#include <stdio.h>
#include <sys/stat.h>    // stat 함수와 구조체 정의
#include <dirent.h>      // 디렉토리 열고 읽는 함수들
#include <string.h>      // 문자열 함수
#include <stdlib.h>      // snprintf

// 디렉토리 내 모든 파일 크기 합산하는 함수
long get_directory_size(const char *path) {
    long total_size = 0;               // 누적 파일 크기 변수
    struct stat st;                   // 파일 정보 저장용 구조체
    struct dirent *entry;             // 디렉토리 항목 포인터
    DIR *dir = opendir(path);         // 디렉토리 열기

    if (!dir) {                      // 디렉토리 열기 실패 시 에러 출력 후 0 반환
        perror("디렉토리 열기 실패");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {   // 디렉토리 항목 하나씩 읽기
        // "." 과 ".." 은 현재, 상위 디렉토리이므로 건너뜀
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // 현재 경로 + "/" + 항목 이름 으로 전체 경로 만듦
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // 파일 정보 얻기
        if (stat(full_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {        // 만약 디렉토리라면
                // 재귀 호출로 하위 디렉토리 크기 합산
                total_size += get_directory_size(full_path);
            } else {
                // 일반 파일이면 크기 더하기
                total_size += st.st_size;
            }
        }
    }

    closedir(dir);  // 디렉토리 닫기
    return total_size;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {          // 인자 개수 확인
        printf("사용법: %s 경로\n", argv[0]);
        return 1;
    }

    struct stat st;
    // 인자로 받은 경로의 파일 정보 가져오기
    if (stat(argv[1], &st) != 0) {
        perror("경로 정보 가져오기 실패");
        return 1;
    }

    long size = 0;
    if (S_ISDIR(st.st_mode)) {       // 디렉토리면
        size = get_directory_size(argv[1]);   // 디렉토리 크기 계산
    } else {
        size = st.st_size;                    // 일반 파일이면 크기 바로 사용
    }

    // 총 크기 출력 (바이트 단위)
    printf("총 사용량: %ld 바이트\n", size);

    return 0;
}
