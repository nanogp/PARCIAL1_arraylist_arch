#pragma once
#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

#include "General.h"
#include "Menu.h"

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#define PROPIETARIO_CANT_MAX 10
#define PROPIETARIO_LARGO_NOMBRE 50
#define PROPIETARIO_LARGO_DIRECCION 100
#define PROPIETARIO_LARGO_TARJETA 20
#define PROPIETARIO_ID_MIN 1
#define PROPIETARIO_ID_MAX 1000000

/**************************** TITULOS ************************************************************/
#define PROPIETARIO_ALTA_TITULO "ALTA DE PROPIETARIO"
#define PROPIETARIO_MODIFICACION_TITULO "MODIFICACION DE PROPIETARIO"
#define PROPIETARIO_BAJA_TITULO "BAJA DE PROPIETARIO"
#define PROPIETARIO_LISTADO_TITULO "LISTADO DE PROPIETARIOS"

/**************************** MENSAJES INPUT *****************************************************/
#define PROPIETARIO_MSJ_INGRESE_ID "\n\nIngrese el ID de Propietario: \0"
#define PROPIETARIO_MSJ_INGRESE_NOMBRE "\nIngrese Nombre y Apellido: \0"
#define PROPIETARIO_MSJ_INGRESE_DIRECCION "\nIngrese direccion: \0"
#define PROPIETARIO_MSJ_INGRESE_TARJETA "\nIngrese numero de tarjeta: \0"
#define PROPIETARIO_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Propietario?"

/**************************** MENSAJES ERROR *****************************************************/
#define PROPIETARIO_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define PROPIETARIO_MSJ_ID_NO_EXISTE "\nEl ID de Propietario ingresado no existe"
#define PROPIETARIO_MSJ_LISTA_VACIA "\n\nLa lista de Propietarios esta vacia o todos los registros se dieron de baja"
#define PROPIETARIO_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Propietario"
#define PROPIETARIO_MSJ_REINGRESE_NOMBRE "\nNombre muy largo. Reingrese por favor: \0"
#define PROPIETARIO_MSJ_REINGRESE_DIRECCION "\nDireccion muy larga. Reingrese por favor: \0"
#define PROPIETARIO_MSJ_REINGRESE_TARJETA "\nNumero de tarjeta no valido. Reingrese por favor: \0"

/**************************** MENSAJES INFO ******************************************************/
#define PROPIETARIO_MSJ_ALTA_OK "\nEl Propietario se dio de alta"
#define PROPIETARIO_MSJ_BAJA_OK "\nEl Propietario se dio de baja"
#define PROPIETARIO_MSJ_MODIFICACION_OK "\nEl Propietario se modifico"
#define PROPIETARIO_MSJ_REGISTRO_ACTUAL "\n\nPropietario actual: \0"
#define PROPIETARIO_MSJ_REGISTRO_MODIFICADO "\n\nPropietario modificado: \0"

/**************************** LISTADOS ***********************************************************/
#define PROPIETARIO_MOSTRAR_UNO_MASCARA "\n%d - %-10s - %-10s - %-20s"
#define PROPIETARIO_MOSTRAR_UNO_CABECERA "\nID - NOMBRE - DIRECCION - TARJETA"

/**************************** ORDENAMIENTO *******************************************************/
#define PROPIETARIO_ORDEN_NOMBRE "nombreAsc"
#define PROPIETARIO_ORDEN_ID "idAsc"

/**************************** MENUS **************************************************************/
#define PROPIETARIO_MENU_MODIFICAR_UNO_TITULO "Que desea modificar?"
#define PROPIETARIO_MENU_MODIFICAR_UNO_CANT 2
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE1 "1. Tarjeta de credito"
#define PROPIETARIO_MENU_MODIFICAR_UNO_DETALLE0 "0. Cancelar"


/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    char nombre[PROPIETARIO_LARGO_NOMBRE];
    char direccion[PROPIETARIO_LARGO_DIRECCION];
    char tarjeta[PROPIETARIO_LARGO_TARJETA];
    //------------
    int idPropietario;
    int estado;
}ePropietario;


/**************************** INICIALIZACIONES ***************************************************/
void ePropietario_initHardcode(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//
void ePropietario_init(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//

/**************************** BUSQUEDA ***********************************************************/
int ePropietario_buscarLugarLibre(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//
int ePropietario_siguienteId(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//
int ePropietario_estaVacio(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//
int ePropietario_informarListadoVacio(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//
int ePropietario_buscarPorId(ArrayList* thisPropietarios, int idPropietario);
//-----------------------------------------------------------------------------------------------//
int ePropietario_pedirIdYBuscar(ePropietario listado[]);
//-----------------------------------------------------------------------------------------------//

/**************************** ENTRADA DE DATOS ***************************************************/
void ePropietario_pedirNombre(char retorno[]);
//-----------------------------------------------------------------------------------------------//
void ePropietario_pedirDireccion(char retorno[]);
//-----------------------------------------------------------------------------------------------//
void ePropietario_pedirTarjeta(char retorno[]);
//-----------------------------------------------------------------------------------------------//
ePropietario ePropietario_pedirIngreso(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//

/**************************** LISTADO DE DATOS ***************************************************/
void ePropietario_mostrarUno(ePropietario propietario);
//-----------------------------------------------------------------------------------------------//
void ePropietario_mostrarListado(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//

/**************************** GESTION DE DATOS ***************************************************/
void ePropietario_alta(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//
void ePropietario_modificacion(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//
int ePropietario_baja(ArrayList* thisPropietarios);
//-----------------------------------------------------------------------------------------------//

/**************************** ORDENAMIENTO *******************************************************/
void ePropietario_ordenar(ePropietario listado[], char orden[]);
//-----------------------------------------------------------------------------------------------//
#endif // PROPIETARIO_H_INCLUDED
