#!/bin/bash

cd ~/indri-5.8/runquery

if [ -e IndriRunQuery ]
then
    echo "IndriRunQuery [OK] "
    ./IndriRunQuery ~/workspace/WT2G_query_parameter_file/laplace_no_stemming.xml -trecFormat=true > ~/workspace/WT2G_result/output_laplace_no_stemming.txt
    cd ~/workspace/WT2G_result/
    perl trec_eval.pl [-q] qrels.401-450.txt output_laplace_no_stemming.txt > laplace_evaluation_no_stemming.txt
else
    echo "IndriRunQuery [Error] "
fi
