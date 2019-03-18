#include <stdio.h>
#include <math.h>

/**
 * Funcion f: R -> R
 * que se desee encontrar
 * sus raices
 * @param x [double] Valor del dominio el cual
 *                   se quiere hallar su imagen
 * @returns [double] Imagen del valor deseado
*/
double f(double x)
{
    return pow(x, 2) - 3 * x - 8;
}

/**
 * Derivada de f
 * @param x [double] Valor del dominio el cual
 *                   se quiere hallar su imagen
 * @returns [double] Imagen del valor deseado
*/
double df(double x)
{
    return sqrt(3 * x + 8);
}

/**
 * Determina si el metodo numerico 
 * convergera
 * 
 * @param x0 [double] Inicio del metodo
 * @returns [int] 1 Si el metodo converge
 *                0 Si el metodo no converge
*/ 
int converge(double x0)
{
    return 1;
}

/**
 * Metodo numerico que determina una raiz de f
 * 
 * @param tol [double] Tolerancia deseada
 * @returns [double] Una raiz de f
 * 
*/
double aproxSucesivas(double tol)
{
    double xn = 1;
    double xn_1=1;
    int i = 0;
    if(!converge(xn)){
        printf("El metodo no convergera\n");
        return 0;
    }
    printf("Iteraciones del metodo:\n");
    printf("i\txn\txn+1\tError\n");
    double error = tol + 1;
    while(error > tol){
        i += 1;
        xn = xn_1;
        xn_1 = xn - f(xn) / df(xn);
        error = fabs(xn - xn_1);
        printf("%d\t%.4f\t%.4f\t%.4f\n", 
                i, xn, xn_1, error);
    }
    return xn_1;
}

int main(int argc, char const *argv[])
{
    double raiz = aproxSucesivas(.01);
    printf("La raiz es: %lf\n", raiz);
    printf("f(raiz)= %lf\n", f(raiz));
    return 0;
}
