/*
 * Kevin Scrivnor
 * Copyright (C) 2024
 * COMP 362 - Operating Systems
 *
 * Modified by: Rafael Diaz
 *
 * Creates a new process and waits for the child process to finish
 * Modify to spawn the entire hierarchy
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void spawn_process(const char *cmd, const char *annotation) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child: exec iam with annotation
        execlp(cmd, cmd, annotation, (char *)NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent: wait for this child
        int status;
        waitpid(pid, &status, 0);
        printf("%s %s exited with status %d\n", cmd, annotation, WEXITSTATUS(status));
    }
}

int main(int argc, char *argv[]) {

    printf("Root process 1: PID %d\n", getpid());

    const char *level1[2] = {"1.1", "1.2"};
    const char *level2[2][2] = {
        {"1.1.1", "1.1.2"},
        {"1.2.1", "1.2.2"}
    };

    for (int i = 0; i < 2; i++) {
        pid_t child = fork();
        if (child < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (child == 0) {

            for (int j = 0; j < 2; j++) {
                spawn_process("./iam", level2[i][j]);
            }

            execlp("./iam", "iam", level1[i], (char *)NULL);
            perror("execlp failed");
            exit(EXIT_FAILURE);
        } else {

            int status;
            waitpid(child, &status, 0);
            printf("Child %s exited with status %d\n", level1[i], WEXITSTATUS(status));
        }
    }

    return 0;
}