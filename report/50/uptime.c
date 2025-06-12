#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("/proc/uptime", "r");
    if (!file) {
        perror("/proc/uptime 열기 실패");
        return 1;
    }

    double uptime_seconds;
    if (fscanf(file, "%lf", &uptime_seconds) != 1) {
        printf("uptime 값을 읽을 수 없습니다.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    // 시간 계산
    int total = (int)uptime_seconds;
    int days = total / (60 * 60 * 24);
    int hours = (total / (60 * 60)) % 24;
    int minutes = (total / 60) % 60;

    // 출력
    printf("up ");
    if (days > 0)
        printf("%d day%s, ", days, days > 1 ? "s" : "");
    printf("%d:%02d\n", hours, minutes);

    return 0;
}
