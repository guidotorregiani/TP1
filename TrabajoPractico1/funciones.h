#ifndef FUNCIONES_H
#define FUNCIONES_H

int getInt(char mensaje[]);
char getChar(char mensaje[]);
char getNumeroAleatorio(int desde,int hasta,int iniciar);
int suma(int A, int B,int* resultado);
int resta(int A, int B,int* resultado);
int dividir(int A, int B,float* resultado);
int multiplicar(int A, int B, int *resultado);
int factorial(int A, long *resultado);
int getNumber(char msg[],char msgErr[],int max,int min,int* numero);


#endif //FUNCIONES_H

