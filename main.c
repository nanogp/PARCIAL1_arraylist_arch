#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "Propietario.h"

int main()
{
    int returnAux;
    eMenu menuPrincipal = {/*titulo del menu*/{"ESTACIONAMIENTO"},
                           /*cantidad de opciones*/8,
                           /*codigos*/{1,2,3,4,5,8,9,0},
                           /*descripciones*/{"\n1. Alta Propietario"
                                             "\n2. Modificacion Propietario"
                                             "\n3. Baja Propietario"
                                             "\n4. Ingreso del Automovil"
                                             "\n5. Egreso del Automovil"
                                             "\n6. "
                                             "\n7. "
                                             "\n8. Listar Automoviles"
                                             "\n9. Listar Propietarios"
                                             "\n0. Salir del programa"}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    ArrayList* listadoPropietarios = al_newArrayList();
ePropietario* p;
p = ePropietario_newParam(1,"jose","Araujo 12312",12345678);
listadoPropietarios->add(listadoPropietarios,p);
p = ePropietario_newParam(2,"domingo","sarmiento 123",87524);
listadoPropietarios->add(listadoPropietarios,p);


    if(listadoPropietarios == NULL)
    {
        returnAux = CHECK_POINTER;
    }

    while(salirDelPrograma == 'N')
    {
        limpiarPantalla();
        opcion = eMenu_pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                ePropietario_gestionAlta(listadoPropietarios);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:
                ePropietario_gestionListado(listadoPropietarios);
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                returnAux = OK;
                break;
        }

    }
    return returnAux;
}
