#pragma once
#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED


/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "ArrayList.h"

/**************************** LIMITES ************************************************************/
#define GESTION_RUTA_LARGO_MAX 255

/**************************** BUSQUEDA ***********************************************************/
int eGestion_siguienteId(ArrayList* this, int (*pGetId)(void*));
int eGestion_informarListadoVacio(ArrayList* this, char* mensaje);
void* eGestion_buscarPorId(ArrayList* this, int (*pGetId)(void*), int id);
void* eGestion_pedirIdYBuscar(ArrayList* this, int (*pGetId)(void*), char* msjIngreso, char* msjReingreso, int idMin, int idMax);

/**************************** GESTION DE DATOS ***************************************************/
int eGestion_alta(ArrayList* this,
                  void* (*pIngreso)(ArrayList*),
                  void (*pMostrar)(void*),
                  int (*pComparar)(void*, void*),
                  char* titulo,
                  char* cabecera,
                  char* msjOk);
int eGestion_baja(ArrayList* this,
                  void (*pMostrar)(void*),
                  int (*pGetId)(void*),
                  int (*pComparar)(void*, void*),
                  int sizeOfStruct,
                  char* tituloBaja,
                  char* tituloListado,
                  char* cabecera,
                  char* msjListaVacia,
                  char* msjConfirmar,
                  char* msjOk,
                  char* msjIngresoId,
                  char* msjReingresoId,
                  int idMin,
                  int idMax,
                  int paginado);
int eGestion_modificacion(ArrayList* this,
                          void (*pMostrar)(void*),
                          int (*pComparar)(void*, void*),
                          int sizeOfStruct,
                          char* tituloModificacion,
                          char* tituloListado,
                          char* cabecera,
                          char* msjListaVacia,
                          char* msjConfirmar,
                          char* msjOk,
                          int idMin,
                          int idMax,
                          int paginado);
int eGestion_cargarArchivoDatos(ArrayList* this,
                                int (*pComparar)(void*, void*),
                                void* (*pConstructor)(),
                                int sizeOfStruct,
                                char* titulo);
int eGestion_guardarArchivoDatos(ArrayList* this,
                                 int sizeOfStruct,
                                 char* titulo,
                                 char* msjListaVacia);
int eGestion_listado(ArrayList* this, void (*pMostrar)(void*), char* titulo, char* cabecera, char* msjListaVacia, int paginado);

/**************************** TITULOS ************************************************************/
#define GESTION_CARGAR_ARCHIVO_DATOS_TITULO "CARGA ARCHIVO DE DATOS"
#define GESTION_GUARDAR_ARCHIVO_DATOS_TITULO "GUARDAR ARCHIVO DE DATOS"

/**************************** MENSAJES INPUT *****************************************************/
#define GESTION_MSJ_INGRESE_RUTA_DATOS "\nIngrese ruta del archivo de datos:\n"
#define GESTION_MSJ_REINGRESE_RUTA_DATOS "\nReingrese una ruta valida:\n"
#define GESTION_MSJ_ARCHIVO_DATOS_ERROR "\nNo pudo abrirse el archivo:\n %s"

/**************************** MENSAJES ERROR *****************************************************/

/**************************** MENSAJES INFO ******************************************************/

/**************************** ORDENAMIENTO *******************************************************/


#endif // GESTION_H_INCLUDED