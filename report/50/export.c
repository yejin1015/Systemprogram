#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s KEY=VALUE\n", argv[0]);
        return 1;
    }

    // 인자를 '=' 기준으로 나누기
    char *arg = argv[1];
    char *eq_pos = strchr(arg, '=');
    if (eq_pos == NULL) {
        printf("잘못된 형식입니다. KEY=VALUE 형태로 입력하세요.\n");
        return 1;
    }

    // 키와 값 분리
    *eq_pos = '\0';
    char *key = arg;
    char *value = eq_pos + 1;

    // 환경 변수 설정 (overwrite=1)
    if (setenv(key, value, 1) != 0) {
        perror("환경 변수 설정 실패");
        return 1;
    }

    printf("환경 변수 설정 완료: %s=%s\n", key, value);
    return 0;
}
