#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define HISTORY_FILE "history.txt"

void show_history() {
    FILE *file = fopen(HISTORY_FILE, "r");
    if (!file) {
        printf("히스토리 파일이 없습니다.\n");
        return;
    }

    char line[MAX_LINE];
    int count = 1;
    while (fgets(line, sizeof(line), file)) {
        printf("%4d  %s", count++, line);
    }

    fclose(file);
}

void add_history(const char *input) {
    FILE *file = fopen(HISTORY_FILE, "a");
    if (!file) {
        perror("history 파일 열기 실패");
        return;
    }
    fprintf(file, "%s\n", input);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        show_history();  // 인자 없으면 출력
    } else {
        // 인자를 history로 저장
        char buffer[MAX_LINE] = "";
        for (int i = 1; i < argc; i++) {
            strcat(buffer, argv[i]);
            if (i < argc - 1) strcat(buffer, " ");
        }
        add_history(buffer);
        printf("기록됨: %s\n", buffer);
    }
    return 0;
}
