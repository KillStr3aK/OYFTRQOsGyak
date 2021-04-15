#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Hasznalat: ./beadando PID\n");
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]);

    unsigned int elkuldottJel = 0;
    while(1)
    {
        int jel = ((elkuldottJel % 5) == 0) ? SIGUSR1 : SIGUSR2;
        printf("\"%s\" jel kuldese a(z) %d. processznek\n", jel == SIGUSR1 ? "SIGUSR1" : "SIGUSR2", (int)pid);
        kill(pid, jel);
        ++elkuldottJel;
        sleep(1);
    }

    return 0;
}
