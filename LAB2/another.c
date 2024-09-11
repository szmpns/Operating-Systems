#include <stdio.h>
#include <stdlib.h> 

int main() {
    printf("Hello, I'm system program!\n");

    int system_result = system("ls -al /var/log/");

    if (system_result == 0) {
        printf("System command executed successfully.\n");
    } else {
        fprintf(stderr, "Failed to execute the system command.\n");
        return 1;
    }

    return 0;
}