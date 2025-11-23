#include <stdio.h>
#include <unistd.h>

int main(void) {
    int pid_num = getpid();
    printf("%lu\n",pid_num);
}