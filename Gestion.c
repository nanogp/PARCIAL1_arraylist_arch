/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Gestion.h"
#include "General.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************** BUSQUEDA ***********************************************************/
int eGestion_compararPorId(void* this, void* that, int (*pGetId)(void*))
{
    int returnAux;

    if(this != NULL && that != NULL && (pGetId) != NULL)
    {
        returnAux = (*pGetId)(this) - (*pGetId)(that);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eGestion_siguienteId(ArrayList* this, int (*pGetId)(void*))
{
    int returnAux = CHECK_POINTER;
    void* pElement;

    if(this != NULL && (*pGetId) != NULL)
    {
        returnAux = 0;
        for(int i=0 ; i<this->len(this) ; i++)
        {
            pElement = this->get(this, i);

            if((*pGetId)(pElement) > returnAux)
            {
                returnAux = (*pGetId)(pElement);
            }
        }
    }
    return (returnAux+1);
}
//-----------------------------------------------------------------------------------------------//
int eGestion_informarListadoVacio(ArrayList* this, char* mensaje)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && mensaje != NULL)
    {
        returnAux = this->isEmpty(this);

        if(returnAux == 1)
        {
            imprimirEnPantalla(mensaje);
        }
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

void* eGestion_buscarPorId(ArrayList* this, int (*pGetId)(void*), int id)
{
    void* returnAux = NULL;
    void* pElement = NULL;

    if(this != NULL && (*pGetId) != NULL)
    {
        for(int i=0 ; i<this->len(this) ; i++)
        {
            pElement = this->get(this, i);

            if((*pGetId)(pElement) == id)
            {
                returnAux = pElement;
                break;
            }
        }
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

void* eGestion_pedirIdYBuscar(ArrayList* this,
                              int (*pGetId)(void*),
                              char* msjIngreso,
                              char* msjReingreso,
                              int idMin,
                              int idMax)
{
    void* returnAux = NULL;
    int id;

    if(this != NULL && (*pGetId) != NULL && msjIngreso != NULL && msjReingreso != NULL)
    {
        id = pedirIntValido(msjIngreso, msjReingreso, idMin, idMax);
        returnAux = eGestion_buscarPorId(this, (*pGetId), id);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

/**************************** GESTION DE DATOS ***************************************************/
int eGestion_alta(ArrayList* this,
                  void* (*pIngreso)(ArrayList*),
                  void (*pMostrar)(void*),
                  int (*pComparar)(void*, void*),
                  char* titulo,
                  char* cabecera,
                  char* msjOk)
{
    int returnAux = CHECK_POINTER;
    void* pElement;
    char confirmacion;

    if(this != NULL && (*pIngreso) != NULL && (*pMostrar) != NULL && (*pComparar) != NULL &&
       titulo != NULL && cabecera != NULL && msjOk != NULL)
    {
        limpiarPantallaYMostrarTitulo(titulo);

        pElement = (*pIngreso)(this);

        if(pElement != NULL)
        {
            imprimirEnPantalla(cabecera);
            (*pMostrar)(pElement);
            confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);
            returnAux = OK;
        }
        else
        {
            imprimirEnPantalla("\nError al setear datos en registro nuevo");
            confirmacion = 'N';
        }


        if(confirmacion == 'S')
        {
            this->add(this, pElement);
            this->sort(this, (*pComparar), ASC);
            imprimirEnPantalla(msjOk);
        }
        else
        {
            imprimirEnPantalla(MSJ_CANCELO_GESTION);
        }

        pausa();

    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
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
                  int paginado)
{
    int returnAux = CHECK_POINTER;
    void* pElement = NULL;
    char confirmacion;

    if(this != NULL && (*pMostrar) != NULL && (*pComparar) != NULL &&
       tituloBaja != NULL && tituloListado != NULL && cabecera != NULL &&
       msjListaVacia != NULL && msjConfirmar != NULL && msjOk && msjIngresoId != NULL && msjReingresoId != NULL)
    {
        limpiarPantallaYMostrarTitulo(tituloBaja);

        if(!eGestion_informarListadoVacio(this, msjListaVacia))
        {
            eGestion_listado(this, (*pMostrar), tituloListado, cabecera, msjListaVacia, paginado);

            imprimirTitulo(tituloBaja);

            while(pElement == NULL)
            {
                pElement = eGestion_pedirIdYBuscar(this, (*pGetId), msjIngresoId, msjReingresoId, idMin, idMax);
            }

            imprimirEnPantalla(cabecera);
            (*pMostrar)(pElement);
            confirmacion = pedirConfirmacion(msjConfirmar);

            if(confirmacion == 'S')
            {
                this->remove(this, this->indexOf(this, pElement));
                this->sort(this, (*pComparar), ASC);
                imprimirEnPantalla(msjOk);
            }
            else
            {
                imprimirEnPantalla(MSJ_CANCELO_GESTION);
            }
            returnAux = OK;
        }

        pausa();

    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
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
                          int paginado)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eGestion_cargarArchivoDatos(ArrayList* this,
                                int (*pComparar)(void*, void*),
                                void* (*pConstructor)(),
                                int sizeOfStruct,
                                char* titulo)
{
    int returnAux = CHECK_POINTER;
    FILE* pFile;
    char* ruta;
    char* modoLectura = "rb";
    void* pElement;
    int errorNuevoRegistro = 0;
    int regProcesados = 0;

    if(this != NULL && (*pComparar) != NULL && (*pConstructor)!= NULL && titulo != NULL)
    {
        returnAux = CHECK_FILE;

        limpiarPantallaYMostrarTitulo(titulo);

        ruta = eString_newParam(GESTION_MSJ_INGRESE_RUTA_DATOS, GESTION_MSJ_REINGRESE_RUTA_DATOS, GESTION_RUTA_LARGO_MAX);

        pFile = fopen(ruta, modoLectura);

        if(pFile == NULL)
        {
            printf(GESTION_MSJ_ARCHIVO_DATOS_ERROR, ruta);
        }
        else
        {
            if(this->len(this) > 0) //vaciar lista
            {
                for(int i=0 ; i<this->len(this) ; i++)
                {
                    pElement = this->pop(this, i);
                    free(pElement);
                }
            }

            pElement = (*pConstructor)();
            if(pElement != NULL)
            {
                fread(pElement, sizeOfStruct, 1, pFile);
            }
            else
            {
                errorNuevoRegistro++;
            };

            while(!feof(pFile))
            {

                if(feof(pFile)){break;} //bug ultima lectura doble

                this->add(this, pElement);
                this->sort(this, (*pComparar), ASC);
                regProcesados++;

                pElement = (*pConstructor)();
                if(pElement != NULL)
                {
                    fread(pElement, sizeOfStruct, 1, pFile);
                }
                else
                {
                    errorNuevoRegistro++;
                };
            }
            fclose(pFile);

            returnAux = OK;

            printf(MSJ_REG_PROCESADOS, regProcesados);
            if(errorNuevoRegistro > 0)
            {
                printf(MSJ_NUEVO_REG_ERROR, errorNuevoRegistro);
            }
        }//endif pFile
    }//endif this

    pausa();
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eGestion_guardarArchivoDatos(ArrayList* this,
                                 int sizeOfStruct,
                                 char* titulo,
                                 char* msjListaVacia)
{
    int returnAux = CHECK_POINTER;
    FILE* pFile;
    char* ruta;
    char* modoEscritura = "wb";
    void* pElement;
    int errorLecturaRegistro = 0;
    int regProcesados = 0;

    if(this != NULL && titulo != NULL && msjListaVacia != NULL)
    {
        limpiarPantallaYMostrarTitulo(GESTION_GUARDAR_ARCHIVO_DATOS_TITULO);

        if(!eGestion_informarListadoVacio(this, msjListaVacia))
        {
            returnAux = CHECK_FILE;

            ruta = eString_newParam(GESTION_MSJ_INGRESE_RUTA_DATOS, GESTION_MSJ_REINGRESE_RUTA_DATOS, 255);

            pFile = fopen(ruta, modoEscritura);

            if(pFile == NULL)
            {
                printf(GESTION_MSJ_ARCHIVO_DATOS_ERROR, ruta);
            }
            else
            {
                for(int i=0 ; i<this->len(this) ; i++)
                {
                    pElement = this->get(this, i);

                    if(pElement != NULL)
                    {
                        fwrite(pElement, sizeOfStruct, 1, pFile);
                        regProcesados++;
                    }
                    else
                    {
                        errorLecturaRegistro++;
                    };
                }
                fclose(pFile);

                returnAux = OK;

                printf(MSJ_REG_PROCESADOS, regProcesados);
                if(errorLecturaRegistro > 0)
                {
                    printf("\nHubo errores leyendo %d pElements", errorLecturaRegistro);
                }
            }//endif vacio
        }//endif pFile
    }//endif this

    pausa();
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eGestion_listado(ArrayList* this,
                     void (*pMostrar)(void*),
                     char* titulo,
                     char* cabecera,
                     char* msjListaVacia,
                     int paginado)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && (*pMostrar) != NULL && titulo != NULL && cabecera != NULL && msjListaVacia != NULL)
    {
        returnAux = OK;

        limpiarPantallaYMostrarTitulo(titulo);

        if(!eGestion_informarListadoVacio(this, msjListaVacia))
        {
            returnAux = this->print(this, (*pMostrar), cabecera, paginado);
        }
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//