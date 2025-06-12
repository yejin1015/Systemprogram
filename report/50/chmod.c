#include <stdio.h>      // printf, perror
#include <stdlib.h>     // strtol
#include <sys/stat.h>   // chmod
#include <errno.h>      // errno

int main(int argc, char *argv[]) {
    // 인자 개수 확인
    if (argc != 3) {
        printf("사용법: %s [권한(8진수)] [파일이름]\n", argv[0]);
        return 1;
    }

    // 8진수 권한값을 정수로 변환
    char *endptr;
    long mode = strtol(argv[1], &endptr, 8);  // 8진수 해석
    if (*endptr != '\0') {
        printf("잘못된 권한 형식입니다. 8진수로 입력하세요 (예: 755)\n");
        return 1;
    }

    // chmod 시스템 호출로 파일 권한 변경
    if (chmod(argv[2], (mode_t)mode) == -1) {
        perror("chmod 실패");
        return 1;
    }

    printf("파일 '%s'의 권한을 %o 로 변경했습니다.\n", argv[2], (unsigned int)mode);
    return 0;
}
