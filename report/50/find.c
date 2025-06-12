#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void find_file(const char *dir_path, const char *target_name) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) return;

    struct dirent *entry;
    char path[1024];

    while ((entry = readdir(dir)) != NULL) {
        // 현재 디렉토리와 상위 디렉토리는 스킵
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // 전체 경로 구성
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        // 파일이면 이름 비교
        if (entry->d_type == DT_REG) {
            if (strcmp(entry->d_name, target_name) == 0) {
                printf("발견: %s\n", path);
            }
        }
        // 디렉토리면 재귀 탐색
        else if (entry->d_type == DT_DIR) {
            find_file(path, target_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("사용법: %s 디렉토리 경로 찾을파일이름\n", argv[0]);
        return 1;
    }

    find_file(argv[1], argv[2]);
    return 0;
}
