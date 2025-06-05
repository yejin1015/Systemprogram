📁 파일 시스템 관련 시스템 호출 요약
📦 i-node 구조 요약
직접 블록 포인터: 12개

간접 / 이중 간접 / 삼중 간접 포인터: 각 1개

👉 최대 파일 크기는 블록 크기에 따라 결정됨

🧾 파일 메타정보 조회: stat()

#include <sys/stat.h>
int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);
용도: 파일 상태(i-node 정보 포함) 확인

반환: 성공 0, 실패 -1

🔐 파일 권한 변경: chmod(), fchmod()

#include <sys/stat.h>
int chmod(const char *path, mode_t mode);
int fchmod(int fd, mode_t mode);
권한은 8진수(예: 0644)로 지정

성공 0, 실패 -1

⏱ 파일 시간 변경: utime()

#include <utime.h>
int utime(const char *filename, const struct utimbuf *times);
접근/수정 시간을 변경

times == NULL이면 현재 시간으로 설정

👤 소유자 변경: chown(), fchown(), lchown()
c
복사
편집
#include <unistd.h>
int chown(const char *path, uid_t owner, gid_t group);
int fchown(int fd, uid_t owner, gid_t group);
int lchown(const char *path, uid_t owner, gid_t group);
슈퍼유저만 변경 가능

성공 0, 실패 -1


