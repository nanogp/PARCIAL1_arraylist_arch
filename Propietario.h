#pragma once
#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Gestion.h"
#include "Menu.h"
#include "ArrayList.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**************************** LIMITES ************************************************************/
#define PROPIETARIO_CANT_MAX 10
#define PROPIETARIO_LARGO_NOMBRE 50
#define PROPIETARIO_LARGO_DIRECCION 100
#define PROPIETARIO_LARGO_TARJETA 9999999999999999
#define PROPIETARIO_ID_MIN 1
#define PROPIETARIO_ID_MAX 1000000

/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    //------------id
    int idPropietario;
    //------------properties
    char nombre[PROPIETARIO_LARGO_NOMBRE];
    char direccion[PROPIETARIO_LARGO_DIRECCION];
    float tarjeta;
}ePropietario;


/**************************** GETTERS ************************************************************/
int ePropietario_getId(void* this);
char* ePropietario_getNombre(void* this);
char* ePropietario_getDireccion(void* this);
float ePropietario_getTarjeta(void* this);

/**************************** SETTERS ************************************************************/
int ePropietario_setId(void* this, int id);
int ePropietario_setNombre(void* this, char* nombre);
int ePropietario_setDireccion(void* this, char* direccion);
int ePropietario_setTarjeta(void* this, float tarjeta);

/**************************** CONSTRUCTORES ******************************************************/
void* ePropietario_new();
void* ePropietario_newParam(int id, char* nombre, char* direccion, float tarjeta);

/**************************** ENTRADA DE DATOS ***************************************************/
char* ePropietario_pedirNombre();
char* ePropietario_pedirDireccion();
float ePropietario_pedirTarjeta();
void* ePropietario_pedirPropietario(ArrayList* this);

/**************************** GESTION DE DATOS ***************************************************/
int ePropietario_modificarUno(void* this);
char* ePropietario_parserATexto(void* this, int bufferSize);
void* ePropietario_parserAVoid(char* this, int bufferSize);

/**************************** LISTADO DE DATOS ***************************************************/
void ePropietario_mostrarUno(void* propietario);

/**************************** ORDENAMIENTO *******************************************************/
int ePropietario_compararPorId(void* this, void* that);
int ePropietario_compararPorNombre(void* this, void* that);
int ePropietario_compararPorDireccion(void* this, void* that);
int ePropietario_compararPorTarjeta(void* this, void* that);
int ePropietario_ordenarPorNombre(ArrayList* this);
int ePropietario_ordenarPorTarjeta(ArrayList* this);

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
#define PROPIETARIO_MSJ_LISTA_VACIA "\n\nLa lista de Propietarios esta vacia"
#define PROPIETARIO_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Propietario"
#define PROPIETARIO_MSJ_REINGRESE_NOMBRE "\nNombre muy largo. Reingrese por favor: \0"
#define PROPIETARIO_MSJ_REINGRESE_DIRECCION "\nDireccion muy larga. Reingrese por favor: \0"
#define PROPIETARIO_MSJ_REINGRESE_TARJETA "\nNumero de tarjeta no valido. Reingrese por favor: \0"

/**************************** MENSAJES INFO ******************************************************/
#define PROPIETARIO_MSJ_ALTA_OK "\nEl Propietario se dio de alta"
#define PROPIETARIO_MSJ_BAJA_OK "\nEl Propietario se dio de baja"
#define PROPIETARIO_MSJ_MODIFICACION_OK "\nEl Propietario se modifico"
#define PROPIETARIO_MSJ_REGISTRO_ACTUAL "\n\nPropietario actual: "
#define PROPIETARIO_MSJ_REGISTRO_MODIFICADO "\n\nPropietario modificado: "

/**************************** LISTADOS ***********************************************************/
#define PROPIETARIO_MOSTRAR_UNO_MASCARA "\n%d \t %-10s \t %-20s \t %.0f"
#define PROPIETARIO_MOSTRAR_UNO_CABECERA "\nID \t NOMBRE \t DIRECCION \t\t TARJETA\n-- \t ------ \t --------- \t\t -------"
#define PROPIETARIO_MOSTRAR_UNO_PAGINADO 20

/**************************** ORDENAMIENTO *******************************************************/
#define PROPIETARIO_ORDEN_NOMBRE "nombreAsc"
#define PROPIETARIO_ORDEN_ID "idAsc"

#endif // PROPIETARIO_H_INCLUDED
