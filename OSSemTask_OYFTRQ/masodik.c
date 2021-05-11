#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

void SignalHandler(int sig);
int valtozo = 0;

int main(void)
{
    if (signal(SIGUSR1, SignalHandler) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a(z) \"SIGUSR1\" jelre!\n");
        return 1;
    }

    if (signal(SIGUSR2, SignalHandler) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a(z) \"SIGUSR2\" jelre!\n");
        return 1;
    }

    printf("Várakozás a beérkező jelekre..\n");
    while(1) { sleep(1); }
    return 0;
}

void SignalHandler(int sig)
{
    switch(sig)
    {
    case SIGUSR1: ++valtozo;
        break;
    case SIGUSR2: printf("A(z) \"valtozo\" jelenlegi erteke: %d\n", valtozo);
        break;
    }
}
