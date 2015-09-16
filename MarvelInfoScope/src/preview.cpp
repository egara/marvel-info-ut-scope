#include <preview.h>

#include <unity/scopes/ColumnLayout.h>
#include <unity/scopes/PreviewWidget.h>
#include <unity/scopes/PreviewReply.h>
#include <unity/scopes/Result.h>
#include <unity/scopes/VariantBuilder.h>
#include <QVariantMap>

#include <iostream>

namespace sc = unity::scopes;

using namespace std;

Preview::Preview(const sc::Result &result, const sc::ActionMetadata &metadata) :
    sc::PreviewQueryBase(result, metadata) {
}

void Preview::cancelled() {
}

void Preview::run(sc::PreviewReplyProxy const& reply) {
    // Result
    sc::Result result = PreviewQueryBase::result();

    // Result Type
    std::string resultType = result["resultType"].get_string();

    // Support three different column layouts
    sc::ColumnLayout layout1col(1), layout2col(2), layout3col(3);

    // We define 3 different layouts, that will be used depending on the
    // device. The shell (view) will decide which layout fits best.
    // If, for instance, we are executing in a tablet probably the view will use
    // 2 or more columns.
    // Column layout definitions are optional.
    // However, we recommend that scopes define layouts for the best visual appearance.

    // Single column layout
    if (resultType == "comics") {
        layout1col.add_column( { "image_widget", "header_widget", "summary_widget", "gallery_widget", "actions_widget" } );
    } else if (resultType == "characters") {
        layout1col.add_column( { "image_widget", "header_widget", "summary_widget", "actions_widget" } );
    }

    // Two column layout
    if (resultType == "comics") {
        layout2col.add_column( { "image_widget" } );
        layout2col.add_column( { "header_widget", "summary_widget", "gallery_widget", "actions_widget" } );
    } else if (resultType == "characters") {
        layout2col.add_column( { "image_widget" } );
        layout2col.add_column( { "header_widget", "summary_widget", "actions_widget" } );
    }

    // Three column layout
    if (resultType == "comics") {
        layout3col.add_column( { "image_widget" });
        layout3col.add_column( { "header_widget", "summary_widget", "gallery_widget" } );
        layout3col.add_column( { "actions_widget" } );
    } else if (resultType == "characters") {
        layout3col.add_column( { "image_widget" });
        layout3col.add_column( { "header_widget", "summary_widget" } );
        layout3col.add_column( { "actions_widget" } );
    }

    // Register the layouts we just created
    reply->register_layout( { layout1col, layout2col, layout3col } );

    // Define the image section
    sc::PreviewWidget image("image_widget", "image");
    // It has a single "source" property, mapped to the result's "art" property
    image.add_attribute_mapping("source", "art");

    // Define the header section
    sc::PreviewWidget header("header_widget", "header");
    // It has a "title" and a "subtitle" property
    header.add_attribute_mapping("title", "title");
    header.add_attribute_mapping("subtitle", "marvelAttribution");

    // Define the summary section
    sc::PreviewWidget summary("summary_widget", "text");
    // It has a "text" property, mapped to the result's "description" property
    summary.add_attribute_mapping("text", "description");

    // Define the actions section
    sc::PreviewWidget actions("actions_widget", "actions");

    // Actions are built using tuples with an id, a label and a URI
    sc::VariantBuilder builder;

    // Detail action
    if (result["uri"].get_string() != "") {
        builder.add_tuple({
            {"id", sc::Variant("open")},
            {"label", sc::Variant("Details")},
            {"uri", sc::Variant(result["uri"].get_string())}
        });
    }

    if (resultType == "characters") {
        // Character preview
        // Buttons only for character preview
        // Wiki action
        if (result["wiki"].get_string() != "") {
            builder.add_tuple({
                {"id", sc::Variant("open")},
                {"label", sc::Variant("Wiki")},
                {"uri", sc::Variant(result["wiki"].get_string())}
            });

        }

        // Comic link action
        if (result["comiclink"].get_string() != "") {
            builder.add_tuple({
                {"id", sc::Variant("open")},
                {"label", sc::Variant("Comics")},
                {"uri", sc::Variant(result["comiclink"].get_string())}
            });

        }
    }

    actions.add_attribute_value("actions", builder.end());

    // Define gallery section
    sc::PreviewWidget gallery("gallery_widget", "gallery");
    sc::VariantArray arr;

    if (resultType == "comics") {
        // Comic preview
        arr.push_back(sc::Variant("http://i.annihil.us/u/prod/marvel/i/mg/6/70/55cca22294d68.jpg"));
        arr.push_back(sc::Variant("http://i.annihil.us/u/prod/marvel/i/mg/e/c0/4bc36bbd11d9b.jpg"));
        gallery.add_attribute_value("sources", sc::Variant(arr));
        //gallery.add_attribute_value("fallback", Variant("file:///tmp/fallback.png"));

    }

    // Push each of the sections
    if (resultType == "comics") {
        reply->push( { image, header, summary, gallery, actions } );
    } else if (resultType == "characters") {
        reply->push( { image, header, summary, actions } );
    }


}

