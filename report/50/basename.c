#include <stdio.h>
#include <string.h>

// basename 명령어 구현: 경로에서 파일명만 추출
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s [경로/파일이름]\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    char *base = strrchr(path, '/');  // 마지막 '/' 찾기

    if (base != NULL) {
        printf("%s\n", base + 1);  // '/' 다음 글자부터 출력
    } else {
        printf("%s\n", path);      // '/' 없으면 전체가 파일명
    }

    return 0;
}
