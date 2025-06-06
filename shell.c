#include "user.h"

int read_command(char *cmdline, size_t size) {
    printf("> ");
    for (size_t i = 0;; i++) {
        char ch = getchar();
        putchar(ch);
        if (i == size - 1) {
            printf("command line too long\n");
            return -1;
        } else if (ch == '\r') {
            printf("\n");
            cmdline[i] = '\0';
            return 0;
        } else {
            cmdline[i] = ch;
        }
    }
}

void main(void) {
    char cmdline[128];
    while (1) {
        if (read_command(cmdline, sizeof(cmdline)) == -1) {
            continue;
        }

        if (strcmp(cmdline, "hello") == 0) {
            printf("Hello world from shell!\n");
        } else if (strcmp(cmdline, "exit") == 0) {
            exit();
        } else {
            printf("unknown command: %s\n", cmdline);
        }
    }
}
