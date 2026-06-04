#include <kernel/types.h>
#include <user/user.h>

int main()
{
    int pwcr[2];
    if(pipe(pwcr) < 0){
      printf("pipe() failed\n");
      exit(1);
    }
    int prcw[2];
        if(pipe(prcw) < 0){
      printf("pipe() failed\n");
      exit(1);
    }
    int pid = fork();
    if(pid == -1)
    {
        printf("fork() failed\n");
        exit(1);
    }
    else if(pid == 0)
    {
        //Child
        close(pwcr[1]); close(prcw[0]);
        char received_byte;
        read(pwcr[0], &received_byte, 1);
        printf("%d: received ping\n", getpid());
        write(prcw[1], &received_byte, 1);
        exit(0);
    }
    else
    {
        //Parent
        close(pwcr[0]); close(prcw[1]);
        char send_byte = 'x';
        write(pwcr[1], &send_byte, 1);
        read(prcw[0], &send_byte, 1);
        printf("%d: received pong\n", getpid());
    }
    exit(0);
}