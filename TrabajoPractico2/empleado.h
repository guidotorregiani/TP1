#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#define Nombre_LEN 51

typedef struct{
int idEmpleado;
int isEmpty;
char nombre [Nombre_LEN];
char apellido[Nombre_LEN];
int salario;
int sector; //el tipo 1 es el led comun y el tipo 2 el led gigante

}Empleado;


int empleado_inicializar(Empleado *arrayEmpleado,int len);
int empleado_lugarLibre(Empleado *arrayEmpleado,int len,int *lugarLibre);
int empleado_listar(Empleado *arrayEmpleado,int len);
int empleado_alta(Empleado *arrayEmpleado,int len,int idEmpleadoAnterior);
int empleado_modificar(Empleado *arrayEmpleado,int len);
int empleado_baja(Empleado *arrayEmpleado,int len);
int empleado_buscarID(Empleado *arrayEmpleado, int len, int valorBuscado, int* posicion);
int empleado_promedioSalarios(Empleado *arrayEmpleado,int len);
int empleado_ordenarPorApellido(Empleado *arrayEmpleado,int len,int orden);
void empleado_menu(Empleado *arrayEmpleado,int len,char* opcionesMenu, char* msgErr);

#endif // EMPLEADO_H_INCLUDED
