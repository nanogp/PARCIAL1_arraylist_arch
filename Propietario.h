#pragma once
#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Menu.h"
#include "ArrayList.h"

/**************************** INCLUSION DE LIBRERIAS DEFAULT *************************************/
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
    char* nombre;
    char* direccion;
    float tarjeta;
    //------------list
    void (*print)();
    //------------sort
    int (*compare)();
    int (*compareId)();
    int (*compareNombre)();
    int (*compareDireccion)();
    int (*compareTarjeta)();
    //------------getters
    int (*getId)();
    char* (*getNombre)();
    char* (*getDireccion)();
    float (*getTarjeta)();
    //------------setters
    int (*setId)();
    int (*setNombre)();
    int (*setDireccion)();
    int (*setTarjeta)();
    //------------input
    int (*nextId)();
    char* (*inputNombre)();
    char* (*inputDireccion)();
    float (*inputTarjeta)();

}ePropietario;


/**************************** GETTERS ************************************************************/
int ePropietario_getIdPropietario(ePropietario* this);
char* ePropietario_getNombre(ePropietario* this);
char* ePropietario_getDireccion(ePropietario* this);
float ePropietario_getTarjeta(ePropietario* this);

/**************************** SETTERS ************************************************************/
int ePropietario_setIdPropietario(ePropietario* this, int id);
int ePropietario_setNombre(ePropietario* this, char* nombre);
int ePropietario_setDireccion(ePropietario* this, char* direccion);
int ePropietario_setTarjeta(ePropietario* this, int tarjeta);

/**************************** CONSTRUCTORES ******************************************************/
ePropietario* ePropietario_new();
ePropietario* ePropietario_newParam(int id, char* nombre, char* direccion, float tarjeta);

/**************************** BUSQUEDA ***********************************************************/
int ePropietario_siguienteId(ArrayList* this);
int ePropietario_informarListadoVacio(ArrayList* this);
ePropietario* ePropietario_buscarPorId(ArrayList* this, int idPropietario);
ePropietario* ePropietario_pedirIdYBuscar(ArrayList* this);

/**************************** ENTRADA DE DATOS ***************************************************/
char* ePropietario_pedirNombre();
char* ePropietario_pedirDireccion();
float ePropietario_pedirTarjeta();
ePropietario* ePropietario_pedirPropietario(ArrayList* this);

/**************************** LISTADO DE DATOS ***************************************************/
void ePropietario_mostrarUno(ePropietario* propietario);

/**************************** GESTION DE DATOS ***************************************************/
int ePropietario_gestionAlta(ArrayList* this);
int ePropietario_gestionModificacion(ArrayList* this);
int ePropietario_gestionBaja(ArrayList* this);
int ePropietario_gestionListado(ArrayList* this);

/**************************** ORDENAMIENTO *******************************************************/
int ePropietario_compararPorCampo(ePropietario* this, ePropietario* that, int nroCampo);
int ePropietario_compararPorId(ePropietario* this, ePropietario* that);
int ePropietario_compararPorNombre(ePropietario* this, ePropietario* that);
int ePropietario_compararPorDireccion(ePropietario* this, ePropietario* that);
int ePropietario_compararPorTarjeta(ePropietario* this, ePropietario* that);
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
#define PROPIETARIO_MSJ_REGISTRO_ACTUAL "\n\nPropietario actual: \0"
#define PROPIETARIO_MSJ_REGISTRO_MODIFICADO "\n\nPropietario modificado: \0"

/**************************** LISTADOS ***********************************************************/
#define PROPIETARIO_MOSTRAR_UNO_MASCARA "\n%d - %-10s - %-10s - %f"
#define PROPIETARIO_MOSTRAR_UNO_CABECERA "\nID - NOMBRE - DIRECCION - TARJETA"
#define PROPIETARIO_MOSTRAR_UNO_PAGINADO 20

/**************************** ORDENAMIENTO *******************************************************/
#define PROPIETARIO_ORDEN_NOMBRE "nombreAsc"
#define PROPIETARIO_ORDEN_ID "idAsc"

#endif // PROPIETARIO_H_INCLUDED
