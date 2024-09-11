#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID of the current process: %d\n", getpid());
    getchar(); 

    pid_t child_pid = fork();

    if (child_pid == 0) {
        printf("Inside the child process:\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID (PPID): %d\n", getppid());
        getchar();
    } else if (child_pid > 0) {
        printf("Inside the parent process:\n");
        printf("Child PID: %d\n", child_pid,"\n");
        getchar(); 
    } else {
        printf("Fork failed!\n");
        return 1;
    }

    return 0;
}