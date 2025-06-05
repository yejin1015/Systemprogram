# 🤖 생성형 AI로 구현한 숫자 처리 프로그램

## 📍 과제 개요
사용자로부터 0부터 255 사이의 정수를 입력받아, 다음과 같은 처리를 수행하는 프로그램을 작성했습니다.  
본 프로젝트는 생성형 AI를 활용하여 개발되었으며, 다양한 언어로 구현 가능합니다.

## 🔧 프로그램 기능
- 입력받은 정수를 8자리 2진수로 변환
- 해당 2진수에 포함된 1의 개수 계산
- 상위 4비트 추출 및 출력

## 🧠 사용된 생성형 AI
- **ChatGPT (OpenAI GPT-4)**

## 💬 주요 프롬프트 예시
0~255 범위의 숫자를 입력받아 8비트 이진수로 출력하고,
1의 개수를 세며, 앞쪽 4비트를 추출하는 프로그램을 작성해줘.
여러 언어(Python, C, Java 등) 버전도 함께 제공해줘.
GitHub README 형식으로 요약 정리해줘.


## 🖥️ 예시 언어: Rust

```rust
use std::io;

fn main() {
    println!("0~255 사이의 정수 입력:");
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let num: u8 = match input.trim().parse() {
        Ok(n) if n <= 255 => n,
        _ => {
            println!("잘못된 입력입니다.");
            return;
        }
    };

    let binary = format!("{:08b}", num);
    let ones_count = binary.chars().filter(|&c| c == '1').count();
    let upper_4 = &binary[..4];

    println!("입력된 숫자: {}", num);
    println!("2진수(8비트): {}", binary);
    println!("1의 개수: {}", ones_count);
    println!("상위 4비트: {}", upper_4);
}
🧪 실행 예시

0~255 사이의 정수 입력:
213
입력된 숫자: 213
2진수(8비트): 11010101
1의 개수: 5
상위 4비트: 1101

📁 참고 사항
이 프로젝트는 Rust 외에도 Python, Java, C, JavaScript, Go, C++ 등 다양한 언어로 구현 가능하며, 각 언어별 코드 파일은 별도로 정리되어 있습니다.

생성형 AI를 활용한 코드 생성 및 문서화가 핵심 학습 목표입니다.
