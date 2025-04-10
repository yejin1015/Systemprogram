#include <stdio.h>

int main() {
    int num;

    // 0~255 사이의 수 입력
    printf("0~255 사이의 정수를 입력하세요: ");
    scanf("%d", &num);

    // 범위 체크
    if (num < 0 || num > 255) {
        printf("잘못된 입력입니다. 0~255 사이의 수를 입력하세요.\n");
        return 1;
    }

    // 2진수 출력 및 1의 개수 세기
    int count = 0;
    printf("2진수: ");
    for (int i = 7; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
        if (bit == 1) count++;
    }
    printf("\n");

    // 1의 개수 출력
    printf("1의 개수: %d개\n", count);

    // 상위 4비트 출력
    int upper4 = (num >> 4) & 0x0F;  // 상위 4비트만 남김
    printf("상위 4비트: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (upper4 >> i) & 1);
    }
    printf("\n");

    return 0;
}
