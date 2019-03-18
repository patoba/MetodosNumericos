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
 * de la funcion f despejar una x
 * tal que:
 * x = g(x)
 * si es trascendental solo sumar una x
 * a cada lado
 * * @param x [double] Valor del dominio el cual
 *                   se quiere hallar su imagen
 * @returns [double] Imagen del valor deseado
*/
double g(double x)
{
    return sqrt(3 * x + 8);
}

/**
 * Derivada de g con respecto x
 * dg = g'
 * @param x [double] Valor del dominio el cual
 *                   se quiere hallar su imagen
 * @returns [double] Imagen del valor deseado
*/
double dg(double x)
{
    return 3 / (2 * sqrt(3 * x + 8));
}

/**
 * Funcion que determina el x0 (x inicial)
 * 
 * returns [double] x0 inicial
*/
double buscarInicio()
{
    //Hiperparametros
    double a = 0; // principio, cambiar si no encuentra una raiz (reducir de pref)
    double inc = 1;  // Incremento, modificar si tarda mucho

    printf("Buscando inicio: \n");
    printf("i\ta\tb\tf(a)\tf(b)\n");

    int i = 0;
    double b = a + inc;
    printf("%d\t%.3f\t%.4f\t%.4f\t%.4f\n", 
            i, a, b, f(a), f(b));
    while(f(a) * f(b) >= 0){
        i++;
        a = b;
        b += inc;
        printf("%d\t%.3f\t%.4f\t%.4f\t%.4f\n", 
            i, a, b, f(a), f(b));
    }
    double c = (a + b) / 2;
    printf("Inicio encontrado: %.4f\n\n", c);
    return c;
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
    return fabs(dg(x0)) <= 1;
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
    double x0 = buscarInicio();
    if(!converge(x0)){
        printf("El metodo no convergera, cambia a g por otro despeje, o empieza antes\n");
        return 0;
    }
    int i = 0;
    double xn = x0;
    double xn_1 = x0;
    printf("Iteraciones del metodo:\n");
    printf("i\txn\txn+1\tError\n");
    double error = tol + 1;
    while(error > tol){
        i += 1;
        xn = xn_1;
        xn_1 = g(xn);
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

/**
 * En el codigo se queria encontrar una raiz de
 * f(x) = x^2 -3x - 8 = 0
 * 
 * Si se despejaba x, quedaria
 * g(x)= x = (x^2 - 8) / 3
 * g'(x) = (2/3)x
 * g'(4.5) = (2/3)(9/2) = 3 > 1
 * Por lo tanto: NO CONVERGE
 * 
 * Por lo que se despejo x², y queda:
 * g(x) = (3x+8)^(1/2) 
 * g'(x) = 3/(2(3*x+8)^(1/2))
 * g'(4.5) = 0.323498 <= 1
 * Por lo tanto: CONVERGE
*/