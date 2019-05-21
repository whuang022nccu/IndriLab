#!/bin/bash

cd ~/indri-5.8/runquery

if [ -e IndriRunQuery ]
then
    echo "IndriRunQuery [OK] "
    ./IndriRunQuery ~/workspace/WT2G_query_parameter_file/jelinek_mercer.xml -trecFormat=true > ~/workspace/WT2G_result/output_jelinek_mercer.txt
    cd ~/workspace/WT2G_result/
    perl trec_eval.pl [-q] qrels.401-450.txt output_jelinek_mercer.txt > jelinek_mercer_evaluation.txt
else
    echo "IndriRunQuery [Error] "
fi
