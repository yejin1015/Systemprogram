#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>  // gettimeofday()
#include <sys/wait.h>  // waitpid()
#include <unistd.h>    // fork(), execvp()

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s 명령어 [인자...]\n", argv[0]);
        return 1;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);  // 시작 시간 측정

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork 실패");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스: 명령어 실행
        execvp(argv[1], &argv[1]);
        perror("execvp 실패");
        exit(1);
    } else {
        // 부모 프로세스: 자식 종료 대기
        int status;
        waitpid(pid, &status, 0);

        gettimeofday(&end, NULL);  // 종료 시간 측정

        long seconds = end.tv_sec - start.tv_sec;
        long useconds = end.tv_usec - start.tv_usec;
        double total_time = seconds + useconds / 1e6;

        printf("실행 시간: %.6f초\n", total_time);
    }

    return 0;
}
