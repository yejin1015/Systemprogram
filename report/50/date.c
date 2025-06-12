#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *t;

    // 현재 시간 가져오기
    time(&now);
    t = localtime(&now);

    // 출력: YYYY-MM-DD HH:MM:SS
    printf("현재 시간: %04d-%02d-%02d %02d:%02d:%02d\n",
        t->tm_year + 1900,   // 연도는 1900년부터 시작
        t->tm_mon + 1,       // 월은 0부터 시작
        t->tm_mday,
        t->tm_hour,
        t->tm_min,
        t->tm_sec
    );

    return 0;
}
