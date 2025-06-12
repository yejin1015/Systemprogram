#include <stdio.h>  

int main(int argc, char *argv[]) {
    // FILE 포인터: 파일과 연결된 스트림을 나타내는 구조체 포인터
    FILE *fp;

    // 한 줄씩 읽기 위한 문자 배열 (버퍼) 선언
    char line[1024];  // 최대 1023자 + 널 문자('\0')

    // argc: 인자의 개수
    // argv: 문자열 배열로, 사용자가 입력한 인자들이 저장됨
    if (argc != 2) {
        printf("사용법: %s 파일이름\n", argv[0]);  // 사용법 안내 출력
        return 1;  // 비정상 종료
    }

    const char *filename = argv[1];  // argv[1]에 입력된 파일 이름을 변수에 저장

    // fopen: 파일을 읽기 모드("r")로 연다
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("파일 열기 실패"); 
        return 1;
    }

    // fgets: 파일에서 한 줄씩 읽음
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line); 
    }

    // 파일 스트림을 닫고 자원 해제
    fclose(fp);

    return 0; 
}


