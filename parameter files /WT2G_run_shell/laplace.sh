#!/bin/bash

cd ~/indri-5.8/runquery

if [ -e IndriRunQuery ]
then
    echo "IndriRunQuery [OK] "
    ./IndriRunQuery ~/workspace/WT2G_query_parameter_file/laplace.xml -trecFormat=true > ~/workspace/WT2G_result/output_laplace.txt
    cd ~/workspace/WT2G_result/
    perl trec_eval.pl [-q] qrels.401-450.txt output_laplace.txt > laplace_evaluation.txt
else
    echo "IndriRunQuery [Error] "
fi
