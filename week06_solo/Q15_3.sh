#!/bin/bash
file_wordcnt_3() {
    for f in $@
    do
        if [ ! -e $f ];
        then
            echo "i can't find..."
        else
            count=$(wc -w < ${f})
            echo "file's word num is ${count}"
        fi
    done
}
file_wordcnt_3 $@