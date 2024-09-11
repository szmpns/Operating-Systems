
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t original_parent_pid = getpid();
    printf("PID of the original parent process: %d\n",
original_parent_pid);
    getchar();

    pid_t child_pid = fork();

    if (child_pid == 0) {
        printf("Inside the first child process:\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID (PPID): %d\n", getppid());

        pid_t second_child_pid = fork();

        if (second_child_pid == 0) {
            printf("Inside the second child process:\n");
            printf("PID: %d\n", getpid());
            printf("Parent PID (PPID): %d\n", getppid());

            getchar();
        } else if (second_child_pid > 0) {
            printf("First Child: Created second child with PID: %d\n", second_child_pid);
            getchar();
        } else {
            printf("Second child fork failed!\n");
            return 1;
        }
    } else if (child_pid > 0) {
        printf("Inside the parent process:\n");
        printf("Child PID: %d\n", child_pid);
        getchar();
    } else {
        printf("First child fork failed!\n");
        return 1;
    }

    printf("\nDisplaying Process Tree of the Original Parent:\n");
    char command[50];
    sprintf(command, "pstree -p %d", original_parent_pid);
    system(command);

    return 0;
}