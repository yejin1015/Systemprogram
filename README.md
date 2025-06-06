
# 💻 시스템 프로그래밍 핵심 요약

> 운영체제와 하드웨어 자원을 **직접 제어**하며, 효율적인 프로그램을 만드는 저수준 프로그래밍

---

🔹 **프로세스 관리**  
`fork()`, `exec()`, `wait()` → 프로세스 생성 & 종료 대기  
`getpid()`, `getppid()` → ID 확인  
`setuid()`, `setgid()` → 권한 변경

🔹 **파일 입출력**  
`open()`, `read()`, `write()`, `lseek()`, `close()` → 파일 직접 제어  
`stat()`, `chmod()`, `chown()` → 파일 정보 및 권한 관리  
`flock()`, `fcntl()` → 파일 잠금 (동시성 제어)

🔹 **빌드 자동화 & 편집기**  
`Makefile` → 컴파일 자동화  
`vi` → CLI 기반 텍스트 편집기

🔹 **우분투 필수 명령어**  
`gcc`, `make`, `ps`, `top`, `ls`, `chmod`, `cat`, `man`, `kill`

---

🧠 *이 모든 요소는 커널과 사용자 공간을 잇는 다리입니다.*
