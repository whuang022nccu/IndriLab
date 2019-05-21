#!/bin/bash

cd ~/indri-5.8/runquery

if [ -e IndriRunQuery ]
then
    echo "IndriRunQuery [OK] "
    ./IndriRunQuery ~/workspace/WT2G_query_parameter_file/okapi.xml -trecFormat=true > ~/workspace/WT2G_result/output_okapi.txt
    cd ~/workspace/WT2G_result/
    perl trec_eval.pl [-q] qrels.401-450.txt output_okapi.txt > okapi_evaluation.txt
else
    echo "IndriRunQuery [Error] "
fi
