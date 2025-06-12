#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// 파일이 없거나 타겟보다 새로 만들었는지 확인하는 함수
int needs_build(const char* target, const char* dependency) {
    struct stat t_stat, d_stat;

    if (stat(target, &t_stat) != 0) return 1;  // 타겟 없으면 빌드
    if (stat(dependency, &d_stat) != 0) return 0;  // 의존파일 없으면 스킵

    return d_stat.st_mtime > t_stat.st_mtime;  // 의존파일이 더 최신이면 빌드
}

int main() {
    FILE* file = fopen("Makefile", "r");
    if (!file) {
        perror("Makefile 열기 실패");
        return 1;
    }

    char line[256];
    char target[100], dep[100], cmd[200];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, ":")) {
            sscanf(line, "%s : %s", target, dep);  // 타겟과 의존성 추출
            fgets(cmd, sizeof(cmd), file);         // 다음 줄은 명령어라고 가정

            // 조건 판단 후 명령 실행
            if (needs_build(target, dep)) {
                printf(">> %s", cmd);
                system(cmd);  // 명령어 실행
            } else {
                printf("스킵: %s 최신 상태\n", target);
            }
        }
    }

    fclose(file);
    return 0;
}
