#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // 조건 1 : 프로그램 실행시 첫 인자는
    // 실행할 프로그램 경로(/usr/bin/에 있는 아무 프로그램)이고
    // 이후 인자들은 실행할 프로그램에 부여하는 옵션

    // 조건 2 : 03_execve 프로그램의 잘못된 사용에 대해
    //          적절한 에러 처리를 수행해야함

    // 조건 3 : fork(2)를 통해 child process를 생성함
    //          생성된 child process에서 execve(2)를 사용하여
    //          전달받은 프로그램(+ 옵션)을 실행합니다

    // 조건 4 : execve(2) 실패 시, child는 exit code 1로 종료합니다

    // 조건 5 : parent process는 waitpid(2)를 사용하여 child process가
    //          종료될 때까지 기다렸다가, child의 exit code를 출력함

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <program> [OPTION]...\n", argv[0]);
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {     // now is child process
        execve(argv[1], &argv[1], NULL);
        perror("execve");   // print error message
        exit(1);
    }
    else {              // now is parent process
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid error");
            exit(1);
        }

        if (WIFEXITED(status)) {
            printf("Child exited with status : %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}