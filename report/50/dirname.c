#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s [경로]\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    char *last_slash = strrchr(path, '/');  // 마지막 '/' 찾기

    if (last_slash == NULL) {
        // '/' 없으면 현재 디렉토리(.)
        printf(".\n");
    } else if (last_slash == path) {
        // '/'가 맨 앞에 있으면 루트 디렉토리
        printf("/\n");
    } else {
        // '/' 앞까지 문자열 출력
        size_t len = last_slash - path;
        char dir[1024];
        strncpy(dir, path, len);
        dir[len] = '\0';
        printf("%s\n", dir);
    }

    return 0;
}
