#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main (int argc, char* argv[]) {

    // Check if the input argument is correct or not
    if (argc > 1) {
        printf("Usage: pingpong...\n");
        exit(1);
    }

    int p[2]; // Pipe file discriptors: read from p[0], write to p[1]
    char buf[4]; // Buffer for sending or receiving between processes

    pipe(p);

    // Child process
    if (fork() == 0) {
        read(p[0], buf, 4);
        fprintf(1, "%d: received %s\n", getpid(), buf);
        write(p[1], "pong", 4);
    }

    // Parent process
    else {
        write(p[1], "ping", 4);
        wait(0); // Wait for the child to finish its execution
        read(p[0], buf, 4);
        fprintf(1, "%d: received %s\n", getpid(), buf);
    }

    close(p[0]);
    close(p[1]);

    exit(0);
}