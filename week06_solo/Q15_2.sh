#!/bin/bash
file_wordcnt_2() {
    for f in $@     # $@는 변수 하나씩
    do
        count=$(wc -w < ${f})
        echo "${f}의 단어 갯수는 ${count}입니다"
    done
}

file_wordcnt_2 $@