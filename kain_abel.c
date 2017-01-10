#include <stdio.h> //printf
#include <unistd.h> //fork
#include <sys/types.h> //kill
#include <signal.h> //kill

int main(int argc, char *argv[]) {
    pid_t pid_parent, pid_kain, pid_abel;

    pid_parent = getpid();
    //printf("Parent process started with pid: %d", pid_parent);


    if ((pid_abel = fork()) != 0) {
        //Parent


        if ((pid_kain = fork()) != 0) {
            //Parent

            printf("\nParent: %d, Abel: %d, Kain: %d", pid_parent, pid_abel, pid_kain);
        } else {
            //Kain
            printf("\nChild-Kain: %d", getpid());
            sleep(5);

            printf("\nKain toetet Abel: %d ", kill(pid_abel, 1));
        }
    } else {
        //Abel
        printf("\nChild-Abel: %d", getpid());

        for (int i = 1; i <= 20; ++i) {
            sleep(1);
            printf("\nAbel wartet %d sec...", i);
        }
    }


    printf("\n");
    return 0;
}