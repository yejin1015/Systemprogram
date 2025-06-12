#include <stdio.h>
#include <sys/utsname.h>  // uname 함수와 utsname 구조체 정의된 헤더

int main() {
    struct utsname buf;  // 시스템 정보를 저장할 구조체 변수 선언

    // uname 함수 호출, 성공 시 0, 실패 시 -1 반환
    if (uname(&buf) == -1) {
        perror("uname 실패");  // 오류 메시지 출력
        return 1;              // 비정상 종료 코드 반환
    }

    // 각 항목별로 시스템 정보 출력
    printf("시스템 이름: %s\n", buf.sysname);    // 운영체제 이름 (예: Linux)
    printf("노드 이름: %s\n", buf.nodename);    // 네트워크 노드 이름(호스트 이름)
    printf("커널 릴리즈: %s\n", buf.release);  // 커널 릴리즈 버전
    printf("커널 버전: %s\n", buf.version);    // 커널 버전 정보
    printf("머신: %s\n", buf.machine);          // 시스템 아키텍처 (예: x86_64)

    return 0;  // 정상 종료
}
