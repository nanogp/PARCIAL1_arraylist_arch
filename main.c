#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "Propietario.h"

int main()
{
    int returnAux;
    eMenu menuPrincipal = {/*titulo del menu*/{"ESTACIONAMIENTO"},
                           /*cantidad de opciones*/17,
                           /*codigos*/{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,0},
                           /*descripciones*/{"\n 1. Alta Propietario"
                                             "\n 2. Modificacion Propietario"
                                             "\n 3. Baja Propietario"
                                             "\n 4. Ingreso del Automovil"
                                             "\n 5. Modificacion Automovil"
                                             "\n 6. Egreso del Automovil"
                                             "\n 7. Cargar Archivo Datos Propietarios"
                                             "\n 8. Guardar Archivo Datos Propietarios"
                                             "\n 9. Cargar Archivo CSV Propietarios"
                                             "\n10. Guardar Archivo CSV Propietarios"
                                             "\n11. Cargar Archivo Datos Automoviles"
                                             "\n12. Guardar Archivo Datos Automoviles"
                                             "\n13. Cargar Archivo CSV Automoviles"
                                             "\n14. Guardar Archivo CSV Automoviles"
                                             "\n15. Listar Automoviles"
                                             "\n16. Listar Propietarios"
                                             "\n 0. Salir del programa"}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    ArrayList* listadoPropietarios = al_newArrayList();

//ePropietario* p;
//p = ePropietario_newParam(1,"jose","Araujo 12312",12345678);
//listadoPropietarios->add(listadoPropietarios,p);
//p = ePropietario_newParam(2,"domingo","sarmiento 123",87524);
//listadoPropietarios->add(listadoPropietarios,p);


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
                ePropietario_gestionCargarArchivoDatos(listadoPropietarios);
                break;
            case 8:
                ePropietario_gestionGuardarArchivoDatos(listadoPropietarios);
                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

                break;
            case 12:

                break;
            case 13:

                break;
            case 14:

                break;
            case 15:
                break;
            case 16:
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
