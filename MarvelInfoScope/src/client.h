 #ifndef CLIENT_H_
#define CLIENT_H_

#include <atomic>
#include <deque>
#include <map>
#include <memory>
#include <string>
#include <core/net/http/request.h>
#include <core/net/uri.h>

#include <QJsonDocument>

/**
 * Provide a nice way to access the HTTP API.
 *
 * We don't want our scope's code to be mixed together with HTTP and JSON handling.
 */
class Client {
public:

    /**
     * Client configuration
     */
    struct Config {
        typedef std::shared_ptr<Config> Ptr;

        // The root of all API request URLs
        std::string apiroot { "http://gateway.marvel.com/v1/public" };

        // Developer Key
        std::string marvelApiKey {"86f0789992b18c005b29de44ff92005c"};

        // Private Key
        std::string privateKey {"f5f8a46693439befcd381a23bb73f983f80c44fb"};

        // Public Key
        std::string publicKey {"86f0789992b18c005b29de44ff92005c"};

        // The custom HTTP user agent string for this library
        std::string user_agent { "example-network-scope 0.1; (foo)" };
    };

    /**
     * Marvel's character information.
     */
    struct Character {
        std::string id;
        std::string name;
        std::string description;
        std::string thumbnail;
        std::string detailUrl;
        std::string wikiUrl;
        std::string comicUrl;
    };

    /**
     * Marvel's comic information.
     */
    struct Comic {
        std::string id;
        std::string format;
        std::string pageCount;
        std::string isbn;
        std::string title;
        std::string description;
        std::string thumbnail;
        std::string detailUrl;
        std::string images;
        std::string characters;
    };

    /**
     * A list of characters
     */
    typedef std::deque<Character> CharacterList;

    /**
     * A list of comics
     */
    typedef std::deque<Comic> ComicList;

    /**
     * Information about Marvel's characters
     */
    struct Characters {
        CharacterList character;
    };

    /**
     * Information about Marvel's comics
     */
    struct Comics {
        ComicList comic;
    };

    Client(Config::Ptr config);

    virtual ~Client() = default;

    /**
     * Get all Marvel's characters
     */
    virtual Characters query_characters(const std::string &query, bool allCharacters, const std::string &order);

    /**
     * Get all Marvel's comics
     */
    virtual Comics query_comics(const std::string &query, bool allComics, const std::string &order);

    /**
     * Cancel any pending queries (this method can be called from a different thread)
     */
    virtual void cancel();

    virtual Config::Ptr config();

protected:
    void get(const core::net::Uri::Path &path,
             const core::net::Uri::QueryParameters &parameters,
             QJsonDocument &root);
    /**
     * Progress callback that allows the query to cancel pending HTTP requests.
     */
    core::net::http::Request::Progress::Next progress_report(
            const core::net::http::Request::Progress& progress);

    /**
     * Hang onto the configuration information
     */
    Config::Ptr config_;

    /**
     * Thread-safe cancelled flag
     */
    std::atomic<bool> cancelled_;
};

#endif // CLIENT_H_

