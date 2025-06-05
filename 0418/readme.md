# 🛠️ Makefile & Vi 편집기 요약

---

## ✅ Make란?
`make`는 C 같은 컴파일 언어에서 변경된 소스 파일만 자동으로 다시 컴파일하여 빌드 효율을 높여주는 **빌드 자동화 도구**입니다.

---

## 📄 Makefile이란?
- 소스 파일들의 **의존 관계**와 **컴파일 방법**을 정의한 스크립트 파일
- 기본 파일명은 `Makefile` 또는 `makefile`

---

## 🧱 Makefile 기본 구조

- **target**: 생성하려는 파일 (예: 실행 파일)
- **dependencies**: target을 만들기 위해 필요한 파일들
- **command**: 파일을 만들기 위한 실제 명령 (탭 문자로 시작해야 함)

---

## 🧪 예시: Makefile

아래는 `main`이라는 실행 파일을 빌드하기 위한 Makefile 예시입니다.

main: main.o copy.o
gcc -o main main.o copy.o

main.o: main.c copy.h
gcc -c main.c

copy.o: copy.c
gcc -c copy.c

