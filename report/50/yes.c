#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *output = "y";  // 기본 출력 문자열

    if (argc > 1) {
        output = argv[1];  // 인자가 있으면 그걸로 출력
    }

    while (1) {
        printf("%s\n", output);
    }

    return 0;  // 이 코드는 실제로 종료되지 않음
}
