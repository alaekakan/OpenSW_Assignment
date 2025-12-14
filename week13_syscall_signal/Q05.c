#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

#define SIG_BLOCK   0  
#define SIG_UNBLOCK 1
#define SIG_SETMASK 2  

struct two_double {
    double a;
    double b;
};

struct two_double data;

// 1초마다 호출되어 현재 상태를 출력
void sigalrm_handler(int _signo) {
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main(void) {
    struct sigaction sa_sigalrm;
    struct two_double zeros = {0.0, 0.0};
    struct two_double ones = {1.0, 1.0}; 

    // 핸들러 설정
    sa_sigalrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;

    if (sigaction(SIGALRM, &sa_sigalrm, NULL) == -1) {
        perror("sigaction error : ");
        exit(0);
    }

    // 블로킹 위함
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM); // SIGALRM을 차단 목록에 추가

    alarm(1); // 첫 알람 시작

    while(1) {
        sigprocmask(SIG_BLOCK, &mask, NULL);
        
        data = zeros; 
        
        sigprocmask(SIG_UNBLOCK, &mask, NULL);


        sigprocmask(SIG_BLOCK, &mask, NULL);
        
        data = ones; 
        
        sigprocmask(SIG_UNBLOCK, &mask, NULL);
    }

    return 0;
}