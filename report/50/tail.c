#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024       // 한 줄 최대 길이
#define MAX_LINES 1000      // 최대 줄 수 제한 (메모리 보호용)
#define DEFAULT_TAIL 10     // tail 출력 기본 줄 수

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s [파일이름]\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 줄들을 저장할 포인터 배열
    char *lines[MAX_LINES];
    int line_count = 0;
    char buffer[MAX_LINE];

    // 파일에서 한 줄씩 읽어서 메모리에 저장
    while (fgets(buffer, sizeof(buffer), fp)) {
        // 줄 메모리 할당 및 복사
        lines[line_count] = strdup(buffer);
        if (lines[line_count] == NULL) {
            fprintf(stderr, "메모리 할당 실패\n");
            return 1;
        }

        line_count++;
        if (line_count >= MAX_LINES) {
            fprintf(stderr, "줄 수가 너무 많습니다 (최대 %d줄)\n", MAX_LINES);
            break;
        }
    }

    fclose(fp); // 파일 닫기

    // 출력 시작 인덱스 결정 (전체 줄 수 - 기본 줄 수)
    int start = line_count - DEFAULT_TAIL;
    if (start < 0) start = 0;

    // 마지막 10줄 출력
    for (int i = start; i < line_count; i++) {
        printf("%s", lines[i]);
        free(lines[i]); // 메모리 해제
    }

    return 0;
}
