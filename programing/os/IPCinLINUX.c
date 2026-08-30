#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MSG_LEN 64

int main() {
    int fd[2];  // File descriptors for the pipe
    char message[] = "Linux World!! Understanding Concepts of Piping";
    char recvd_msg[MSG_LEN];

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    // Write to pipe
    if (write(fd[1], message, strlen(message)) == -1) {
        perror("Write failed");
        exit(2);
    }

    // Read from pipe
    if (read(fd[0], recvd_msg, MSG_LEN) == -1) {
        perror("Read failed");
        exit(3);
    }

    // Print received message
    printf("Received: %s\n", recvd_msg);

    return 0;
}