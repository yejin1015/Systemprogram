#include <stdio.h>      // 표준 입출력 함수
#include <unistd.h>     // getuid() 함수
#include <pwd.h>        // getpwuid(), struct passwd

int main() {
    uid_t uid = getuid();  // 현재 사용자 ID 얻기
    struct passwd *pw = getpwuid(uid);  // 사용자 ID로 사용자 정보 얻기

    if (pw == NULL) {
        perror("사용자 정보를 가져올 수 없습니다");
        return 1;
    }

    printf("%s\n", pw->pw_name);  // 사용자 이름 출력

    return 0;
}
