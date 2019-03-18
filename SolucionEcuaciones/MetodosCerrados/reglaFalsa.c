#include <stdio.h>
#include <math.h>

/*
 * Funcion real de una variable
 * de la cual se quiere obtener f(x) = 0
 * debe ser continua en el intervalo [a, b]
 *
 * @param x [double] Valor del dominio el cual
 *                   se quiere hallar su imagen
 * @returns [double] Imagen del valor deseado
*/
double f(double x)
{
    return log(x);
}


/**
 * Funcion que determina donde se hace la
 * funcion f, tomando como puntos (a, f(a))
 * y (b, f(b))
 * 
 * @param a [double] Un valor en x de uno de los puntos
 * @param b [double] Un valor en x del otro de los puntos
 *
*/
double puntoCero(double a, double b){
    return (f(b) * a - f(a) * b)/(f(b) - f(a));
}

/*
 * Metodo numerico que encuentra la
 * raiz de la funcion f ubicada
 * en un intervalo [a, b]
 * 
 * @param a [double] Inicio del intervalo
 *                   donde se encuentra la
 *                   raiz
 * @param b [double] Fin del intervalo
 *                   donde se encuentra 
 *                   la raiz 
 * @param tol [double] Tolerancia que se desea
*/
double reglaFalsa(double a, double b, double tol)
{   
    if(f(a) * f(b) >= 0){
        printf("No se encuentra una raiz en el intervalo\n");
        return 0;
    }
    printf("i\ta\tb\tc\tf(a)\tf(b)\tf(c)\terror\n");
    int i = 0;
    double c = puntoCero(a, b);
    double error = fabs(a - b);
    printf("%d\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n", 
            i, a, b, c, f(a), f(b), f(c), error);
    while(error > tol){
        i++;
        if(f(a) * f(c) < 0){
            b = c;
        }else{
            a = c;
        }
        c = puntoCero(a, b);
        error = fabs(a - b);
        printf("%d\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n", 
                i, a, b, c, f(a), f(b), f(c), error);
        if(i > 10)
        break;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    double raiz = reglaFalsa(.5, 3, 0.005);
    printf("La raiz es: %lf\n", raiz);
    printf("f(raiz)= %lf\n", f(raiz));
    return 0;
}
