/*
* Kevin Scrivnor
 * Copyright (C) 2024
 * COMP 362 - Operating Systems
 *
 * Modified by: Rafael Diaz
 *
 * Example code - use as an example to create your iam.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <annotation>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *annotation = argv[1];
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("I am child %s (%d), parent PID is %d\n", annotation, pid, ppid);

    // Infinite loop for debugging/attaching
    int i = 1;
    while (i) {
        // spin
    }

    printf("Child %s (%d) exiting\n", annotation, pid);
    return 0;
}
