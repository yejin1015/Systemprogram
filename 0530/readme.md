# grep 명령어 발표 요약

## 1. grep 개념  
- `grep` = Global Regular Expression Print  
- 텍스트 파일에서 특정 문자열을 빠르게 찾는 명령어  
- 예) `grep "Park" students.txt` → 파일 내 "Park" 포함된 줄 출력

## 2. grep 문법  
```bash
grep [옵션] '찾을_문자열' 파일명

3. 실생활 중심 예제
이름이 Kim인 사람 찾기
grep "Kim" students.txt

학번이 2020으로 시작하는 줄 찾기
grep "^2020" students.txt

대소문자 구분 없이 이름 Park 찾기
grep -i "park" students.txt

4. 에러 로그 예제
에러만 추출
grep "ERROR" system.log

대소문자 무시 warning 찾기
grep -i "warning" system.log

error 와 warning 동시에 보기 (정규식)
grep -E "ERROR|WARNING" system.log
