#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleado.h"
#include "Utn_String.h"
#define Nombre_LEN 51

void empleado_menu(Empleado *arrayEmpleado,int len,char* opcionesMenu, char* msgErr)
{
    int opcion;
    int ready=0;
    int id=0;

    empleado_inicializar(arrayEmpleado,1000);

    while(ready!=1)
    {
        getValidInt(&opcion,opcionesMenu,msgErr,1,5,3);

        switch(opcion)
        {
            case 1:
                empleado_alta(arrayEmpleado,1000,id);
                id++;
                break;
            case 2:
                empleado_baja(arrayEmpleado,1000);
                break;
            case 3:
                empleado_modificar(arrayEmpleado,1000);
                break;
            case 4:
                empleado_promedioSalarios(arrayEmpleado,1000);
                empleado_ordenarPorApellido(arrayEmpleado,1000,1);
                empleado_listar(arrayEmpleado,1000);
                break;
            case 5:
                ready=1;
                break;
        }
    }
}

int empleado_inicializar(Empleado *arrayEmpleado,int len)
{
    int i;
    int ret=-1;
    if(arrayEmpleado != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            arrayEmpleado[i].isEmpty=1;
            arrayEmpleado[i].salario=0;
            arrayEmpleado[i].sector=0;
            ret=0;
        }
    }
    return ret;
}
int empleado_lugarLibre(Empleado *arrayEmpleado,int len,int *lugarLibre)
{
    int i;
    int ret=-1;
    if(arrayEmpleado != NULL && len >= 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayEmpleado[i].isEmpty==1)
            {
                *lugarLibre = i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int empleado_alta(Empleado *arrayEmpleado,int len,int idEmpleadoAnterior)
{
    int ret=-1;
    int flag=1; // 0 falso(dio mal) 1 verdadero(dio bien)
    int lugarLibre;
    int auxSector;
    int auxSalario;
    char auxNombre[Nombre_LEN];
    char auxApellido[Nombre_LEN];


    if(arrayEmpleado != NULL && len >= 0)
    {
        if(empleado_lugarLibre(arrayEmpleado,1000,&lugarLibre)==0)
        {
            if(getString(auxNombre,"Ingrese un nombre: \n", "ERROR!\n", 1, Nombre_LEN, 2)!=0)
            {
                flag=0;
            }
            if(getString(auxApellido,"Ingrese apellido: \n", "ERROR!\n", 1, Nombre_LEN, 2)!=0)
            {
                flag=0;
            }
            if(getValidInt(&auxSector,"Ingrese el sector\n","ERROR!\n",1,4,2)!=0)
            {
                flag=0;
            }
            if(getValidInt(&auxSalario,"Ingrese el salario\n","ERROR!\n",1,2500,2)!=0)
            {
                flag=0;
            }

            if(flag==1)
            {
                strncpy(arrayEmpleado[lugarLibre].nombre,auxNombre,Nombre_LEN);
                strncpy(arrayEmpleado[lugarLibre].apellido,auxApellido,Nombre_LEN);
                arrayEmpleado[lugarLibre].sector=auxSector;
                arrayEmpleado[lugarLibre].salario=auxSalario;
                arrayEmpleado[lugarLibre].isEmpty=0;
                arrayEmpleado[lugarLibre].idEmpleado=idEmpleadoAnterior+1;
                ret=0;
            }
            else
            {
                printf("error, campo mal ingresado, el empleado no se guardara");
                arrayEmpleado[lugarLibre].isEmpty=1;
            }

            /*Debuggers
            printf(" %s\n %s\n %d\n %d\n",arrayEmpleado[lugarLibre].apellido
                                         ,arrayEmpleado[lugarLibre].nombre
                                         ,arrayEmpleado[lugarLibre].sector
                                         ,arrayEmpleado[lugarLibre].salario);
            printf(" %d\n",lugarLibre);
            printf("%d\n",arrayEmpleado[lugarLibre].isEmpty);
            printf("%d\n",arrayEmpleado[lugarLibre].idEmpleado);*/
        }

    }
    return ret;
}

int empleado_buscarID(Empleado *arrayEmpleado, int size, int id, int* posicion)
{
    int ret=-1;
    int i;
    if(arrayEmpleado!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayEmpleado[i].isEmpty==1)
            {
                continue;
            }
            else if(arrayEmpleado[i].idEmpleado==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}


int empleado_modificar(Empleado *arrayEmpleado,int len)
{
    int ret=-1;
    int idEmpleado;
    int posicionDeLaCoincidencia=0;
    int ready=0;
    int opcion;

    if(arrayEmpleado != NULL && len >= 0)
    {
        getValidInt(&idEmpleado,"Ingrese el id del empleado a modificar\n","error\n",1,9999,3);
        if(empleado_buscarID(arrayEmpleado,1000,idEmpleado,&posicionDeLaCoincidencia)!=0)
        {
            printf("Error, el id no existe o el array es nulo\n");
        }
        else
        {
            while(ready!=1)
            {
                getValidInt(&opcion,"Ingrese valor a modificar:\n 1 para nombre\n2 para apellido\n3 para sector\4 para salario\5 para salir","Error",1,5,3);

                switch(opcion)
                {
                    case 1:
                        getString(arrayEmpleado[posicionDeLaCoincidencia].nombre,"\nNuevo valor para nombre:\n","\nError\n",1,Nombre_LEN,2);
                        break;
                    case 2:
                        getString(arrayEmpleado[posicionDeLaCoincidencia].apellido,"\nNuevo valor para apellido:\n","\nError\n",1,Nombre_LEN,2);
                        break;
                    case 3:
                        getValidInt(&arrayEmpleado[posicionDeLaCoincidencia].sector,"\nIngrese el nuevo valor para sector\n","\nError\n",1,8,2);
                        break;
                     case 4:
                        getValidInt(&arrayEmpleado[posicionDeLaCoincidencia].salario,"\nIngrese el nuevo valor para salario\n","\nError\n",1,2500,2);
                        break;
                    case 5:
                        ready=1;
                        break;
                }
            }
        }
    }return ret;
}

int empleado_baja(Empleado *arrayEmpleado,int len)
{
    int ret=-1;
    int idEmpleado;
    int posicionDeLaCoincidencia=0;

    if(arrayEmpleado != NULL && len >= 0)
    {
        getValidInt(&idEmpleado,"\nIngrese el id del empleado a dar de baja\n","\nerror\n",1,9999,3);
        if(empleado_buscarID(arrayEmpleado,30,idEmpleado,&posicionDeLaCoincidencia)==0)
        {
            arrayEmpleado[posicionDeLaCoincidencia].isEmpty=1;
            printf("se ha dado de baja el empleado en la posicion %d\n",posicionDeLaCoincidencia);
        }
        else
        {
            printf("Error, el id no existe o el array es nulo");
        }
    }
    return ret;
}

int empleado_listar(Empleado *arrayEmpleado,int len)
{
    int i;
    int ret=-1;
    if(arrayEmpleado!=NULL && len>=0)
    {
        printf("\nEmpleados ordenados alfabeticamente del sector 1\n");
        for(i=0;i<len;i++)
        {
            if(arrayEmpleado[i].sector==1 && arrayEmpleado[i].isEmpty==1)
            {
                    printf(" %s\n %s\n %d\n %d\n",arrayEmpleado[i].apellido
                                                 ,arrayEmpleado[i].nombre
                                                 ,arrayEmpleado[i].sector
                                                 ,arrayEmpleado[i].salario);
            }
        }
        printf("\nEmpleados ordenados alfabeticamente del sector 2\n");
        for(i=0;i<len;i++)
        {
            if(arrayEmpleado[i].sector==2 && arrayEmpleado[i].isEmpty==1)
            {
                    printf(" %s\n %s\n %d\n %d\n",arrayEmpleado[i].apellido
                                                 ,arrayEmpleado[i].nombre
                                                 ,arrayEmpleado[i].sector
                                                 ,arrayEmpleado[i].salario);
            }
        }
        printf("\nEmpleados ordenados alfabeticamente del sector 3\n");
        for(i=0;i<len;i++)
        {
            if(arrayEmpleado[i].sector==3 && arrayEmpleado[i].isEmpty==1)
            {
                    printf(" %s\n %s\n %d\n %d\n",arrayEmpleado[i].apellido
                                                 ,arrayEmpleado[i].nombre
                                                 ,arrayEmpleado[i].sector
                                                 ,arrayEmpleado[i].salario);
            }
        }
        printf("\nEmpleados ordenados alfabeticamente del sector 4\n");
        for(i=0;i<len;i++)
        {
            if(arrayEmpleado[i].sector==4 && arrayEmpleado[i].isEmpty==1)
            {
                    printf(" %s\n %s\n %d\n %d\n",arrayEmpleado[i].apellido
                                                 ,arrayEmpleado[i].nombre
                                                 ,arrayEmpleado[i].sector
                                                 ,arrayEmpleado[i].salario);
            }
        }
        ret=0;
    }
    return ret;
}

int empleado_promedioSalarios(Empleado *arrayEmpleado,int len)
{
    int ret=0;
    int i;
    int contador=0;
    int acumuladorSalarios=0;
    int acumuladorEmpleados=0;
    float promedio;
    if(arrayEmpleado!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(arrayEmpleado[i].salario!=0)
            {
                acumuladorSalarios=acumuladorSalarios+arrayEmpleado[i].salario;
                contador++;
            }
        }
        if(acumuladorSalarios!=0)
        {
            promedio=(float)acumuladorSalarios/contador;
            printf("\nEl promedio de los salarios es %.2f\n",promedio);
            printf("\nEl total de los salarios es %d\n",acumuladorSalarios);
        }
        for(i=0;i<len;i++)
        {
            if(arrayEmpleado[i].salario > promedio)
            {
                acumuladorEmpleados++;
            }
        }
        printf("\nEl total de los empleados cuyo salario supera al promedio es %d\n",acumuladorEmpleados);
    }
    return ret;
}

int empleado_ordenarPorApellido(Empleado *arrayEmpleado,int len,int orden)
{
    int ret=-1;
    int i;
    int j;
    Empleado buffer;

    if(arrayEmpleado!= NULL && len>0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(orden==1 && (strcmp(arrayEmpleado[j].apellido,arrayEmpleado[i].apellido)<0))
                {
                    buffer = arrayEmpleado[i];
                    arrayEmpleado[i] = arrayEmpleado[j];
                    arrayEmpleado[j] = buffer;
                    ret=0;
                }
                else if(orden==0 && (strcmp(arrayEmpleado[j].apellido,arrayEmpleado[i].apellido)>0))
                {
                    buffer = arrayEmpleado[i];
                    arrayEmpleado[i] = arrayEmpleado[j];
                    arrayEmpleado[j] = buffer;
                    ret=0;
                }
            }
        }
    }
    return ret;
}
