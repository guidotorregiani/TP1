#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char continuar='s';
    int opcion;
    float resultadoFloat;
    int resultadoInt;
    long resultadoLong;
    int numA;
    int numB;

    while(continuar=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        fflush(stdin);
        if(getNumber("\n Ingrese el numero de la opcion \n","el numero ingresado no esta en el rango de opciones \n",9,1,&opcion)==0)
        {
             switch(opcion)
            {
                case 1:
                    getNumber("\n Ingrese el 1er operando ","el numero ingresado es incorrecto \n",32767,-32767,&numA);
                    printf("el numero ingresado es: %d \n",numA);
                    break;
                case 2:
                    getNumber("\n Ingrese el 2do operando ","el numero ingresado es incorrecto \n",32767,-32767,&numB);
                    printf("el numero ingresado es: %d \n",numB);
                    break;
                case 3:
                    suma(numA,numB,&resultadoInt);
                    printf("el resultado de A+B es: %d \n",resultadoInt);
                    fflush(stdin);
                    break;
                case 4:
                    resta(numA,numB,&resultadoInt);
                    printf("el resultado de A-B es: %d \n",resultadoInt);
                    break;
                case 5:
                    dividir(numA,numB,&resultadoFloat);
                    printf("el resultado de A/B es: %.2f \n",resultadoFloat);
                    break;
                case 6:
                    multiplicar(numA,numB,&resultadoInt);
                    printf("el resultado de A*B es: %d \n",resultadoInt);
                    break;
                case 7:
                    factorial(numA,&resultadoLong);
                    printf("el factorial de A es: %ld \n",resultadoLong);
                    break;
                case 8:
                    if(suma(numA,numB,&resultadoInt)==0)
                    {
                        printf("el resultado de A+B es: %d \n",resultadoInt);
                    }
                    if(resta(numA,numB,&resultadoInt)==0)
                    {
                        printf("el resultado de A-B es: %d \n",resultadoInt);
                    }
                    if(dividir(numA,numB,&resultadoFloat)==0)
                    {
                        printf("el resultado de A/B es: %.2f \n",resultadoFloat);
                    }
                    else if(dividir(numA,numB,&resultadoFloat)!=0)
                    {
                        printf("No es posible dividir 0 ni por 0 \n");
                    }
                    if( multiplicar(numA,numB,&resultadoInt)==0)
                    {
                        printf("el resultado de A*B es: %d \n",resultadoInt);
                    }
                    if(factorial(numA,&resultadoLong)==0)
                    {
                        printf("el factorial de A es: %ld \n",resultadoLong);
                    }
                    else if(factorial(numA,&resultadoLong)!=0)
                    {
                        printf("error, no es posible calcular el factorial \n");
                    }
                    break;
                case 9:
                    continuar='n';
                    break;
            }
        }
    }
}
