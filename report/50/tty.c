#include <stdio.h>
#include <unistd.h>

int main() {
    char *tty = ttyname(STDIN_FILENO);  // 표준 입력에 연결된 터미널 장치 이름

    if (tty == NULL) {
        perror("터미널 장치 확인 실패");
        return 1;
    }

    printf("%s\n", tty);  // 터미널 장치 파일명 출력
    return 0;
}
