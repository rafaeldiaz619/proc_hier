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

int
main(int argc, char** argv)
{
    // Obtain information about the process
    pid_t pid = getpid();
    pid_t ppid = getppid();

    // Display the args
    for(int i = 0; i < argc; i++) {
        printf("%d: argv[%d] -> \"%s\"\n", pid, i, argv[i]);
    }
    printf("\n");

    // Display info
    printf("%d: Hi, my process id is %d and my parent's is %d\n", pid, pid, ppid);

    // Have a nap
    printf("%d: Press enter to continue...", pid);
    int i = 1;
    // Use gdb to set i to 0 and the while loop will exit
    // $ gdb -p PID, where PID is the actual process ID number
    // (gdb) set var i=0
    // (gdb) continue
    while(i);

    printf("%d: Bye now.\n", pid);

    // Bye
    exit(EXIT_SUCCESS);
}
