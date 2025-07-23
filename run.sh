#! /bin/bash

make rps

for REP in $(seq 0 1 100)
    do time for PM in $(seq 0.00 0.03 0.90)
        do echo "$PM $REP"; ./rps.out $REP $PM
    done
done
