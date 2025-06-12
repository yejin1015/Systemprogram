#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int cmp_name(const void *a, const void *b) {
    const char **sa = (const char **)a;
    const char **sb = (const char **)b;
    return strcmp(*sa, *sb);
}

int main(int argc, char *argv[]) {
    char *dir_name = ".";
    if (argc > 1) dir_name = argv[1];

    DIR *dir = opendir(dir_name);
    if (!dir) {
        perror("디렉토리 열기 실패");
        return 1;
    }

    char *names[1024];
    int count = 0;
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // 숨김파일 제외

        names[count] = strdup(entry->d_name);
        if (!names[count]) {
            perror("메모리 할당 실패");
            closedir(dir);
            return 1;
        }
        count++;
    }
    closedir(dir);

    // 이름 오름차순 정렬
    qsort(names, count, sizeof(char *), cmp_name);

    // 역순 출력
    for (int i = count - 1; i >= 0; i--) {
        printf("%s\n", names[i]);
        free(names[i]);
    }

    return 0;
}
