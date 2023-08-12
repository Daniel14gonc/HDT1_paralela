/*
* Nombre: Daniel Gonzalez
* Carne: 20293
* Descripcion: Programa para ejemplificar uso de API de OpenMP.
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void hello_world(void);

int main(int argc, char* argv[]) {
    int thread_count = 10;
    if (argc > 1) {
        thread_count = strtol(argv[1], NULL, 10);
    }
    // Se ejecuta la funcion para imprimir con hilos.
    #pragma omp parallel num_threads(thread_count)
    hello_world();

    return 0;
}

void hello_world(void) {
    int threadNum = omp_get_thread_num();
    // Se determinar si el ID de thread es par o impar para imprimir lo que corresponde.
    if (threadNum % 2 == 0) {
        printf("Saludos desde el hilo %d.\n", threadNum);
    } 
    else {
        printf("Feliz cumpleaños numero %d.\n", omp_get_num_threads());
    }
}