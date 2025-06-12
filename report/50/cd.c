#include <stdio.h>
#include <unistd.h>    // chdir(), getcwd()
#include <limits.h>    // PATH_MAX
#include <errno.h>     // 오류 메시지용
#include <string.h>

int main(int argc, char *argv[]) {
    char cwd[PATH_MAX]; // 현재 경로 저장용

    // 인자 체크
    if (argc != 2) {
        printf("사용법: %s 디렉토리명\n", argv[0]);
        return 1;
    }

    // chdir 함수로 디렉토리 이동 시도
    if (chdir(argv[1]) != 0) {
        perror("디렉토리 변경 실패");
        return 1;
    }

    // 현재 디렉토리 출력
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("현재 디렉토리: %s\n", cwd);
    } else {
        perror("현재 디렉토리 확인 실패");
        return 1;
    }

    return 0;
}
