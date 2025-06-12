#include <stdio.h>
#include <sys/stat.h>   // mkdir() 함수
#include <sys/types.h>  // mode_t 타입 정의
#include <errno.h>      // 오류 코드 확인용
#include <string.h>     // strerror()

int main(int argc, char *argv[]) {
    // 인자 개수 확인 (예: ./mymkdir myfolder)
    if (argc != 2) {
        printf("사용법: %s 디렉토리이름\n", argv[0]);
        return 1;
    }

    const char *dirname = argv[1];

    // 디렉토리 생성: mode 0755 (사용자 쓰기+실행, 다른 사용자 읽기+실행)
    if (mkdir(dirname, 0755) == 0) {
        printf("디렉토리 '%s'가 생성되었습니다.\n", dirname);
    } else {
        // 실패 시 오류 메시지 출력
        printf("디렉토리 생성 실패: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}
