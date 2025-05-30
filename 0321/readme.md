## 🧾 1. 소스 파일 작성 (vi 사용)

터미널에서 아래 명령어로 C 소스 파일을 생성합니다.

```bash
vi student.c
```

### ▶ vi 사용법

1. `vi` 실행 후 `i` 키를 눌러 **입력 모드**로 진입  
2. 아래 코드를 입력하거나 붙여넣습니다:

```c
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
```

3. 입력을 마쳤으면 `Esc` 키를 누른 뒤 아래 명령어를 입력하여 저장하고 종료합니다:

```bash
:wq
```
