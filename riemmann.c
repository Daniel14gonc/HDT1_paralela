#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double first_function(double x) {
    return x*x;
}

double second_function(double x) {
    return 2 * x * x * x;
}

double third_function(double x) {
    return sin(x);
}

double riemman_sum(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (third_function(a) + third_function(b));
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += third_function(x);
    }
    
    return h * sum;
}

int main(int argc, char* argv[]) {
    double a = 2.0;
    double b = 10.0;
    int n = 1000000;
    if (argc == 3) {
        a = strtod(argv[1], NULL);
        b = strtod(argv[2], NULL);
    }

    double result = riemman_sum(a, b, n);
    printf("La aproximacion de la integral es %f\n", result);
}