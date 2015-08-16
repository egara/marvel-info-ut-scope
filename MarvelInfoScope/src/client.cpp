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

Client::Characters Client::query_characters(const string& query) {
    QJsonDocument root;

    // Build a URI and get the contents
    // The fist parameter forms the path part of the URI.
    // The second parameter forms the CGI parameters.
   // get( { "data", "2.5", "forecast", "daily" }, { { "q", query }, { "units",
   //                                                                  "metric" }, { "cnt", to_string(cnt) }
   //      }, root);

    //get( { "search", query }, {{ "filter", "guide,teardown" }, {"limit", "100"}}, root);
    get( { "characters" }, { { "name", query }, { "apikey", "86f0789992b18c005b29de44ff92005c" } }, root);
    // e.g. http://api.openweathermap.org/data/2.5/forecast/daily/?q=QUERY&units=metric&cnt=7
    // e.g. http://gateway.marvel.com/v1/public/characters?name=Hulk&apikey=86f0789992b18c005b29de44ff92005c

    Forecast result;

    QVariantMap variant = root.toVariant().toMap();

    // Read out the city we found
    QVariantMap city = variant["city"].toMap();
    result.city.id = city["id"].toUInt();
    result.city.name = city["name"].toString().toStdString();
    result.city.country = city["country"].toString().toStdString();

    // Iterate through the weather data
    for (const QVariant &i : variant["list"].toList()) {
        QVariantMap item = i.toMap();

        // Extract the first weather item
        QVariantList weather_list = item["weather"].toList();
        QVariantMap weather = weather_list.first().toMap();

        // Extract the temperature data
        QVariantMap temp = item["temp"].toMap();

        // Add a result to the weather list
        result.weather.emplace_back(
                    Weather { weather["id"].toUInt(), weather["main"].toString().toStdString(),
                              weather["description"].toString().toStdString(),
                              "http://openweathermap.org/img/w/"
                              + weather["icon"].toString().toStdString() + ".png", Temp {
                                  temp["max"].toDouble(), temp["min"].toDouble(),
                                  0.0 } });
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

