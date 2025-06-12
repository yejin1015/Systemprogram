#include <stdio.h>
#include <sys/stat.h>   // stat 구조체
#include <time.h>       // 시간 출력용
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat st;

    // 인자 확인
    if (argc != 2) {
        printf("사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    // stat 함수: 파일 상태 가져오기
    if (stat(argv[1], &st) == -1) {
        perror("stat 실패");
        return 1;
    }

    printf("파일 이름: %s\n", argv[1]);
    printf("파일 크기: %ld 바이트\n", st.st_size);
    printf("권한: %o\n", st.st_mode & 0777);  // 하위 3자리만 출력
    printf("링크 수: %ld\n", st.st_nlink);
    printf("UID: %d\n", st.st_uid);
    printf("GID: %d\n", st.st_gid);
    printf("수정 시각: %s", ctime(&st.st_mtime));  // 줄바꿈 포함

    return 0;
}
