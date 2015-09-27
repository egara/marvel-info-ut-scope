#include <query.h>
#include <localization.h>

#include <unity/scopes/Annotation.h>
#include <unity/scopes/CategorisedResult.h>
#include <unity/scopes/CategoryRenderer.h>
#include <unity/scopes/QueryBase.h>
#include <unity/scopes/SearchReply.h>
#include <unity/scopes/OptionSelectorFilter.h>

#include <iomanip>
#include <iostream>
#include <sstream>

namespace sc = unity::scopes;

using namespace std;

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
        "category-layout": "vertical-journal",
        "card-layout": "horizontal-list",
        "overlay": true
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

/**
 * Define the layout for the comics results.
 *
 * Ask for the card layout
 * itself to be horizontal. I.e. the text will be placed
 * next to the image.
 */
const static string COMIC_TEMPLATE =
        R"(
{
        "schema-version": 1,
        "template": {
        "category-layout": "vertical-journal",
        "card-layout": "horizontal-list",
        "overlay": true
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

        // Filters are defined
        sc::Filters filters;
        auto homepage = settings().at("homepage").get_int();
        std::string homepageText = "Characters";
        if (homepage == 1) {
            homepageText = "Comics";
        }
        sc::OptionSelectorFilter::SPtr optionsFilter = sc::OptionSelectorFilter::create("category", homepageText);
        optionsFilter->set_display_hints(1);
        // Characters filter
        optionsFilter->add_option("characters", _("Characters"));
        // Comics filter
        optionsFilter->add_option("comics", _("Comics"));
        optionsFilter->active_options(query.filter_state());
        filters.push_back(optionsFilter);
        reply->push(filters, query.filter_state());

        std::string filterid;
        if (optionsFilter->has_active_option(query.filter_state())){
            // Get a set of active filters(1 element only)
            auto o = *(optionsFilter->active_options(query.filter_state()).begin());
            filterid = o->id();
        }

        if (filterid == "") {
            //set filter according to settings
            if (homepage == 0) {
                // Characters
                filterid = "characters";

            } else if (homepage == 1) {
                // Comics
                filterid = "comics";

            }
        }

        // Getting order to sort by
        auto order = settings().at("order").get_int();

        std::string orderToken = "";
        switch ( order ) {
        case 0:
          if (filterid == "characters") {
            orderToken = "name";
          } else {
            orderToken = "title";
          }
          break;
        case 1:
            orderToken = "modified";
            break;
        case 2:
            orderToken = "random";
            break;
        default:
            orderToken = "name";
            break;
        }


        if (filterid == "characters") {
            // Characters
            Client::Characters characters;

            if (query_string.empty()) {
                // If there is no search string, get all characters
                characters = client_.query_characters("", true, orderToken);
            } else {
                // otherwise, get the character for the search string
                characters = client_.query_characters(query_string, false, orderToken);
            }

            // Register a category for characters
            auto characters_cat = reply->register_category("characters", _("Marvel Characters"), "",
                                                         sc::CategoryRenderer(CHARACTER_TEMPLATE));

            // For each of the characters
            for (const auto &character : characters.character) {
                // Create a result
                sc::CategorisedResult res(characters_cat);

                // Set URLs
                res.set_uri(character.detailUrl);
                res["wiki"] = character.wikiUrl; // wiki must not be defined within CHARACTER_TEMPLATE
                                                 // but it will be available in preview.cpp
                res["comiclink"] = character.comicUrl;  // comiclink must not be defined within CHARACTER_TEMPLATE
                                                        // but it will be available in preview.cpp

                // Set the rest of the attributes
                res["title"] = character.name;
                res.set_art(character.thumbnail);
                res["subtitle"] = "";
                if (character.description == "") {
                    res["description"] = "No description found.";
                } else {
                    res["description"] = character.description;
                }
                res["marvelAttribution"] = "Data provided by Marvel. © 2014 Marvel";   // Marvel attribution
                res["resultType"] = filterid;

                // Push the result
                if (!reply->push(res)) {
                    // If we fail to push, it means the query has been cancelled.
                    // So don't continue;
                    return;
                }
            }
        } else if (filterid == "comics") {
            // Comics
            Client::Comics comics;

            if (query_string.empty()) {
                // If there is no search string, get all comics
                comics = client_.query_comics("", true, orderToken);
            } else {
                // otherwise, get the character for the search string
                comics = client_.query_comics(query_string, false, orderToken);
            }

            // Register a category for comics
            auto comics_cat = reply->register_category("comics", _("Marvel Comics"), "",
                                                         sc::CategoryRenderer(COMIC_TEMPLATE));

            // For each of the comics
            for (const auto &comic : comics.comic) {
                // Create a result
                sc::CategorisedResult res(comics_cat);

                // Set URLs
                res.set_uri(comic.detailUrl);

                // Set the rest of the attributes
                res["title"] = comic.title;
                res.set_art(comic.thumbnail);
                res["subtitle"] = comic.format;
                res["format"] = comic.format;
                res["pageCount"] = comic.pageCount;
                if (comic.isbn == "") {
                    res["isbn"] = "No ISBN found";
                } else {
                    res["isbn"] = comic.isbn;
                }
                res["isbn"] = comic.isbn;
                if (comic.description == "") {
                    res["description"] = "No description found.";
                } else {
                    res["description"] = comic.description;
                }
                res["marvelAttribution"] = "Data provided by Marvel. © 2014 Marvel";   // Marvel attribution
                res["resultType"] = filterid;
                res["images"] = comic.images;
                res["characters"] = comic.characters;

                // Push the result
                if (!reply->push(res)) {
                    // If we fail to push, it means the query has been cancelled.
                    // So don't continue;
                    return;
                }
            }
        }

    } catch (domain_error &e) {
        // Handle exceptions being thrown by the client API
        cerr << e.what() << endl;
        reply->error(current_exception());
    }
}

