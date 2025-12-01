#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    pid_t child_pid;
    child_pid = fork();

    if (child_pid == 0) {   // child process!
        sleep(1);           // 1초 수면
        printf("\nchild pid : %lu\n child ppid : %lu\n",getpid(), getppid());
        return 7;
    }
    else {                  // parent process!
        printf("\nparent pid : %lu\n parent ppid : %lu\n", getpid(), getppid());
    }

    return 0;
}