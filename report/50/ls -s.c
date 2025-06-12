#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *dir_name = ".";  // 기본은 현재 디렉토리

    if (argc > 1) {
        dir_name = argv[1];
    }

    DIR *dir = opendir(dir_name);
    if (!dir) {
        perror("디렉토리 열기 실패");
        return 1;
    }

    struct dirent *entry;

    // 디렉토리 항목 반복
    while ((entry = readdir(dir)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

        struct stat st;
        if (stat(path, &st) != 0) {
            perror("stat 실패");
            continue;
        }

        // st_blocks는 512바이트 블록 수
        printf("%ld %s\n", st.st_blocks, entry->d_name);
    }

    closedir(dir);
    return 0;
}
