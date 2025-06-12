#include <stdio.h>

int main() {
    // ANSI 이스케이프 코드로 화면 지우기
    printf("\033[2J"); // 전체 지우기
    printf("\033[H");  // 커서 맨 위로 이동

    return 0;
}
