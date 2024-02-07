#include <stdio.h>
#include <math.h>
#define NUM 100

/*
    Método de cálculo isolado das decimais π (Fórmula BBP)
*/

int main(void) {
    long double pi = 0.0;

    /*
        π = ∑ (1 / 16^k) * ((4 / (8k + 1)) - (2 / (8k + 4)) - (1 / (8k + 5)) - (1 / (8k + 6)))
    */

    for (int k = 0; k < NUM; k++) {
        pi += (1.0 / powl(16, k)) * ((4.0 / (8*k + 1)) - (2.0 / (8*k + 4)) - (1.0 / (8*k + 5)) - (1.0 / (8*k + 6)));
    }

    printf("PI (valor estimado): %.15Lf\n", pi);
    printf("PI (valor real): 3.141592653589793");

    return 0;
}
