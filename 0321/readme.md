📄 README.md
학번과 이름 입력 프로그램
이 프로그램은 사용자로부터 학번과 이름을 입력받아 출력하는 간단한 C 프로그램입니다.

📁 파일 구성
bash
복사
편집
student.c     # 메인 C 소스 파일
Makefile      # 컴파일 및 실행 자동화 파일
🧾 1. 소스 파일 작성 (vi 사용)
터미널에서 아래 명령어로 C 소스 파일을 생성합니다.

bash
복사
편집
vi student.c
▶ vi 사용법
vi 실행 후 i 키를 눌러 입력 모드로 진입

아래 코드 입력 또는 붙여넣기

c
복사
편집
#include <stdio.h>

int main() {
    int student_id;
    char name[100];

    printf("학번을 입력하세요: ");
    scanf("%d", &student_id);

    printf("이름을 입력하세요: ");
    scanf("%s", name);

    printf("입력된 학번: %d\n", student_id);
    printf("입력된 이름: %s\n", name);

    return 0;
}
Esc 키 → :wq 입력 후 엔터로 저장하고 종료

🛠️ 2. Makefile 작성
bash
복사
편집
vi Makefile
▶ 아래 내용 입력
makefile
복사
편집
CC = gcc
TARGET = student
SRC = student.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
⚙️ 3. 컴파일 및 실행
🔨 컴파일
bash
복사
편집
make
▶️ 실행
bash
복사
편집
make run
🧹 실행 파일 삭제
bash
복사
편집
make clean
📌 주의사항
scanf("%s", name);은 공백 전까지의 문자열만 입력받습니다.

공백 포함된 이름 입력을 원한다면 fgets()를 사용하는 방식으로 수정이 필요합니다.

