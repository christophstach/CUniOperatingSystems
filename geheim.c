#include <stdio.h>
#include <jmorecfg.h>

int main(int argc, char *argv[]) {
    char c;

    FILE *fpIn = fopen("geheim.in", "r");
    FILE *fpOut = fopen("geheim.out", "w");

    boolean charFound = FALSE;

    while ((c = (char) fgetc(fpIn)) != EOF) {
        if(c == argv[1][0]) {
            charFound = TRUE;
        }

        fputc(c, fpOut);
    }

    if(charFound) {
        printf("Das Zeichen wurde gefunden!");
    } else {
        printf("Das Zeichen wurde nicht gefunden!");
    }

    printf("\n");

    fclose(fpIn);
    fclose(fpOut);

    return 0;
}