#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    // 인자 확인
    if (argc != 2) {
        printf("사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    // "a" 모드는 파일이 없으면 생성, 있으면 그대로 둠
    fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    fclose(fp);
    printf("'%s' 파일이 생성되었거나 이미 존재합니다.\n", filename);
    return 0;
}
