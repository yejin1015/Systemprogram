 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
 /* 부모 프로세스가 자식프로세스를생성하고서로다른메시지를프린트*/
    int main() 
{
    int pid;
    pid = fork();
    if (pid ==0) {   // 자식 프로세스
        printf("[Child] : Hello, world pid=%d\n", getpid());
        }
     else {   // 부모 프로세스
    printf("[Parent] : Hello, world pid=%d\n", getpid());
    }
 }