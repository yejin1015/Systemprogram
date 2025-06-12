#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *src, *dest;
    char ch;

    // 인자가 3개가 아니라면 사용법 안내
    if (argc != 3) {
        printf("사용법: %s 원본파일 복사파일\n", argv[0]);
        return 1;
    }

    // 원본 파일 열기 (읽기 모드)
    src = fopen(argv[1], "r");
    if (src == NULL) {
        printf("원본 파일을 열 수 없습니다.\n");
        return 1;
    }

    // 복사 파일 열기 (쓰기 모드)
    dest = fopen(argv[2], "w");
    if (dest == NULL) {
        printf("복사 파일을 생성할 수 없습니다.\n");
        fclose(src);  // 열린 파일은 닫고 종료
        return 1;
    }

    // 원본 파일에서 한 글자씩 읽어 복사 파일에 쓰기
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    // 파일 닫기
    fclose(src);
    fclose(dest);

    printf("파일 복사가 완료되었습니다.\n");
    return 0;
}
