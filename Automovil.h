#pragma once
#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Gestion.h"
#include "Menu.h"
#include "ArrayList.h"
#include "Propietario.h"

/**************************** INCLUSION DE LIBRERIAS DEFAULT *************************************/
#include <stdlib.h>

/**************************** CONSTANTES *********************************************************/
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4
#define TXT_ALPHA_ROMEO "Alfa Romeo"
#define TXT_FERRARI "Ferrari"
#define TXT_AUDI "Audi"
#define TXT_OTROS "Otros"

/**************************** LIMITES ************************************************************/
#define AUTOMOVIL_CANT_MAX 10
#define AUTOMOVIL_LARGO_PATENTE 50
#define AUTOMOVIL_LARGO_DIRECCION 100
#define AUTOMOVIL_LARGO_TARJETA 9999999999999999
#define AUTOMOVIL_ID_MIN 1
#define AUTOMOVIL_ID_MAX 1000000

/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    //------------id
    int idAutomovil;
    int idPropietario;
    //------------properties
    char patente[AUTOMOVIL_LARGO_PATENTE];
    int marca;
}eAutomovil;


/**************************** GETTERS ************************************************************/
int eAutomovil_getId(void* this);
int eAutomovil_getIdPropietario(void* this);
char* eAutomovil_getPatente(void* this);
int eAutomovil_getMarca(void* this);
char* eAutomovil_getMarcaTxt(void* this);

/**************************** SETTERS ************************************************************/
int eAutomovil_setId(void* this, int id);
int eAutomovil_setIdPropietario(void* this, int id);
int eAutomovil_setPatente(void* this, char* patente);
int eAutomovil_setMarca(void* this, int marca);

/**************************** CONSTRUCTORES ******************************************************/
void* eAutomovil_new();
void* eAutomovil_newParam(int id, int idPropietario, char* patente, int marca);

/**************************** ENTRADA DE DATOS ***************************************************/
int eAutomovil_pedirPropietario(ArrayList* propietarios);
char* eAutomovil_pedirPatente();
int eAutomovil_pedirMarca();
void* eAutomovil_pedirAutomovil(ArrayList* this, ArrayList* propietarios);

/**************************** GESTION DE DATOS ***************************************************/
int eAutomovil_modificarUno(void* this);
char* eAutomovil_parserATexto(void* this, int bufferSize);
void* eAutomovil_parserAVoid(char* this, int bufferSize);

/**************************** LISTADO DE DATOS ***************************************************/
void eAutomovil_mostrarUno(void* automovil);

/**************************** ORDENAMIENTO *******************************************************/
int eAutomovil_compararPorId(void* this, void* that);
int eAutomovil_compararPorIdPropietario(void* this, void* that);
int eAutomovil_compararPorMarca(void* this, void* that);
int eAutomovil_compararPorPatente(void* this, void* that);
int eAutomovil_ordenarPorMarca(ArrayList* this);
int eAutomovil_ordenarPorPatente(ArrayList* this);

/**************************** TITULOS ************************************************************/
#define AUTOMOVIL_ALTA_TITULO "ALTA DE AUTOMOVIL"
#define AUTOMOVIL_MODIFICACION_TITULO "MODIFICACION DE AUTOMOVIL"
#define AUTOMOVIL_BAJA_TITULO "BAJA DE AUTOMOVIL"
#define AUTOMOVIL_LISTADO_TITULO "LISTADO DE AUTOMOVILS"

/**************************** MENSAJES INPUT *****************************************************/
#define AUTOMOVIL_MSJ_INGRESE_ID "\n\nIngrese el ID de Automovil: \0"
#define AUTOMOVIL_MSJ_INGRESE_PATENTE "\nIngrese Patente: \0"
#define AUTOMOVIL_MSJ_INGRESE_DIRECCION "\nIngrese direccion: \0"
#define AUTOMOVIL_MSJ_INGRESE_TARJETA "\nIngrese numero de tarjeta: \0"
#define AUTOMOVIL_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Automovil?"

/**************************** MENSAJES ERROR *****************************************************/
#define AUTOMOVIL_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define AUTOMOVIL_MSJ_ID_NO_EXISTE "\nEl ID de Automovil ingresado no existe"
#define AUTOMOVIL_MSJ_LISTA_VACIA "\n\nLa lista de Automovils esta vacia"
#define AUTOMOVIL_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Automovil"
#define AUTOMOVIL_MSJ_REINGRESE_PATENTE "\nPatente no valida. Reingrese por favor: \0"
#define AUTOMOVIL_MSJ_REINGRESE_DIRECCION "\nDireccion muy larga. Reingrese por favor: \0"
#define AUTOMOVIL_MSJ_REINGRESE_TARJETA "\nNumero de tarjeta no valido. Reingrese por favor: \0"

/**************************** MENSAJES INFO ******************************************************/
#define AUTOMOVIL_MSJ_ALTA_OK "\nEl Automovil se dio de alta"
#define AUTOMOVIL_MSJ_BAJA_OK "\nEl Automovil se dio de baja"
#define AUTOMOVIL_MSJ_MODIFICACION_OK "\nEl Automovil se modifico"
#define AUTOMOVIL_MSJ_REGISTRO_ACTUAL "\n\nAutomovil actual: "
#define AUTOMOVIL_MSJ_REGISTRO_MODIFICADO "\n\nAutomovil modificado: "

/**************************** LISTADOS ***********************************************************/
#define AUTOMOVIL_MOSTRAR_UNO_MASCARA "\n%d \t %d \t %s \t %s"
#define AUTOMOVIL_MOSTRAR_UNO_CABECERA "\nID \t ID PROPIETARIO \t PATENTE \t MARCA\n-- \t -------------- \t ------- \t -----"
#define AUTOMOVIL_MOSTRAR_UNO_PAGINADO 20

/**************************** ORDENAMIENTO *******************************************************/
#define AUTOMOVIL_ORDEN_PATENTE "nombreAsc"
#define AUTOMOVIL_ORDEN_ID "idAsc"

#endif // AUTOMOVIL_H_INCLUDED
