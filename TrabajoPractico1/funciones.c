#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <time.h>



/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief suma dos numeros
 * \param a y b son los numeros que van a ser usados en la operacion
 * \param resultado es donde se va a guardar el resultado de la operacion
 * \return 0 si salio todo bien -1 si exploto algo
 *
 */
int suma(int A, int B,int* resultado)
{
    int retorno=0;
    int aux;
    aux=A+B;
    if(aux> 32767 && aux< -32767)
    {
         printf("Error");
         retorno= -1;
    }
    else
    {
        *resultado=aux;
    }
    return retorno;

}

/**
 * \brief resta dos numeros
 * \param a y b son los numeros que van a ser usados en la operacion
 * \param resultado es donde se va a guardar el resultado de la operacion
 * \return 0 si salio todo bien -1 si exploto algo
 *
 */
int resta(int A, int B,int* resultado)
{
    int retorno=0;
    int aux;
    aux=A-B;
    if(aux< 32767 && aux> -32767)
    {
         *resultado=aux;
    }
    else
    {
        retorno=-1;
    }
    return retorno;

}

/**
 * \brief obtiene un numero dentro de un rango especificado
 * \param a y b son los numeros que van a ser usados en la operacion
 * \return el resultado de la operacion
 *
 */
int getNumber(char msg[],char msgErr[],int max,int min,int* numero)
{
    int retorno=0;
    int aux;
    printf("%s",msg);
    fflush(stdin);
    scanf("%d",&aux);
    if(aux<=max && aux>=min)
    {
        *numero = aux;
    }
    else
    {
       printf("%s" ,msgErr);
       retorno = -1;
    }
    return retorno;
}
/**
 * \brief divide a por b
 * \param a y b son los numeros que van a ser usados en la operacion
 * \param resultado es donde se almacena el resultado
 * \return 0 si salio bien -1 si fallo
 *
 */
int dividir(int A, int B,float* resultado)
{
    int retorno=0;
    if(B!=0 && A!=0)
    {
       *resultado=(float)A/B;
    }
    else if(B==0 || A==0)
    {
        retorno=-1;
    }
    return retorno;
}
/**
 * \brief multiplica a por b
 * \param a y b son los numeros que van a ser usados en la operacion
 * \param resultado es donde se almacena el resultado
 * \return 0 si salio bien -1 si fallo
 *
 */
int multiplicar(int A, int B, int *resultado)
{
    int retorno=0;
    if(B==0 || A==0)
    {
        *resultado=0;
    }
    else if(B!=0 && A!=0)
    {
         *resultado=A*B;
    }
    return retorno;
}
/**
 * \brief hace el factorial de a
 * \param a es el numero que va a se usado en la operacion
 * \param resultado es donde se almacena el resultado
 * \return 0 si salio bien -1 si fallo
 *
 */
int factorial(int A, long *resultado)
{
    int retorno=-1;
    long aux;
    if(A==1)
    {
        *resultado=1;
        retorno=0;
    }
    else
    {
        aux=A;
        while(A>1)
        {
            A--;
            aux=aux*A;
        }
        if(aux>=1 && aux<2147483647)
        {
            *resultado=aux;
            retorno=0;
        }
    }
    return retorno;
}

