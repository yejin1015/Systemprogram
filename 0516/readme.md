# 🧠 프로세스 & 사용자/그룹 ID 요약

## 😀 프로세스란?

- 실행 중인 프로그램  
- 쉘(Shell)이 명령어를 해석해 프로세스를 생성함  

---

## 🔍 프로세스 ID 확인

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID : %d\n", getpid());
    printf("PPID: %d\n", getppid());
}

