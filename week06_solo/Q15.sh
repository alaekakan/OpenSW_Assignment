#!/bin/bash

file_wordcnt() {
    for f in $@
    do
        count=$(wc -w < $f)
        echo "${count}"
    done
}

file_wordcnt $@