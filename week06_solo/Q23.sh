#! /bin/bash

factorial() {
    result=1
    for i in $(seq 1 $1)
    do
        result=$((${result} * i))  #계산할때는 괄호 하나 더 추가
    done
    echo "Fac $1 is ${result}"
}

factorial $1