#!/bin/sh

for i in `seq 9`
do
    for j in `seq $i`
    do
        printf "%d*%d=%d " $i $j $(expr $i \* $j)
    done
    echo ""
done


exit 0