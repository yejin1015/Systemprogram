#include <stdio.h>

int main(int argc, char *argv[]) {
    // 인자 개수 확인
    if (argc != 3) {
        printf("사용법: %s 원본이름 대상이름\n", argv[0]);
        return 1;
    }

    const char *oldname = argv[1];
    const char *newname = argv[2];

    // rename 함수: 이름 변경 또는 위치 이동
    if (rename(oldname, newname) == 0) {
        printf("'%s' → '%s' 로 이동 또는 이름이 변경되었습니다.\n", oldname, newname);
    } else {
        perror("파일 이동 실패");
        return 1;
    }

    return 0;
}
