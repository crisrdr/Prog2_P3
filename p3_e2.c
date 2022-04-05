#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    int n = 0;

    if (argc < 2){
        fprintf(stdout,"Arguments missing\n");
        return EXIT_FAILURE;
    } else if (argc > 2){
        fprintf(stdout,"Too many arguments\n");
        return EXIT_FAILURE;
    }

    n = atoi(argv[1]);        /* Asignación al primer argumento recibido al número de puntos a generar */

    return EXIT_SUCCESS;
}