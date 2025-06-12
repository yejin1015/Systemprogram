#include <stdio.h>      // 표준 입출력 사용
#include <stdlib.h>     // exit(), EXIT_FAILURE 사용

#define MAX_LINE 1024       // 한 줄에 최대 1024바이트까지 읽기
#define DEFAULT_LINES 10    // 출력할 기본 줄 수 (head의 기본값)

int main(int argc, char *argv[]) {
    // 인자 확인: 파일 이름 하나만 받아야 함
    if (argc != 2) {
        printf("사용법: %s [파일이름]\n", argv[0]);
        return 1;
    }

    // 파일 열기 (읽기 모드)
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE];  // 한 줄씩 저장할 배열
    int count = 0;        // 현재까지 출력한 줄 수

    // 파일에서 한 줄씩 읽기
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);  // 줄 출력 (줄바꿈 포함되어 있음)
        count++;             // 출력한 줄 수 증가

        // DEFAULT_LINES (10줄) 이상이면 종료
        if (count >= DEFAULT_LINES)
            break;
    }

    // 파일 닫기
    fclose(fp);
    return 0;
}
