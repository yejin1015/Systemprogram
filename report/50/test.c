#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        // test filename (파일 존재 여부만 간단 검사)
        struct stat st;
        if (stat(argv[1], &st) == 0) {
            printf("(파일 존재)\n");
            return 0;
        } else {
            printf("(파일 없음)\n");
            return 1;
        }
    } else if (argc == 3) {
        // test string1 = string2 (문자열 비교)
        if (strcmp(argv[1], "=") == 0) {
            if (strcmp(argv[0], argv[2]) == 0) {
                return 0;
            } else {
                return 1;
            }
        }
    } else if (argc == 4) {
        // test -f filename
        if (strcmp(argv[1], "-f") == 0) {
            struct stat st;
            if (stat(argv[2], &st) == 0 && S_ISREG(st.st_mode)) {
                return 0;
            } else {
                return 1;
            }
        }
    }

    printf("지원하지 않는 형식입니다.\n");
    return 2;
}
