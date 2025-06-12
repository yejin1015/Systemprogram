#include <stdio.h>      // printf
#include <stdlib.h>     // atoi
#include <unistd.h>     // sleep()

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s [초]\n", argv[0]);
        return 1;
    }

    int seconds = atoi(argv[1]);  // 문자열 → 정수 변환

    if (seconds < 0) {
        printf("0 이상 숫자를 입력하세요.\n");
        return 1;
    }

    printf("%d초 동안 대기 중...\n", seconds);
    sleep(seconds);  // 지정한 초만큼 대기
    printf("대기 종료\n");

    return 0;
}
