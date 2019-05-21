#!/bin/bash

cd ~/indri-5.8/runquery

if [ -e IndriRunQuery ]
then
    echo "IndriRunQuery [OK] "
    ./IndriRunQuery ~/workspace/WT2G_query_parameter_file/jelinek_mercer_laplace.xml -trecFormat=true > ~/workspace/WT2G_result/output_jelinek_mercer_laplace.txt
    cd ~/workspace/WT2G_result/
    perl trec_eval.pl [-q] qrels.401-450.txt output_jelinek_mercer_laplace.txt > jelinek_mercer_laplace_evaluation.txt
else
    echo "IndriRunQuery [Error] "
fi
