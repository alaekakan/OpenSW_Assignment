// 조건 1 : 키보드로 입력한 내용을 read하여 터미널에 write 한다
//          해당 과정이 loop를 돌며 게속되어야한다

// 조건 2 : 만약 Ctrl + D를 입력한다면, 프로그램이 중단된다

// 조건 3 : 읽기 버퍼는 최대 128byte 입니다.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUF_SIZE 128

int main(int argc, char *argv[]) {
    
    if (argc != 1) {
        printf("입력이 안들어옴");
        return 0;
    }

    char* read_str = (char*)malloc(sizeof(char) * BUF_SIZE);
    ssize_t read_result;

    while(1) {
        read_result = read(0, read_str, BUF_SIZE);
        if (read_result == 0) {
            printf("DONE!!\n");
            return 0;
        }
        write(1, read_str,read_result);
    }

    free(read_str);

    return 0;
}