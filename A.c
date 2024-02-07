#include <stdio.h>
#include <math.h>
#define NUM 15

// Algoritmo de Gauss-Legendre:

int main(void) {
    /*
        A = 1;
        B = 1 / √2;
        T = 1 / 4;
        P = 1;
    */

    long double a = 1.0;
    long double b = 1.0 / sqrtl(2);
    long double t = 1.0 / 4.0;
    long double p = 1.0;


    for (int i = 0; i < NUM; i++) {
        /*
            An = A + B / 2;
            Bn = 2√A * B;
            Tn = T - P * (A - An)²;
            Pn = 2 * P

        Onde: A = 1, B = 1 / √2, T = 1 / 4, P = 1;
        */

        long double a_n = (a + b) / 2.0;
        long double b_n = sqrtl(a * b);
        long double t_n = t - p * powl(a - a_n, 2);
        long double p_n = 2.0 * p;

        a = a_n;
        b = b_n;
        t = t_n;
        p = p_n;
    }

    /*
        Estimativa dada em:
        π = (An + Bn)² / 4Tn
    */

    long double pi = powl(a + b, 2) / (4.0 * t);

    printf("PI (valor estimado): %.15Lf\n", pi);
    printf("PI (valor real): 3.141592653589793");

    /*
        A NASA utiliza aproximadamente o valor 3,141592653589793 (com 15 casas decimais).
    Para calcular um círculo com 46 bilhões de anos-luz de raio em volta do universo observável,
    seria suficiente uma aproximação de com 40 casas decimais para garantir precisão de 1 átomo de hidrogênio.
    */

    return 0;
}
