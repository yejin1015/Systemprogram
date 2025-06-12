#include <stdio.h>
#include <string.h>

// 하드코딩된 명령어-설명 목록
typedef struct {
    const char *cmd;
    const char *desc;
} WhatIsEntry;

WhatIsEntry database[] = {
    {"ls", "list directory contents"},
    {"cd", "change the shell working directory"},
    {"mkdir", "make directories"},
    {"rm", "remove files or directories"},
    {"grep", "print lines matching a pattern"},
    {"cat", "concatenate and print files"},
    {"echo", "display a line of text"},
    {"pwd", "print working directory"},
    // 필요하면 더 추가 가능
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s 명령어\n", argv[0]);
        return 1;
    }

    const char *input = argv[1];
    int found = 0;

    // 배열 순회하며 검색
    for (int i = 0; i < sizeof(database)/sizeof(database[0]); i++) {
        if (strcmp(input, database[i].cmd) == 0) {
            printf("%s: %s\n", database[i].cmd, database[i].desc);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%s: 설명을 찾을 수 없습니다.\n", input);
    }

    return 0;
}
