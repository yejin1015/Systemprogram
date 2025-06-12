#include <stdio.h>      // 표준 입출력 함수 사용을 위한 헤더 파일
#include <dirent.h>     // 디렉토리 관련 함수(opendir, readdir 등) 사용을 위한 헤더 파일

int main() {
    // "." 은 현재 디렉토리를 의미한다.
    // 현재 디렉토리를 열고 DIR 포인터로 반환받는다.
    DIR *dir = opendir(".");

    // 디렉토리에서 항목(파일, 디렉토리 등)을 하나씩 읽기 위한 구조체 포인터 선언
    struct dirent *entry;

    // 디렉토리 열기에 실패한 경우 (예: 권한 없음, 디렉토리 존재하지 않음 등)
    if (dir == NULL) {
        printf("디렉토리를 열 수 없습니다.\n");  // 오류 메시지 출력
        return 1;  // 비정상 종료 코드 반환
    }

    // 디렉토리 안의 모든 항목을 하나씩 읽음 (NULL이 반환되면 끝)
    while ((entry = readdir(dir)) != NULL) {
        // entry->d_name은 현재 항목의 이름 (파일명 또는 디렉토리명)을 나타냄
        printf("%s\n", entry->d_name);  // 항목 이름 출력
    }

    // 디렉토리 스트림을 닫아 자원 해제
    closedir(dir);

    return 0;  // 정상 종료
}
