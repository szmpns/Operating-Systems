#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void signal_handler(int signum) {
    const char *signal_name = strsignal(signum);
    if (signal_name == NULL) {
        printf("Received unknown signal: %d\n", signum);
    } else {
        printf("Received signal: %s (%d)\n", signal_name, signum);
    }
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = signal_handler;

    sigaction(SIGINT, &sa, NULL); 
    sigaction(SIGTERM, &sa, NULL); 
    sigaction(SIGUSR1, &sa, NULL); 

    printf("Waiting for signals...\n");

    while (1) {
        sleep(1);
    }

    return 0;
}