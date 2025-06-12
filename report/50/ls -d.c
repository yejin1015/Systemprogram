#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // 인자가 없으면 현재 디렉토리 출력
    if (argc == 1) {
        printf(".\n");
        return 0;
    }

    // 인자가 여러개일 수 있음
    for (int i = 1; i < argc; i++) {
        struct stat st;
        if (stat(argv[i], &st) != 0) {
            perror("stat 실패");
            continue;
        }

        // 디렉토리든 파일이든 그냥 이름만 출력
        printf("%s\n", argv[i]);
    }

    return 0;
}
