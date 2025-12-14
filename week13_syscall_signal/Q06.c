#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(void) {
    
    // 순서 1: SIGINT signal blocking 설정
    sigset_t block_set;
    
    // 시그널 집합 초기화 및 SIGINT 추가
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);

    // SIGINT를 블로킹 설정
    // 지금부터 Ctrl+C를 눌러도 프로그램이 종료되지 않고 신호가 '대기' 상태로 남음
    if (sigprocmask(SIG_BLOCK, &block_set, NULL) < 0) {
        perror("sigprocmask error");
        exit(1);
    }
    printf("SIGINT is now blocked.\n");

    // 2: 5초간 sleep. (사용자의 입력을 기다림)
    printf("sleep 5seconds!\n");
    sleep(5);
    printf("\nWake up!\n");

    // 3: sleep 이후, SIGINT pending 여부 확인
    sigset_t pending_set;

    // pending 시그널 목록을 가져옴
    if (sigpending(&pending_set) < 0) {
        perror("sigpending error");
        exit(1);
    }

    // 목록 안에 SIGINT가 있는지 검사
    if (sigismember(&pending_set, SIGINT)) {
        printf("[Result] \"SIGINT is pending\"\n");
    } 
    else {
        printf("[Result] \"SIGINT is not pending\"\n");
    }

    return 0;
}