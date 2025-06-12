#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    char line[256];

    // 파일 이름 입력 받기
    printf("파일 이름을 입력하세요: ");
    scanf("%s", filename);

    // 쓰기 모드로 파일 열기 ("w" = 새로 쓰기, 기존 내용 삭제됨)
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    printf("파일에 입력할 내용을 작성하세요 (종료: Ctrl+D):\n");

    // 표준 입력을 받아 파일에 쓰기 (Ctrl+D로 종료)
    while (fgets(line, sizeof(line), stdin)) {
        fputs(line, fp);
    }

    // 파일 닫기
    fclose(fp);

    printf("'%s' 파일이 저장되었습니다.\n", filename);
    return 0;
}
