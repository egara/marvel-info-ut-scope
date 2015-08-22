#include <client.h>

#include <core/net/error.h>
#include <core/net/http/client.h>
#include <core/net/http/content_type.h>
#include <core/net/http/response.h>
#include <QVariantMap>

namespace http = core::net::http;
namespace net = core::net;

using namespace std;

Client::Client(Config::Ptr config) :
    config_(config), cancelled_(false) {
}


void Client::get(const net::Uri::Path &path,
                 const net::Uri::QueryParameters &parameters, QJsonDocument &root) {
    // Create a new HTTP client
    auto client = http::make_client();

    // Start building the request configuration
    http::Request::Configuration configuration;

    // Build the URI from its components
    net::Uri uri = net::make_uri(config_->apiroot, path, parameters);
    configuration.uri = client->uri_to_string(uri);

    // Give out a user agent string
    configuration.header.add("User-Agent", config_->user_agent);

    // Build a HTTP request object from our configuration
    auto request = client->head(configuration);

    try {
        // Synchronously make the HTTP request
        // We bind the cancellable callback to #progress_report
        auto response = request->execute(
                    bind(&Client::progress_report, this, placeholders::_1));

        // Check that we got a sensible HTTP status code
        if (response.status != http::Status::ok) {
            throw domain_error(response.body);
        }
        // Parse the JSON from the response
        root = QJsonDocument::fromJson(response.body.c_str());

        // Open weather map API error code can either be a string or int
        QVariant cod = root.toVariant().toMap()["cod"];
        if ((cod.canConvert<QString>() && cod.toString() != "200")
                || (cod.canConvert<unsigned int>() && cod.toUInt() != 200)) {
            throw domain_error(root.toVariant().toMap()["message"].toString().toStdString());
        }
    } catch (net::Error &) {
    }
}

Client::Characters Client::query_characters(const string& query, bool allCharacters) {
    QJsonDocument root;

    // Build a URI and get the contents
    // The fist parameter forms the path part of the URI.
    // The second parameter forms the CGI parameters.
    if (allCharacters) {
        get( { "characters" }, { { "apikey", "86f0789992b18c005b29de44ff92005c" } }, root);
        // e.g. http://gateway.marvel.com/v1/public/characters?apikey=86f0789992b18c005b29de44ff92005c
    } else {
        get( { "characters" }, { { "name", query }, { "apikey", "86f0789992b18c005b29de44ff92005c" } }, root);
        // e.g. http://gateway.marvel.com/v1/public/characters?name=Hulk&apikey=86f0789992b18c005b29de44ff92005c
    }

    Characters result;

    QVariantMap variant = root.toVariant().toMap();

    // Iterate through the weather data
    for (const QVariant &i : variant["results"].toList()) {
        // Item result (Character from JSON response)
        QVariantMap item = i.toMap();

        // Map of images from item. There will be only one
        QVariantMap images = item["thumbnail"].toMap();

        // Complete URL for a thumbnail
        //std::string completeURLThumbnail = images["path"].toString().toStdString() + "." + images["extension"].toString().toStdString();

        //std::string completeURLThumbnail = { "http://i.annihil.us/u/prod/marvel/i/mg/c/e0/535fecbbb9784.jpg" };
        // Final URL
        std::string finalURL = "http://www.estoes.es";

        // Add a result to the character list
        result.character.emplace_back(
                    Character {
                            item["id"].toString().toStdString(),
                            item["name"].toString().toStdString(),
                            item["desciption"].toString().toStdString(),
                            images["path"].toString().toStdString() + "." + images["extension"].toString().toStdString(),
                            //images["path"].toString().toStdString() + "." + images["extension"].toString().toStdString()
                            finalURL
                    });


    }

    return result;
}

http::Request::Progress::Next Client::progress_report(
        const http::Request::Progress&) {

    return cancelled_ ?
                http::Request::Progress::Next::abort_operation :
                http::Request::Progress::Next::continue_operation;
}

void Client::cancel() {
    cancelled_ = true;
}

Client::Config::Ptr Client::config() {
    return config_;
}

