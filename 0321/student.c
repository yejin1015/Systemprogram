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
