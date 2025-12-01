#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    pid_t child_pid;
    child_pid = fork();

    if (child_pid == 0) {   // child process!
        printf("child pid : %lu\n child ppid : %lu\n",getpid(), getppid());
        return 7;
    }
    else {                  // parent process!
        int wstatus;
        waitpid(child_pid, &wstatus, 0);

        if (WIFEXITED(wstatus)) {
            printf("child's status code : %d\n", WEXITSTATUS(wstatus));            
        }

        printf("parent pid : %lu\n parent ppid : %lu\n", getpid(), getppid());
    }

    return 0;
}