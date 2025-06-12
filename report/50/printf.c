#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s FORMAT [ARGUMENTS...]\n", argv[0]);
        return 1;
    }

    // argv[1]은 포맷 문자열
    // argv + 2부터는 포맷에 들어갈 인자들

    // 단순하게 포맷 문자열과 인자들을 printf에 전달
    // 가변 인자 함수 호출 대신 아래처럼 구현 가능 (단순 발표용)

    if (argc == 2) {
        // 인자 없으면 포맷만 출력
        printf(argv[1]);
    } else {
        // 인자가 있으면 하나만 적용 (발표용 단순 구현)
        printf(argv[1], argv[2]);
    }

    return 0;
}
