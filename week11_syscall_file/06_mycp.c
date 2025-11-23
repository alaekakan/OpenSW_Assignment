// 조건 1 : 사용법은 ./06_mycp [source] [dest1] [dest2] ...
// 조건 2 : source는 미리 존재해야함 존재하지않으면 에러처리
// 조건 3 : source는 read only로 open
// 조건 4 : source에서 32byte씩 읽고 dest에 stdout에 동시에 write
//          read의 결과가 만약 End일경우 read loop를 끝냄
// 조건 5 : dest 파일들을 write only로 open 해야함
//          이때 존재하지않는겨웅 새로 생성되도록 open해야함
//          해당 파일의 접근권한은 rw-r--r--임!!

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUF_SIZE 32

int main(int argc, char *argv[]) {
 
    // argv[1] 이 실제로 존재하지않는거 에러처리도 해줘야함
    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {  // 없다면... 쌰갈!!
        perror("Where is File...!");
        exit(EXIT_FAILURE);
    }

    // argv[2]부터 존재하는지 확인하고 없으면 만들어줘야함
    // dest 파일들을 일단 write only로 열어 줘야함
    int dest_fd[argc - 2];
    for (int i = 2; i < argc; i++) {
        dest_fd[i - 2] = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        close(dest_fd);
    }


    char buffer[BUF_SIZE];
    ssize_t read_result;

    while ((read_result = read(source_fd, buffer, BUF_SIZE)) > 0) {
        // stdout
        write(STDOUT_FILENO, buffer, read_result);

        // 각 dest 파일에 write
        for (int i = 0; i < argc - 2; i++) {
            write(dest_fd[i], buffer, read_result);
        }
    }

    if (read_result == -1) {
        perror("read error");
    }

    close(source_fd);
    for (int i = 0; i < argc - 2; i++) {
        close(dest_fd[i]);
    }
    return 0;
}
