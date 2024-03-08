#include "kernel/types.h"
#include "user/user.h"

int main (int argc, char *argv[]) {

    // Check input arguments
    if (argc != 2) {
        printf("Usage: sleep ...\n");
        exit(1);
    }

    // Call sleep function
    sleep(atoi(argv[1]));

    exit(0);
}