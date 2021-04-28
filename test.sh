#!/usr/bin/env /bin/bash

# ARG="4 67 3 87 23"; ./push_swap $ARG
echo ""
echo "(3):   < 2-3"
ARG="2 1 0";
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo ""
echo "(5):  < 12"
ARG="1 5 2 4 3";
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo ""
echo "(5):  < 12"
ARG="11 5 3 2 1";
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo ""
echo "(5):   < 12"
ARG=`./random 5 20`;
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo ""
echo "(100):  700-1500"
ARG=`./random 100 10000`;
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo ""
echo "(500):  5500-11500"
ARG=`./random 500 100000`;
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG