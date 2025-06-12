#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    int c;
    int lines = 0, words = 0, chars = 0;
    int in_word = 0;  // 단어 내부인지 여부

    while ((c = fgetc(fp)) != EOF) {
        chars++;

        if (c == '\n')
            lines++;

        if (isspace(c)) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    // 마지막 단어 처리
    if (in_word)
        words++;

    fclose(fp);

    printf(" %d %d %d %s\n", lines, words, chars, argv[1]);
    return 0;
}
