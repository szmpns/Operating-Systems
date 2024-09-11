#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <PID> <signal>\n", argv[0]);
        return 1;
    }

    pid_t dest_pid = atoi(argv[1]); // Convert PID argument to integer
    int signal_num = atoi(argv[2]); // Convert signal argument to integer

    if (kill(dest_pid, signal_num) == 0) {
        printf("Signal %d sent to process with PID %d\n", signal_num, dest_pid);
    } else {
        fprintf(stderr, "Failed to send signal to process with PID %d\n", dest_pid);
        return 1;
    }

    return 0;
}