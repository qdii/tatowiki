/**
 * Tatoeba wiki  Wiki made with cppcmsskel
 * Copyright (C) 2012 Allan SIMON <allan.simon@supinfo.com> 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * @category Tatoeba wiki
 * @package  Form
 * @author   Allan SIMON <allan.simon@supinfo.com> 
 * @license  Affero General Public License
 * @link     https://github.com/sysko/tatowiki@
 */


#ifndef TATOWIKI_BASE_ARTICLES_FORM_H
#define TATOWIKI_BASE_ARTICLES_FORM_H

#include <cppcms/form.h>

#include "results/Articles.h"



namespace forms{
namespace articles {

/**
 * @struct BaseArticleForm Base form for all form
 *                         related to articles
 * 
 * @since 3 November 2012
 */
struct BaseArticleForm : public cppcms::form {


    /**
     * @brief Hidden field to store the slug of the article
     *        (i.e it's URL representation)
     *
     * @since  30 October 2012
     */
    cppcms::widgets::hidden slug;

    cppcms::widgets::text title;
    cppcms::widgets::textarea content;
    
    /**
     * @brief Text field to explain what kind of change we made
     *
     * @since 24 March 2013
     */
    cppcms::widgets::text summary;
    /**
     * @brief button to save the article and view it
     *
     * @since  30 October 2012
     */
    cppcms::widgets::submit saveAndView;

    /**
     * @brief button to save the article and continue to edit it
     *
     * @since  30 October 2012
     */
    cppcms::widgets::submit saveAndContinue;
    
    /**
     * @brief Centralize the common instruction between the
     *        constructors of this form, without adding them
     *
     * @since around 30 October 2012
     */
    void init() {
        //%%%NEXT_WIDGET_ADD_MARKER%%%
        slug.non_empty();

        title.message(
            cppcms::locale::translate("Title")
        );
        title.non_empty();

        //important for the javascript code to know
        //on which textarea to put the markdown syntax
        content.id("editor");
        content.message(
            cppcms::locale::translate("Content")
        );
        content.non_empty();
        
        //
        summary.message(
            cppcms::locale::translate("Summary")
        );

        //
        saveAndView.value(
            cppcms::locale::translate("Save")
        );
        saveAndView.name("save_and_view");

        saveAndContinue.value(
            cppcms::locale::translate("save and continue")
        );
        saveAndContinue.name("save_and_continue");

    };

    /**
     * @brief Centralize the common instruction between the
     *        constructors of this form, and add them
     *
     * @since around 13 December 2012
     */

    void init_and_add() {
        init();
        add(slug);
        add(title);
        add(content);
        add(summary);
        add(saveAndView);
        add(saveAndContinue);
    }


};

} // end of namespace articles
}// end of namespace forms
#endif
