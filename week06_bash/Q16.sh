#!/bin/bash

file_wordcnt() {
  
  for f in "$@"
  do
    if [ ! -e "$f" ]; 
    then
      echo "오류: '$f' 파일이 존재하지 않습니다."
    
    else
      count=$(wc -w < "$f")
      echo "$f 파일의 단어는 ${count}개 입니다."
    fi
  done
}

file_wordcnt "$@"
echo "file_wordcnt 함수의 종료상태: $?"