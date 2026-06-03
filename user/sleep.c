#include <kernel/types.h>
#include <user/user.h>

const char* input;

int main(int argc, char *argv[])
{
    if(argc < 1)
    {
        fprintf(2,"Please provide an integer amount of time to sleep.\n");
        exit(1);
    }
    input = argv[1];
    int sleepAmount = atoi(input);
    fprintf(1,"Going to sleep...\n");
    sleep(sleepAmount);
    fprintf(1,"Awake! Slept for %d ticks.\n", sleepAmount);
    exit(0);
}