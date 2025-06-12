#include <stdio.h>

// echo는 명령행 인자를 받아서 그대로 출력하는 단순한 구조다.
int main(int argc, char *argv[]) {
    // 인자가 없는 경우 (단순 줄바꿈)
    if (argc == 1) {
        printf("\n");
        return 0;
    }

    // argv[1]부터 출력, 각 인자 사이에 공백 넣기
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc - 1)
            printf(" ");  // 마지막엔 공백 안 넣음
    }

    printf("\n");  // 줄바꿈
    return 0;
}
