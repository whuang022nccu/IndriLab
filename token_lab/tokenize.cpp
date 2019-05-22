
/*

This is a basic example of using Indri API for parsing.

@whuang022nccu

*/


#include <iostream>
#include "indri/UnparsedDocument.hpp"
#include "indri/TokenizedDocument.hpp"
#include "indri/TokenizerFactory.hpp"
#include "indri/TextTokenizer.hpp"


int main(int argc, char * argv[]){
	//Add the string into Indri doc.
    std::string s("The test of token");
    indri::parse::UnparsedDocument *doc = new indri::parse::UnparsedDocument();
    doc->content = s.c_str();
    doc->contentLength = s.length();
	//Call tokenfactory get token
	indri::parse::Tokenizer* tok = indri::parse::TokenizerFactory::get( "word" );
    indri::parse::TokenizedDocument *tdoc = tok->tokenize(doc);//do parsing
	//Get tokens output
    indri::utility::greedy_vector<char *> terms = tdoc->terms;
    for (unsigned int i = 0; i <terms.size(); i++) {
            std::cout << terms[i] << "\\";
    }
    return 0;
}
