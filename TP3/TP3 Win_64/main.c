#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_string.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int flagTexto=0;
    int flagBinario=0;
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        getValidInt(&option,"\n1)Cargar los datos de los empleados desde el archivo data.csv (txt)\n"
                            "2)Cargar los datos de los empleados desde el archivo data.csv (bin)\n"
                            "3)Alta de empleado\n"
                            "4)Modificar datos de empleado\n"
                            "5)Baja de empleado\n"
                            "6)MOSTRAR\n"
                            "7)Ordenar empleados\n"
                            "8)Guardar datos (txt)\n"
                            "9)Guardar datos (bin)\n"
                            "10)Salir\n","\nERROR\n",1,10,3);
        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nLa carga del archivo fue exitosa(texto)\n");
                    flagTexto=1;
                }
                else
                {
                    printf("\nERROR en la carga del archivo(texto)\n");
                }
                break;
            case 2:
                if(!controller_loadFromBinary("dataBin.dat",listaEmpleados))
                {
                    printf("\nLa carga del archivo fue exitosa(Binario)\n");
                    flagBinario=1;
                }
                else
                {
                    printf("\nERROR en la carga del archivo(Binario)--\n");
                }
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("\nEl alta del empleado fue exitosa\n");
                }
                else
                {
                    printf("\nERROR en el alta\n");
                }
                break;
            case 4:
                if(!controller_editEmployee(listaEmpleados))
                {
                    printf("\nLa modificacion fue exitosa\n");
                }
                else
                {
                    printf("\nERROR en la modificacion\n");
                }
                break;
            case 5:
                if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("\nLa baja fue exitosa\n");
                }
                else
                {
                    printf("\nERROR en la baja\n");
                }
                break;
            case 6:
                if(flagTexto||flagBinario)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nNo hay Informacion disponible a mostrar\n");
                }
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                if(!controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("\nEl archivo se guardo correctamente(texto)\n");
                }
                else
                {
                    printf("\nERROR(texto)\n");
                }
                break;
            case 9:
                if(!controller_saveAsBinary("dataBin.dat",listaEmpleados))
                {
                    printf("\nEl archivo se guardo correctamente(binario)\n");
                }
                else
                {
                    printf("\nERROR(binario)\n");
                }
                break;
        }
    }while(option != 10);
    return 0;
}
