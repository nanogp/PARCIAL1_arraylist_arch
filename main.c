#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Gestion.h"
#include "Menu.h"
#include "Propietario.h"
#include "Automovil.h"


int main()
{
    int returnAux;
    eMenu menuPrincipal = {/*titulo del menu*/{"ESTACIONAMIENTO"},
                           /*cantidad de opciones*/17,
                           /*codigos*/{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
                           0},
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
    ArrayList* listadoAutomoviles = al_newArrayList();

    if(listadoPropietarios == NULL || listadoAutomoviles == NULL)
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
                eGestion_alta(listadoPropietarios,
                              ePropietario_pedirPropietario,
                              ePropietario_mostrarUno,
                              ePropietario_compararPorId,
                              PROPIETARIO_ALTA_TITULO,
                              PROPIETARIO_MOSTRAR_UNO_CABECERA,
                              PROPIETARIO_MSJ_ALTA_OK);
                break;
            case 2:
                eGestion_modificacion(listadoPropietarios,
                                      ePropietario_modificarUno,
                                      ePropietario_mostrarUno,
                                      ePropietario_getId,
                                      ePropietario_new,
                                      ePropietario_compararPorId,
                                      sizeof(ePropietario),
                                      PROPIETARIO_MODIFICACION_TITULO,
                                      PROPIETARIO_LISTADO_TITULO,
                                      PROPIETARIO_MOSTRAR_UNO_CABECERA,
                                      PROPIETARIO_MSJ_LISTA_VACIA,
                                      PROPIETARIO_MSJ_MODIFICACION_OK,
                                      PROPIETARIO_MSJ_INGRESE_ID,
                                      PROPIETARIO_MSJ_REINGRESE_ID,
                                      PROPIETARIO_ID_MIN,
                                      PROPIETARIO_ID_MAX,
                                      PROPIETARIO_MOSTRAR_UNO_PAGINADO);
              break;
            case 3:
                eGestion_baja(listadoPropietarios,
                              ePropietario_mostrarUno,
                              ePropietario_getId,
                              ePropietario_compararPorId,
                              sizeof(ePropietario),
                              PROPIETARIO_BAJA_TITULO,
                              PROPIETARIO_LISTADO_TITULO,
                              PROPIETARIO_MOSTRAR_UNO_CABECERA,
                              PROPIETARIO_MSJ_LISTA_VACIA,
                              PROPIETARIO_MSJ_CONFIRMAR_BAJA,
                              PROPIETARIO_MSJ_BAJA_OK,
                              PROPIETARIO_MSJ_INGRESE_ID,
                              PROPIETARIO_MSJ_REINGRESE_ID,
                              PROPIETARIO_ID_MIN,
                              PROPIETARIO_ID_MAX,
                              PROPIETARIO_MOSTRAR_UNO_PAGINADO);

                break;
            case 4:
                eGestion_altaHijo(listadoAutomoviles,
                                  listadoPropietarios,
                                  eAutomovil_pedirAutomovil,
                                  eAutomovil_mostrarUno,
                                  eAutomovil_compararPorPatente,
                                  AUTOMOVIL_ALTA_TITULO,
                                  AUTOMOVIL_MOSTRAR_UNO_CABECERA,
                                  PROPIETARIO_MSJ_LISTA_VACIA,
                                  AUTOMOVIL_MSJ_ALTA_OK);
                break;
            case 5:
                eGestion_modificacion(listadoAutomoviles,
                                      eAutomovil_modificarUno,
                                      eAutomovil_mostrarUno,
                                      eAutomovil_getId,
                                      eAutomovil_new,
                                      eAutomovil_compararPorId,
                                      sizeof(eAutomovil),
                                      AUTOMOVIL_MODIFICACION_TITULO,
                                      AUTOMOVIL_LISTADO_TITULO,
                                      AUTOMOVIL_MOSTRAR_UNO_CABECERA,
                                      AUTOMOVIL_MSJ_LISTA_VACIA,
                                      AUTOMOVIL_MSJ_MODIFICACION_OK,
                                      AUTOMOVIL_MSJ_INGRESE_ID,
                                      AUTOMOVIL_MSJ_REINGRESE_ID,
                                      AUTOMOVIL_ID_MIN,
                                      AUTOMOVIL_ID_MAX,
                                      AUTOMOVIL_MOSTRAR_UNO_PAGINADO);
                break;
            case 6:
                eGestion_baja(listadoAutomoviles,
                              eAutomovil_mostrarUno,
                              eAutomovil_getId,
                              eAutomovil_compararPorId,
                              sizeof(eAutomovil),
                              AUTOMOVIL_BAJA_TITULO,
                              AUTOMOVIL_LISTADO_TITULO,
                              AUTOMOVIL_MOSTRAR_UNO_CABECERA,
                              AUTOMOVIL_MSJ_LISTA_VACIA,
                              AUTOMOVIL_MSJ_CONFIRMAR_BAJA,
                              AUTOMOVIL_MSJ_BAJA_OK,
                              AUTOMOVIL_MSJ_INGRESE_ID,
                              AUTOMOVIL_MSJ_REINGRESE_ID,
                              AUTOMOVIL_ID_MIN,
                              AUTOMOVIL_ID_MAX,
                              AUTOMOVIL_MOSTRAR_UNO_PAGINADO);

                break;
            case 7:
                eGestion_cargarArchivoDatos(listadoPropietarios,
                                            ePropietario_compararPorId,
                                            ePropietario_new,
                                            sizeof(ePropietario),
                                            GESTION_CARGAR_ARCHIVO_DATOS_TITULO);
                break;
            case 8:
                eGestion_guardarArchivoDatos(listadoPropietarios,
                                             sizeof(ePropietario),
                                             GESTION_GUARDAR_ARCHIVO_DATOS_TITULO,
                                             PROPIETARIO_MSJ_LISTA_VACIA);
                break;
            case 9:
                eGestion_cargarArchivoTexto(listadoPropietarios,
                                            ePropietario_parserAVoid,
                                            ePropietario_compararPorId,
                                            GESTION_CARGAR_ARCHIVO_TEXTO_TITULO,
                                            2000);
                break;
            case 10:
                eGestion_guardarArchivoTexto(listadoPropietarios,
                                             ePropietario_parserATexto,
                                             GESTION_GUARDAR_ARCHIVO_TEXTO_TITULO,
                                             PROPIETARIO_MSJ_LISTA_VACIA,
                                             2000);
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
                eGestion_listado(listadoAutomoviles,
                                 eAutomovil_mostrarUno,
                                 AUTOMOVIL_LISTADO_TITULO,
                                 AUTOMOVIL_MOSTRAR_UNO_CABECERA,
                                 AUTOMOVIL_MSJ_LISTA_VACIA,
                                 AUTOMOVIL_MOSTRAR_UNO_PAGINADO);
                                 pausa();
                break;
            case 16:
                eGestion_listado(listadoPropietarios,
                                 ePropietario_mostrarUno,
                                 PROPIETARIO_LISTADO_TITULO,
                                 PROPIETARIO_MOSTRAR_UNO_CABECERA,
                                 PROPIETARIO_MSJ_LISTA_VACIA,
                                 PROPIETARIO_MOSTRAR_UNO_PAGINADO);
                                 pausa();
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                returnAux = OK;
                break;
        }

    }
    return returnAux;
}
