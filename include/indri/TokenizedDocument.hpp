/*==========================================================================
 * Copyright (c) 2003-2005 University of Massachusetts.  All Rights Reserved.
 *
 * Use of the Lemur Toolkit for Language Modeling and Information Retrieval
 * is subject to the terms of the software license set forth in the LICENSE
 * file included with this software, and also available at
 * http://www.lemurproject.org/license.html
 *
 *==========================================================================
 */


//
// TokenizedDocument
//
// 15 September 2005 -- mwb
//

#ifndef INDRI_TOKENIZEDDOCUMENT_HPP
#define INDRI_TOKENIZEDDOCUMENT_HPP

#include "indri/greedy_vector"
#include "indri/TagEvent.hpp"
#include "indri/TermExtent.hpp"
#include "indri/MetadataPair.hpp"

namespace indri {
  namespace parse {
    
    struct TokenizedDocument {

      const char* text;
      size_t textLength;

      const char* content;
      size_t contentLength;

      indri::utility::greedy_vector<char*> terms; //term by term
      indri::utility::greedy_vector<TagEvent> tags;//xml file`s node start termid & end term id of terms //https://blog.csdn.net/spche/article/details/5181934
      indri::utility::greedy_vector<TermExtent> positions;//term`s begin end char id in document
      indri::utility::greedy_vector<MetadataPair> metadata;//other info
    };
  }
}

#endif // INDRI_TOKENIZEDDOCUMENT_HPP

