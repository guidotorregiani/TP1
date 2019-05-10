#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleado.h"
#include "Utn_String.h"
#define Nombre_LEN 51


int main()
{
    Empleado arrayEmpleado[1000];
    empleado_menu(arrayEmpleado,1000,"\n1 realizar alta de empleado\n2 realizar baja de una empleado\n3 modificar una empleado\n4 informes\n5 para salir\n","\nError\n");
    return 0;
}
