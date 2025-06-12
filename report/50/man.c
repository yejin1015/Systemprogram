#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s 명령어이름\n", argv[0]);
        return 1;
    }

    char command[256];
    snprintf(command, sizeof(command), "man %s", argv[1]);

    // man 명령어 실행
    int ret = system(command);
    if (ret == -1) {
        perror("man 실행 실패");
        return 1;
    }

    return 0;
}
