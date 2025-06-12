#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 인자 개수 확인
    if (argc != 2) {
        printf("사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    // 파일 삭제 시도
    if (remove(filename) == 0) {
        printf("파일 '%s'가 삭제되었습니다.\n", filename);
    } else {
        perror("파일 삭제 실패");  // 오류 출력
        return 1;
    }

    return 0;
}
