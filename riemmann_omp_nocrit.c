#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double sum = 0;

double first_function(double x) {
    return x*x;
}

double second_function(double x) {
    return 2 * x * x * x;
}

double third_function(double x) {
    return sin(x);
}

double trapezoide(double a, double b, int n, int num_threads) {
    double h = (b-a)/n;
    double n_local = n / num_threads;
    double a_local = a + (omp_get_thread_num() * n_local * h);
    double b_local = a_local + (n_local * h);
    double local_sum = 0.5 * (third_function(a) + third_function(b));
    for (int i = a_local; i < a_local + n_local; i++) {
        double x = a_local + i * h;
        local_sum += third_function(x);
    }
    sum += local_sum * h;
}

int main(int argc, char* argv[]) {
    double a = 2.0;
    double b = 10.0;
    int n = 1000000;
    int num_threads = 10;
    if (argc == 4) {
        a = strtod(argv[1], NULL);
        b = strtod(argv[2], NULL);
        num_threads = strtod(argv[3], NULL);
    }

    #pragma omp parallel num_threads(num_threads)
    trapezoide(a, b, n, num_threads);
    printf("La aproximacion de la integral es %f\n", sum);
}