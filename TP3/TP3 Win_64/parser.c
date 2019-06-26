#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    int cantidadDatos;
    Employee *pEmpleado;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferHorasTrabajadas,
                                                  bufferSueldo);
        while(!feof(pFile))
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferHorasTrabajadas,
                                                  bufferSueldo);
            if(cantidadDatos==4)
            {
                pEmpleado = employee_newParametros( bufferId,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);

                if(pEmpleado != NULL)
                {
                    if(ll_add(pArrayListEmployee,pEmpleado))
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pe;
    int retorno=-1;

    do
    {
        pe=employee_new();
        if(pe!=NULL&&pFile!=NULL&&pArrayListEmployee!=NULL)
        {
            if(fread(pe,sizeof(Employee),1,pFile)==1)
            {
                ll_add(pArrayListEmployee,pe);
                retorno=0;
            }
            else
            {
                employee_delete(pe);
            }
        }
    }while(!feof(pFile));
    return retorno;
}
