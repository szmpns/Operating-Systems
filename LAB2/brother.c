#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t original_parent_pid = getpid(); // Get the PID of the original parent process

    printf("PID of the current process: %d\n", original_parent_pid);

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
            printf("\nDisplaying Process Information:\n");
            system("ps -o pid,ppid,cmd -C brother"); //program name

        } else if (second_child_pid > 0) {
            printf("First Child: Created second child with PID: %d\n",
second_child_pid);
        } else {
            printf("Second child fork failed!\n");
            return 1;
        }
    } else if (child_pid > 0) {
        printf("Inside the parent process:\n");
        printf("Child PID: %d\n", child_pid);

        pid_t third_child_pid = fork();

        if (third_child_pid == 0) {
            printf("Inside the third child process:\n");
            printf("PID: %d\n", getpid());
            printf("Parent PID (PPID): %d\n", getppid());
        } else if (third_child_pid > 0) {
            printf("Parent Process: Created third child with PID: %d\n",
third_child_pid);
        } else {
            printf("Third child fork failed!\n");
            return 1;
        }

        wait(NULL); // Wait for the third child to complete

    } else {
        printf("First child fork failed!\n");
        return 1;
    }

    // Display process tree
    printf("\nDisplaying Process Tree:\n");
    char command[50];
    sprintf(command, "pstree -p %d", original_parent_pid);
    system(command); // Display the process tree using pstree

    return 0;
}