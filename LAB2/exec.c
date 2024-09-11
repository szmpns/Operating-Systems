#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Hello, I'm exec program!\n");

    execl("./child", "new", NULL);

    perror("exec");
    return 1;
}