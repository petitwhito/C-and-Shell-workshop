#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static unsigned int signals = 0;
static unsigned int generation = 0;

void handler(int signum)
{
    pid_t cpid;
    signals++;
    switch (signum)
    {
    case SIGINT:
        exit(0);
        break;
    case SIGUSR1:
        printf("Received %d signals.\n", signals);
        fflush(NULL);
        break;
    case SIGUSR2:
        printf("Current generation: %d\n", generation);
        fflush(NULL);
        break;
    case SIGTERM:
        signals = 0;
        generation++;
        cpid = fork();
        if (cpid == -1)
            exit(1);

        if (cpid != 0)
        {
            exit(0);
        }
        break;
    default:
        break;
    }
}

int main(void)
{
    pid_t cpid = fork();

    if (cpid == -1)
        exit(1);

    if (cpid != 0)
    {
        exit(0);
    }

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = handler;
    if (sigemptyset(&sa.sa_mask) < 0)
    {
        return 1;
    }
    if (sigaction(SIGINT, &sa, NULL) < 0)
    {
        return 1;
    }
    if (sigaction(SIGUSR1, &sa, NULL) < 0)
    {
        return 1;
    }
    if (sigaction(SIGUSR2, &sa, NULL) < 0)
    {
        return 1;
    }
    if (sigaction(SIGTERM, &sa, NULL) < 0)
    {
        return 1;
    }
    while (1)
    {
        continue;
    }

    return 0;
}
