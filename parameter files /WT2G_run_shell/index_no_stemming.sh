#!/bin/bash

cd ~/indri-5.8/buildindex

if [ -e IndriBuildIndex ]
then
    echo "IndriBuildIndex [OK] "
    ./IndriBuildIndex ~/workspace/WT2G_index_parameter_file/project_W2T_withoutstemming.xml
else
    echo "IndriBuildIndex [Error] "
fi


