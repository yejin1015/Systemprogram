#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 1024  // 한 줄 최대 길이

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("사용법: %s 패턴 파일이름\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];
    const char *filename = argv[2];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern)) {  // 패턴이 포함된 줄이면 출력
            printf("%s", line);       // 줄바꿈 포함되어 있음
        }
    }

    fclose(fp);
    return 0;
}
