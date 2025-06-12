#include <stdio.h>
#include <unistd.h>   // getcwd() 함수 포함
#include <limits.h>   // PATH_MAX 상수 포함

int main() {
    char path[PATH_MAX];  // 현재 디렉토리 경로를 저장할 버퍼

    // getcwd 함수: 현재 작업 디렉토리의 경로를 얻는다
    if (getcwd(path, sizeof(path)) != NULL) {
        printf("%s\n", path);  // 경로 출력
    } else {
        perror("getcwd");      // 오류 발생 시 메시지 출력
        return 1;
    }

    return 0;
}
