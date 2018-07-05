#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "Propietario.h"
#include "Automovil.h"

int main()
{
    eMenu menuPrincipal = {/*titulo del menu*/{"ESTACIONAMIENTO"},
                           /*cantidad de opciones*/8,
                           /*codigos*/{1,2,3,4,5,8,9,0},
                           /*descripciones*/{"1. Alta Propietario"
                                            "2. Modificacion Propietario"
                                            "3. Baja Propietario"
                                            "4. Ingreso del Automovil"
                                            "5. Egreso del Automovil"
                                            "6. "
                                            "7. "
                                            "8. Listar Automoviles"
                                            "9. Listar Propietarios"
                                            "0. Salir del programa"}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    ePropietario listadoPropietarios[PROPIETARIO_CANT_MAX] = {};
    eAutomovil listadoAutomoviles[AUTOMOVIL_CANT_MAX] = {};

    //INCIALIZAR
    ePropietario_init(listadoPropietarios, PROPIETARIO_CANT_MAX);
    eAutomovil_init(listadoAutomoviles, AUTOMOVIL_CANT_MAX);

    //CARGAR DATOS POR HARDCODE PARA DEBUG
    ePropietario_initHardcode(listadoPropietarios);
    eAutomovil_initHardcode(listadoAutomoviles);


    do
    {
        limpiarPantalla();
        opcion = pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                ePropietario_alta(listadoPropietarios,PROPIETARIO_CANT_MAX);
                break;
            case 2:
                ePropietario_modificacion(listadoPropietarios, PROPIETARIO_CANT_MAX);
                break;
            case 3:
                ePropietario_baja(listadoPropietarios, PROPIETARIO_CANT_MAX);
                break;
            case 4:
                eAutomovil_alta(listadoAutomoviles, AUTOMOVIL_CANT_MAX, listadoPropietarios, PROPIETARIO_CANT_MAX);
                break;
            case 5:
                eAutomovil_baja(listadoAutomoviles, AUTOMOVIL_CANT_MAX, listadoPropietarios, PROPIETARIO_CANT_MAX);
                break;
            case 6:
                limpiarPantalla();imprimirEnPantalla(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 7:
                limpiarPantalla();imprimirEnPantalla(menuPrincipal.descripciones[opcion-1]);pausa();
                break;
            case 8:
                eAutomovil_mostrarListado(listadoAutomoviles, AUTOMOVIL_CANT_MAX);
                pausa();
                break;
            case 9:
                ePropietario_mostrarListado(listadoPropietarios, PROPIETARIO_CANT_MAX);
                pausa();
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
