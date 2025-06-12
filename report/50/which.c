#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // access()
#include <limits.h>     // PATH_MAX

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s 명령어\n", argv[0]);
        return 1;
    }

    char *cmd = argv[1];
    char *path_env = getenv("PATH");   // PATH 환경변수 읽기

    if (!path_env) {
        fprintf(stderr, "PATH 환경변수가 설정되지 않았습니다.\n");
        return 1;
    }

    // PATH 변수 복사 (strtok에서 문자열 변형 방지)
    char *path_copy = strdup(path_env);
    if (!path_copy) {
        perror("메모리 할당 실패");
        return 1;
    }

    char *dir = strtok(path_copy, ":");  // PATH 경로 분리

    while (dir != NULL) {
        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);

        // 실행 파일인지 검사 (읽기 및 실행 가능 확인)
        if (access(full_path, X_OK) == 0) {
            printf("%s\n", full_path);
            free(path_copy);
            return 0;   // 찾으면 바로 종료
        }

        dir = strtok(NULL, ":");  // 다음 경로로 이동
    }

    free(path_copy);
    // 명령어를 찾지 못했을 때 (출력 없음 또는 메시지)
    fprintf(stderr, "%s: 명령어를 찾을 수 없습니다.\n", cmd);
    return 1;
}
