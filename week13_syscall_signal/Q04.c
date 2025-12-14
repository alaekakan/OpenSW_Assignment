#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

void sigint_handler(int signum) {
    printf("SIGINT handler\n");
    pid_t pid = fork();

    if (pid == 0) {     // child

        char *argv[] = { "ls", NULL };
        execve("/usr/bin/ls", argv, NULL);
    }
    else {              // parent
        wait(NULL);
    }
}

void sigquit_handler(int signum) {
    printf("SIGQUIT handler\n");
    pid_t pid = fork();

    if (pid == 0) {     // child

        char *argv[] = { "date", NULL };
        execve("/usr/bin/date", argv, NULL);
    }
    else {              // parent
        wait(NULL);
    }
}

void sigalrm_handler(int signum) {
    printf("SIGALRM handler\n");
    pid_t pid = fork();

    if (pid == 0) {     // child

        char *argv[] = { "whoami", NULL };
        execve("/usr/bin/whoami", argv, NULL);
    }
    else {              // parent
        wait(NULL);
        alarm(3);
    }
}

int main(void) {

    // signal 반환 처리
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGALRM, sigalrm_handler);

    alarm(3);

    while(1) {
        sleep(1);
    }

    return 0;
}