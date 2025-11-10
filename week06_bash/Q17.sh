#!/bin/bash
file_wordcnt() {
  
  echo "--- 현재 디렉토리의 .txt 파일 단어 수 ---"
  
  for f in *.txt
  do

    if [ ! -e "$f" ]; then
      echo "오류: .txt 파일을 찾을 수 없습니다."
      break 
    fi
  
    count=$(wc -w < "$f")
    
    echo "$f 파일의 단어는 ${count}개 입니다."
  done
  
}

file_wordcnt