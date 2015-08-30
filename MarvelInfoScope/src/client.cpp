#include <client.h>

#include <core/net/error.h>
#include <core/net/http/client.h>
#include <core/net/http/content_type.h>
#include <core/net/http/response.h>
#include <QVariantMap>
#include <md5.h>
#include <ctime>
#include <iostream>

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

Client::Characters Client::query_characters(const string& query, bool allCharacters, std::string const& order) {
    QJsonDocument root;

    // Calculating all the parameters needed in order to Marvel's API works properly
    // It is needed a timestamp and a md5 hash with timestamp + privateKey + publicKey
    std::time_t t = std::time(0);  // t is an integer type
    std::string timestamp = std::to_string(t);
    std::string hash = md5(timestamp + config_->privateKey + config_->publicKey);

    int offset = 0;
    // Build a URI and get the contents
    // The fist parameter forms the path part of the URI.
    // The second parameter forms the CGI parameters.
    if (allCharacters) {
        // All characters
        if (order == "random") {
            // Generating a random integer between 0 and 100 [output = min + (rand() % (int)(max - min + 1))]
            offset = 0 + (rand() % (int)(100 - 0 + 1));
            get( { "characters" }, { { "ts", timestamp }, { "apikey", config_->marvelApiKey }, { "hash", hash }, { "offset", std::to_string(offset) }, { "limit", "20" } }, root);
            // e.g. http://gateway.marvel.com/v1/public/characters?ts=mytimestamp&apikey=mymarvelapikey&hash=myhash&offset=myoffset&limit=20
        } else {
            get( { "characters" }, { { "ts", timestamp }, { "apikey", config_->marvelApiKey }, { "hash", hash }, { "orderBy", order }, { "limit", "20" } }, root);
            // e.g. http://gateway.marvel.com/v1/public/characters?ts=mytimestamp&apikey=mymarvelapikey&hash=myhash&orderBy=myorder&limit=20
        }
    } else {
        get( { "characters" }, { { "nameStartsWith", query }, { "ts", timestamp }, { "apikey", config_->marvelApiKey }, { "hash", hash }, { "limit", "20" } }, root);
        // e.g. http://gateway.marvel.com/v1/public/characters?nameStartsWith=Hulk&ts=mytimestamp&apikey=mymarvelapikey&hash=myhash&limit=20
    }

    Characters result;

    QVariantMap variant = root.toVariant().toMap();
    QVariantMap data = variant["data"].toMap();

    // Iterate through the characters data
    for (const QVariant &i : data["results"].toList()) {
        // Item result (Character from JSON response)
        QVariantMap item = i.toMap();

        // Map of images from item. There will be only one
        QVariantMap image = item["thumbnail"].toMap();

        // Complete URL for a thumbnail
        std::string completeURLThumbnail = image["path"].toString().toStdString() + "." + image["extension"].toString().toStdString();

        // Important URLs
        std::string detailUrl = "";
        std::string wikiUrl = "";
        std::string comicUrl = "";
        for (const QVariant &urlVariant : item["urls"].toList()) {

            QVariantMap url = urlVariant.toMap();
            std::string type = url["type"].toString().toStdString();

            // Detail URL
            if (type == "detail") {
                detailUrl = url["url"].toString().toStdString();
            }

            // Wiki URL
            if (type == "wiki") {
                wikiUrl = url["url"].toString().toStdString();
            }

            // Comiclink URL
            if (type == "comiclink") {
                comicUrl = url["url"].toString().toStdString();
            }
        }

        // Add a result to the character list
        result.character.emplace_back(
                    Character {
                            item["id"].toString().toStdString(),
                            item["name"].toString().toStdString(),
                            item["description"].toString().toStdString(),
                            completeURLThumbnail,
                            detailUrl,
                            wikiUrl,
                            comicUrl
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

