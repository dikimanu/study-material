// FIFO 1

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char msg[100];
    char reply[100];

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    while (1) {
        printf("User 1: ");
        fgets(msg, sizeof(msg), stdin);

        int fd = open("fifo1", O_WRONLY);
        write(fd, msg, strlen(msg));
        close(fd);

        if (strncmp(msg, "exit", 4) == 0)
            break;

        fd = open("fifo2", O_RDONLY);
        int n = read(fd, reply, sizeof(reply) - 1);
        reply[n] = '\0';
        close(fd);

        printf("User 2: %s", reply);

        if (strncmp(reply, "exit", 4) == 0)
            break;
    }

    return 0;
}

// FIFO 2

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char msg[100];
    char reply[100];

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    while (1) {
        int fd = open("fifo1", O_RDONLY);
        int n = read(fd, msg, sizeof(msg) - 1);
        msg[n] = '\0';
        close(fd);

        printf("User 1: %s", msg);

        if (strncmp(msg, "exit", 4) == 0)
            break;

        printf("User 2: ");
        fgets(reply, sizeof(reply), stdin);

        fd = open("fifo2", O_WRONLY);
        write(fd, reply, strlen(reply));
        close(fd);

        if (strncmp(reply, "exit", 4) == 0)
            break;
    }

    return 0;
}