#!/bin/bash

file_wordcnt() {
	for f in "$@"
	do
	 count=$(wc -w < "$f")
	 echo "$f 파일의 단어는 ${count}개 입니다."
	done
}

file_wordcnt "$@"
