#include <query.h>
#include <localization.h>

#include <unity/scopes/Annotation.h>
#include <unity/scopes/CategorisedResult.h>
#include <unity/scopes/CategoryRenderer.h>
#include <unity/scopes/QueryBase.h>
#include <unity/scopes/SearchReply.h>

#include <iomanip>
#include <iostream>
#include <sstream>

namespace sc = unity::scopes;

using namespace std;


/**
 * Define the larger "current weather" layout.
 *
 * The icons are larger.
 */
/*
const static string CURRENT_TEMPLATE =
        R"(
{
        "schema-version": 1,
        "template": {
        "category-layout": "grid",
        "card-size": "medium"
        },
        "components": {
        "title": "title",
        "art" : {
        "field": "art"
        },
        "subtitle": "subtitle"
        }
        }
        )";
*/
/**
 * Define the layout for the characters results.
 *
 * The icon size is small, and ask for the card layout
 * itself to be horizontal. I.e. the text will be placed
 * next to the image.
 */
/*
const static string WEATHER_TEMPLATE =
        R"(
{
        "schema-version": 1,
        "template": {
        "category-layout": "grid",
        "card-layout": "horizontal",
        "card-size": "small"
        },
        "components": {
        "title": "title",
        "art" : {
        "field": "art"
        },
        "subtitle": "subtitle"
        }
        }
        )";
*/
/**
 * Define the layout for the characters results.
 *
 * Ask for the card layout
 * itself to be horizontal. I.e. the text will be placed
 * next to the image.
 */
const static string CHARACTER_TEMPLATE =
        R"(
{
        "schema-version": 1,
        "template": {
        "category-layout": "grid",
        "card-layout": "horizontal"
        },
        "components": {
        "title": "title",
        "mascot" : "mascot",
        "subtitle": "subtitle"
        }
        }
        )";

Query::Query(const sc::CannedQuery &query, const sc::SearchMetadata &metadata,
             Client::Config::Ptr config) :
    sc::SearchQueryBase(query, metadata), client_(config) {
}

void Query::cancelled() {
    client_.cancel();
}


void Query::run(sc::SearchReplyProxy const& reply) {
    try {
        // Start by getting information about the query
        const sc::CannedQuery &query(sc::SearchQueryBase::query());

        // Get the query string
        string query_string = query.query_string();

        Client::Characters characters;
        if (query_string.empty()) {
            // If there is no search string, get all characters
            characters = client_.query_characters("", true);
        } else {
            // otherwise, get the character for the search string
            characters = client_.query_characters(query_string, false);
        }

        // Register a category for characters
        auto characters_cat = reply->register_category("characters", _("Marvel Characters"), "",
                                                     sc::CategoryRenderer(CHARACTER_TEMPLATE));

        // For each of the characters
        for (const auto &character : characters.character) {
            // Create a result
            sc::CategorisedResult res(characters_cat);

            // We must have a URI
            res.set_uri(character.url);


            // Set the rest of the attributes
            res.set_title(character.name);
            res["mascot"] = character.thumbnail;
            res["subtitle"] = character.description;
            //res["description"] = "A description of the result";

            // Push the result
            if (!reply->push(res)) {
                // If we fail to push, it means the query has been cancelled.
                // So don't continue;
                return;
            }
        }

    } catch (domain_error &e) {
        // Handle exceptions being thrown by the client API
        cerr << e.what() << endl;
        reply->error(current_exception());
    }
}

