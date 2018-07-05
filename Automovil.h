#pragma once
#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Propietario.h"
#include "Menu.h"

/**************************** CONSTANTES *********************************************************/
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

/**************************** LIMITES ************************************************************/
#define AUTOMOVIL_CANT_MAX 20
#define AUTOMOVIL_LARGO_PATENTE 20
#define AUTOMOVIL_LARGO_MARCA 20
#define AUTOMOVIL_ID_MIN 1
#define AUTOMOVIL_ID_MAX 1000000

/**************************** TITULOS ************************************************************/
#define AUTOMOVIL_ALTA_TITULO "INGRESO DE AUTOMOVIL"
#define AUTOMOVIL_MODIFICACION_TITULO "MODIFICACION DE AUTOMOVIL"
#define AUTOMOVIL_BAJA_TITULO "EGRESO DE AUTOMOVIL"
#define AUTOMOVIL_LISTADO_TITULO "LISTADO DE AUTOMOVILES"

/**************************** MENSAJES ERROR *****************************************************/
#define AUTOMOVIL_MSJ_ID_NO_EXISTE "\nEl ID de Automovil ingresado no existe"
#define AUTOMOVIL_MSJ_LISTA_VACIA "\n\nLa lista de Automoviles esta vacia o todos los registros se dieron de baja"
#define AUTOMOVIL_MSJ_NO_EXISTEN_ID_PROPIETARIO "\n\nNo existen Automoviles para el ID de Automovil ingresado"
#define AUTOMOVIL_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Automovil"
#define AUTOMOVIL_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define AUTOMOVIL_MSJ_REINGRESE_PATENTE "\nNumero de patente muy largo. Reingrese por favor: \0"
#define AUTOMOVIL_MSJ_REINGRESE_TARJETA "\nNumero de tarjeta no valido. Reingrese por favor: \0"

/**************************** MENSAJES INFO ******************************************************/
#define MSJ_ALPHA_ROMEO "Alfa Romeo"
#define MSJ_FERRARI "Ferrari"
#define MSJ_AUDI "Audi"
#define MSJ_OTROS "Otros"
#define MSJ_CONFIRMA_CORRECTOS "Confirma que los datos ingresados son correctos?"
#define MSJ_CANCELO_GESTION "\nSe cancelo la gestion"
#define AUTOMOVIL_MSJ_ALTA_OK "\nEl Automovil se dio de alta"
#define AUTOMOVIL_MSJ_BAJA_OK "\nEl Automovil se dio de baja"

/**************************** MENSAJES INPUT *****************************************************/
#define AUTOMOVIL_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Automovil?"
#define AUTOMOVIL_MSJ_INGRESE_ID "\n\nIngrese el ID de Automovil: \0"
#define AUTOMOVIL_MSJ_INGRESE_PATENTE "\nIngrese numero de patente: \0"
#define AUTOMOVIL_MSJ_INGRESE_TARJETA "\nIngrese numero de tarjeta: \0"

/**************************** LISTADOS ***********************************************************/
#define AUTOMOVIL_MOSTRAR_UNO_MASCARA "\n%-3d - %-10s - %-20s"
#define AUTOMOVIL_MOSTRAR_UNO_CABECERA "\nID - MARCA - PATENTE"

/**************************** ORDENAMIENTO *******************************************************/
#define AUTOMOVIL_ORDEN_PATENTE "patenteAsc"

/**************************** MENUS **************************************************************/
#define AUTOMOVIL_MENU_MARCA_TITULO "Que marca es?"
#define AUTOMOVIL_MENU_MARCA_CANT 4
#define MSJ_MENU_ALPHA_ROMEO "1. Alfa Romeo"
#define MSJ_MENU_FERRARI "2. Ferrari"
#define MSJ_MENU_AUDI "3. Audi"
#define MSJ_MENU_OTROS "4. Otros"

/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    int marca;
    char patente[AUTOMOVIL_LARGO_PATENTE];
    //------------
	int idAutomovil;
    int idPropietario;
    int estado;
}eAutomovil;


/**************************** BUSQUEDA ***********************************************************/
int eAutomovil_buscarLugarLibre(eAutomovil listadoAutomoviles[]);
//-----------------------------------------------------------------------------------------------//
int eAutomovil_siguienteId(eAutomovil listadoAutomoviles[]);
//-----------------------------------------------------------------------------------------------//
int eAutomovil_buscarPorId(eAutomovil listadoAutomoviles[], int idAutomovil);
//-----------------------------------------------------------------------------------------------//
int eAutomovil_pedirIdYBuscar(eAutomovil listado[]);
//-----------------------------------------------------------------------------------------------//
int eAutomovil_estaVacio(eAutomovil listadoAutomoviles[]);
//-----------------------------------------------------------------------------------------------//
int eAutomovil_informarListadoVacio(eAutomovil listadoAutomoviles[]);
//-----------------------------------------------------------------------------------------------//
void eAutomovil_convertirCodMarcaEnTexto(int codMarca, char textoMarca[]);
//-----------------------------------------------------------------------------------------------//
int eAutomovil_informarExisteIdAutomovil(eAutomovil listadoAutomoviles[], int idAutomovil);
//-----------------------------------------------------------------------------------------------//

/**************************** ENTRADA DE DATOS ***************************************************/
int eAutomovil_pedirMarca();
//-----------------------------------------------------------------------------------------------//
void eAutomovil_pedirPatente(char retorno[]);
//-----------------------------------------------------------------------------------------------//
eAutomovil eAutomovil_pedirIngreso(eAutomovil listadoAutomoviles[], ePropietario listadoPropietarios[], int limitePropietarios);
//-----------------------------------------------------------------------------------------------//

/**************************** LISTADO DE DATOS ***************************************************/
void eAutomovil_mostrarUno(eAutomovil automovil);
//-----------------------------------------------------------------------------------------------//
void eAutomovil_mostrarListado(eAutomovil listadoAutomoviles[]);
//-----------------------------------------------------------------------------------------------//
int devolverHorasEstadia();
//-----------------------------------------------------------------------------------------------//
void emitirTicket(eAutomovil automovil, ePropietario propietario);
//-----------------------------------------------------------------------------------------------//

/**************************** GESTION DE DATOS ***************************************************/
void eAutomovil_alta(eAutomovil listadoAutomoviles[], ePropietario listadoPropietarios[], int limitePropietarios);
//-----------------------------------------------------------------------------------------------//
void eAutomovil_baja(eAutomovil listadoAutomoviles[], ePropietario listadoPropietarios[], int limitePropietarios);
//-----------------------------------------------------------------------------------------------//
void eAutomovil_bajaPropietario(eAutomovil listadoAutomoviles[], ePropietario listadoPropietarios[], int limitePropietarios);
//-----------------------------------------------------------------------------------------------//
int devolverHorasEstadia();
//-----------------------------------------------------------------------------------------------//
int calcularValorEstadia(eAutomovil automovil, int horasEstadia);
//-----------------------------------------------------------------------------------------------//
void emitirTicket(eAutomovil automovil, ePropietario propietario);
//-----------------------------------------------------------------------------------------------//

/**************************** ORDENAMIENTO *******************************************************/
void eAutomovil_ordenar(eAutomovil listado[], char orden[]);
//-----------------------------------------------------------------------------------------------//

#endif //AUTOMOVIL_H_INCLUDED
