#include <stdio.h>
#include <unistd.h>

int main(void) {
    int now_pid_num = getpid();
    int parent_pid_num = getppid();
    printf("pid : %lu\n",now_pid_num);
    printf("ppid : %lu\n",parent_pid_num);
}