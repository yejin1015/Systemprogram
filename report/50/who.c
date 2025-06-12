#include <stdio.h>
#include <utmp.h>
#include <time.h>

int main() {
    struct utmp *ut;

    setutent();  // utmp 파일 시작 위치로
    while ((ut = getutent()) != NULL) {
        if (ut->ut_type == USER_PROCESS) {  // 사용자 로그인 정보
            char time_buf[32];
            struct tm *tm_info;

            tm_info = localtime(&ut->ut_tv.tv_sec);
            strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M", tm_info);

            printf("%-8s %-8s %s\n", ut->ut_user, ut->ut_line, time_buf);
        }
    }
    endutent();

    return 0;
}
