#include <stdio.h>
#include <unistd.h>     // getuid, getgid
#include <sys/types.h>  // gid_t, uid_t
#include <pwd.h>        // getpwuid
#include <grp.h>        // getgrgid, getgroups
#include <stdlib.h>

int main() {
    uid_t uid = getuid();    // 현재 사용자 ID
    gid_t gid = getgid();    // 현재 그룹 ID

    struct passwd *pw = getpwuid(uid);
    struct group *gr = getgrgid(gid);

    if (pw == NULL || gr == NULL) {
        perror("사용자 또는 그룹 정보를 가져올 수 없습니다.");
        return 1;
    }

    printf("uid=%d(%s) gid=%d(%s) groups=", uid, pw->pw_name, gid, gr->gr_name);

    // 현재 프로세스가 속한 그룹 목록 얻기
    int ngroups = 0;
    getgrouplist(pw->pw_name, gid, NULL, &ngroups);  // 그룹 개수 알아내기
    gid_t *groups = malloc(ngroups * sizeof(gid_t));
    if (groups == NULL) {
        perror("메모리 할당 실패");
        return 1;
    }

    if (getgrouplist(pw->pw_name, gid, groups, &ngroups) == -1) {
        perror("그룹 리스트 가져오기 실패");
        free(groups);
        return 1;
    }

    for (int i = 0; i < ngroups; i++) {
        struct group *g = getgrgid(groups[i]);
        if (g != NULL) {
            printf("%d(%s)", groups[i], g->gr_name);
            if (i < ngroups -1) printf(",");
        }
    }
    free(groups);
    printf("\n");

    return 0;
}
