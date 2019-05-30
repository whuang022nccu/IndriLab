
/*

This is a basic example of using Indri API for data struct greedy_vector  TermExtent for record term position

@whuang022nccu

*/

#include <iostream>
#include "indri/greedy_vector"
#include "indri/TermExtent.hpp"
#include <bits/stdc++.h> 
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace  std;

void test_push_data(){
    indri::utility::greedy_vector<indri::parse::TermExtent> pos_data ;//testing target
    for(unsigned int i=0;i<3;i++){
	indri::parse::TermExtent pos;
	pos.begin=1+i;//just test
	pos.end=2+i;//just test
        pos_data.push_back(pos);
    }
    //print data of greedy_vector
    for (unsigned int i = 0; i <pos_data.size(); i++) {
        std::cout << pos_data[i].begin << ":" << pos_data[i].end << "\\";
    }
}

int main(int argc, char * argv[]){
    test_push_data();// This function shows how to push strings into greedy vector
    return 0;
}
