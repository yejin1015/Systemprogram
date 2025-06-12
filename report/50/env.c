#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    (void)argc;  // argc 사용 안 해서 경고 방지
    (void)argv;

    // envp는 환경변수 배열, 마지막은 NULL 포인터
    for (int i = 0; envp[i] != NULL; i++) {
        printf("%s\n", envp[i]);  // 한 줄씩 출력
    }

    return 0;
}
