#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    char *dir_name = ".";  // 기본 디렉토리는 현재 디렉토리

    if (argc > 1) {
        dir_name = argv[1];  // 인자가 있으면 해당 디렉토리로
    }

    DIR *dir = opendir(dir_name);
    if (!dir) {
        perror("디렉토리 열기 실패");
        return 1;
    }

    struct dirent *entry;

    // 디렉토리 항목 모두 출력 (숨김 파일 포함)
    while ((entry = readdir(dir)) != NULL) {
        printf("%s  ", entry->d_name);
    }
    printf("\n");

    closedir(dir);
    return 0;
}
