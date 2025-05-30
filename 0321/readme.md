
# 컴파일러 설정
CC = gcc

# 컴파일 대상
TARGET = student
SRC = student.c

# 기본 규칙: make 입력 시 실행됨
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

# 실행
run: $(TARGET)
	./$(TARGET)

# 정리
clean:
	rm -f $(TARGET)
