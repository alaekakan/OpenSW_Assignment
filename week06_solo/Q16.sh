#!/bin/bash

file_wordcnt() {
    for f in $@
    do
        if [ ! -e $f ]; then
            echo "존재 X"
        else
            count=$(wc -w < $f)
            echo "${count}개 존재"
        fi
    done
}

file_wordcnt $@