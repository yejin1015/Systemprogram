#include <stdio.h>
#include <unistd.h>  // gethostname()

int main() {
    char hostname[256];  // 호스트 이름 저장 버퍼

    // 시스템에서 호스트 이름을 가져옴
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("%s\n", hostname);  // 출력
    } else {
        perror("호스트 이름을 가져올 수 없습니다");
        return 1;
    }

    return 0;
}
