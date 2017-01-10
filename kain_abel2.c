#include <stdio.h> //printf
#include <unistd.h> //fork
#include <sys/types.h> //kill
#include <signal.h> //kill

int main(int argc, char *argv[]) {
    pid_t pid_parent, pid_kain, pid_abel;
    int fd[2];
    char *writeString = "Schreibtest";

    pid_parent = getpid();

    if (pipe(fd) == 0) {
        printf("\nParent eine Pipe erfolgreich erstellt");
    }


    if ((pid_abel = fork()) != 0) {
        //Parent
        //Lesezugriff schließen
        close(fd[0]);


        if ((pid_kain = fork()) != 0) {
            //Parent
            sleep(5);
            printf("\nParent schreibt in Pipe: %d", write(fd[1], &pid_kain, sizeof(pid_kain)));
            close(fd[1]);


            printf("\nParent: %d, Abel: %d, Kain: %d", pid_parent, pid_abel, pid_kain);
        } else {
            //Kain
            printf("\nChild-Kain: %d", getpid());

            for (int i = 1; i <= 10; ++i) {
                sleep(1);
                printf("\nKain wartet %d sec...", i);
            }
        }
    } else {
        int pid;
        printf("\nChild-Abel: %d", getpid());
        //Abel
        //Schreibzugriff schließen
        close(fd[1]);


        read(fd[0], &pid, sizeof(pid));
        printf("\nAbel kills Kain(%d) aus der Pipe", pid);
        kill(pid, 1);
    }


    printf("\n");
    return 0;
}