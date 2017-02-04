#include <stdio.h> //printf
#include <unistd.h> //fork
#include <sys/types.h> //kill
#include <signal.h> //kill

int main(int argc, char *argv[]) {
    pid_t pid_parent, pid_child_1, pid_child_2, pid_child_1_1, pid_child_1_2, pid_child_2_1, pid_child_2_2;
    pid_parent = getpid();

    if ((pid_child_1 = fork()) == 0) {
        if ((pid_child_1_1 = fork()) == 0) {
            for (int i = 1; i <= 10; ++i) {
                sleep(1);
                printf("Ich bin Child 1-1 (%d) und %d sec alt.\n", pid_child_1_1, i);
            }
        }

        if ((pid_child_1_2 = fork()) == 0) {
            for (int i = 1; i <= 10; ++i) {
                sleep(1);
                printf("Ich bin Child 1-2 (%d) und %d sec alt.\n", pid_child_1_2, i);
            }
        }
    }

    if ((pid_child_2 = fork()) == 0) {
        if ((pid_child_2_1 = fork()) == 0) {
            for (int i = 1; i <= 10; ++i) {
                sleep(1);
                printf("Ich bin Child 2-1 (%d) und %d sec alt.\n", pid_child_2_1, i);
            }
        }

        if ((pid_child_2_2 = fork()) == 0) {
            for (int i = 1; i <= 10; ++i) {
                sleep(1);
                printf("Ich bin Child 2-2 (%d) und %d sec alt.\n", pid_child_2_2, i);
            }
        }
    }

    printf("\n");
    return 0;
}