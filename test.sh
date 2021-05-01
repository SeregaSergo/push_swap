#!/usr/bin/env /bin/bash

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
ARG=`./random 5 -10 25`;
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo ""
echo "(100):  700-1500"
ARG=`./random 100 -1000 10000`;
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo ""
echo "(500):  5500-11500"
ARG=`./random 500 -100000 1000000`;
echo $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

# ARG=`./random 500 1000000`;./push_swap $ARG
# ARG=`./random 5 20`;./push_swap $ARG
# ARG="11 5 3 2 1";./push_swap $ARG | ./checker -v $ARG