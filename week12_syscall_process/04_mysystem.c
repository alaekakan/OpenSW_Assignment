#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char* command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {     // child process
        // execl은 현재 프로세스이 메모리를 
        // 새로운 프로그램으로 교체해주는 역할

        // 즉 받은 명령을 /bin/sh로 변신해서 수행함

        // -c는 쉘에게 뒤로 명령어 줄테니 해석해서 실행하라는 뜻

        // 이를통해 command에 "ls -l | wc -l"이 들어가서 실행함
        execl("/bin/sh", "sh", "-c", command, (char *) NULL);
        perror("execl failed");
        exit(127);      // 명령어 없는경우에는 127로 리턴
    }
    else {              // parent process
        if (waitpid(pid, &status, 0) == -1) {
            return -1;
        }

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
    }
}

int main(void) {

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Bye Bye~!\n");

    return 0;
}