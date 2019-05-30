
/*

This is a basic example of using Indri API for data struct greedy_vector

@whuang022nccu

*/

#include <iostream>
#include "indri/greedy_vector"
#include <bits/stdc++.h> 
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace  std;

void test_push_data(){
    indri::utility::greedy_vector<char *> terms ;//testing target
    std::vector<std::string> strVec;//stl string vectors
    strVec.push_back("Hello");
    strVec.push_back("World");
    //using strcpy & malloc to push data into greey_vector
    for(unsigned int i=0;i<strVec.size();i++){
        char *tmp=(char*)malloc(sizeof(string)*strVec.at(i).size()+1);
        strcpy(tmp,strVec.at(i).c_str()); 
        terms.push_back(tmp);
        free(tmp);
    }
    //print data of greedy_vector
    for (unsigned int i = 0; i <terms.size(); i++) {
        std::cout << terms[i] << "\\";
    }
}

int main(int argc, char * argv[]){
    test_push_data();// This function shows how to push strings into greedy vector
    return 0;
}
