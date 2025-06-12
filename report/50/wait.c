#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>  // wait()
#include <unistd.h>    // fork(), sleep()

int main() {
    pid_t pid = fork();  // 자식 생성

    if (pid < 0) {
        perror("fork 실패");
        return 1;
    }
    else if (pid == 0) {
        // 자식 프로세스
        printf("자식 프로세스: PID=%d, 2초간 작업 중...\n", getpid());
        sleep(2);  // 작업 흉내
        printf("자식 프로세스 종료\n");
        exit(42);  // 종료 코드 42
    }
    else {
        // 부모 프로세스
        int status;
        printf("부모 프로세스: 자식 %d의 종료를 기다립니다...\n", pid);
        wait(&status);  // 자식 종료 대기

        if (WIFEXITED(status)) {
            printf("자식이 정상 종료. 종료 코드: %d\n", WEXITSTATUS(status));
        } else {
            printf("자식이 비정상 종료\n");
        }
    }

    return 0;
}
