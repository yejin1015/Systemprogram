#include <stdio.h>

int main() {
    int num;

    // 0~255 ������ �� �Է�
    printf("0~255 ������ ������ �Է��ϼ���: ");
    scanf("%d", &num);

    // ���� üũ
    if (num < 0 || num > 255) {
        printf("�߸��� �Է��Դϴ�. 0~255 ������ ���� �Է��ϼ���.\n");
        return 1;
    }

    // 2���� ��� �� 1�� ���� ����
    int count = 0;
    printf("2����: ");
    for (int i = 7; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
        if (bit == 1) count++;
    }
    printf("\n");

    // 1�� ���� ���
    printf("1�� ����: %d��\n", count);

    // ���� 4��Ʈ ���
    int upper4 = (num >> 4) & 0x0F;  // ���� 4��Ʈ�� ����
    printf("���� 4��Ʈ: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (upper4 >> i) & 1);
    }
    printf("\n");

    return 0;
}
