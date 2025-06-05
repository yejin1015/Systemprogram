
# 📂 파일 입출력 함수 요약 (C 시스템 콜 기반)

리눅스에서 사용하는 대표적인 파일 입출력 시스템 콜들을 간단히 정리했습니다.

---

## 📄 open() — 파일 열기

```c
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int open(const char *path, int oflag, mode_t mode); // mode는 O_CREAT 시 필요
성공 시: 파일 디스크립터(fd) 반환

실패 시: -1

주요 oflag 옵션
옵션	설명
O_RDONLY	읽기 전용
O_WRONLY	쓰기 전용
O_RDWR	읽기/쓰기 모두 가능
O_CREAT	파일이 없으면 새로 생성
O_TRUNC	기존 내용 삭제 후 시작

🆕 creat() — 새 파일 생성

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int creat(const char *path, mode_t mode);
파일 생성 및 권한 설정

내부적으로는 다음과 같음:

open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
❌ close() — 파일 닫기

#include <unistd.h>

int close(int fd);
파일 디스크립터(fd) 닫기

성공: 0, 실패: -1

📥 read() — 파일 읽기

#include <unistd.h>

ssize_t read(int fd, void *buf, size_t nbytes);
fd로 지정된 파일에서 최대 nbytes만큼 읽어 buf에 저장

반환값:

성공: 읽은 바이트 수

EOF: 0

실패: -1

📤 write() — 파일 쓰기

#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t nbytes);
buf의 데이터를 fd에 nbytes만큼 씀

반환값:

성공: 실제 쓴 바이트 수

실패: -1
