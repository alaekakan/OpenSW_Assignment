#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {

    pid_t p_num = getpid();

    for (;;) {
        printf("%lu\n", p_num);
    }

    return 0;
}