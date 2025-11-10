#! /bin/bash

factorial() {
    result=1
    for i in $(seq 1 $1)
    do
        result=$((result * i))
    done
    echo "Fac $1 is $result"
}

read NUM
factorial $NUM