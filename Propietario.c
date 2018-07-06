/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Propietario.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <string.h>


/**************************** GETTERS ************************************************************/
int ePropietario_getIdPropietario(ePropietario* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->idPropietario;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* ePropietario_getNombre(ePropietario* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        strcpy(returnAux, this->nombre);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

char* ePropietario_getDireccion(ePropietario* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        strcpy(returnAux, this->direccion);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

float ePropietario_getTarjeta(ePropietario* this)
{
    float returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->tarjeta;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//


/**************************** SETTERS ************************************************************/
int ePropietario_setIdPropietario(ePropietario* this, int id)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        this->idPropietario = id;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_setNombre(ePropietario* this, char* nombre)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        this->nombre = nombre;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_setDireccion(ePropietario* this, char* direccion)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        this->direccion = direccion;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_setTarjeta(ePropietario* this, int tarjeta)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        this->tarjeta = tarjeta;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//


/**************************** CONSTRUCTORES ******************************************************/
ePropietario* ePropietario_new()
{
    ePropietario* propietario;

    propietario = (ePropietario*) malloc(sizeof(ePropietario));

    if(propietario != NULL)
    {
        //------------list
        propietario->print              = ePropietario_mostrarUno;
        //------------sort
        propietario->compare            = ePropietario_compararPorCampo;
        propietario->compareNombre      = ePropietario_compararPorCampo;
        propietario->compareId          = ePropietario_compararPorCampo;
        propietario->compareDireccion   = ePropietario_compararPorCampo;
        propietario->compareTarjeta     = ePropietario_compararPorCampo;
        //------------getters
        propietario->getId              = ePropietario_getIdPropietario;
        propietario->getNombre          = ePropietario_getNombre;
        propietario->getDireccion       = ePropietario_getDireccion;
        propietario->getTarjeta         = ePropietario_getTarjeta;
        //------------setters
        propietario->setId              = ePropietario_setIdPropietario;
        propietario->setNombre          = ePropietario_setNombre;
        propietario->setDireccion       = ePropietario_setDireccion;
        propietario->setTarjeta         = ePropietario_setTarjeta;
        //------------input
        propietario->nextId             = ePropietario_siguienteId;
        propietario->inputNombre        = ePropietario_pedirNombre;
        propietario->inputDireccion     = ePropietario_pedirDireccion;
        propietario->inputTarjeta       = ePropietario_pedirTarjeta;
    }

    return propietario;
}
//-----------------------------------------------------------------------------------------------//

ePropietario* ePropietario_newParam(int id, char* nombre, char* direccion, float tarjeta)
{
    ePropietario* propietario;

    propietario = ePropietario_new();

    if(propietario != NULL)
    {
        propietario->setId(propietario, id);
        propietario->setNombre(propietario, nombre);
        propietario->setDireccion(propietario, direccion);
        propietario->setTarjeta(propietario, tarjeta);
    }
    return propietario;
}
//-----------------------------------------------------------------------------------------------//


/**************************** BUSQUEDA ***********************************************************/
int ePropietario_siguienteId(ArrayList* this)
{
    int returnAux = CHECK_POINTER;
    ePropietario* propietario;

    if(this != NULL)
    {
        returnAux = 0;
        for(int i=0 ; i<this->len(this) ; i++)
        {
            propietario = (ePropietario*) this->get(this, i);

            if(propietario->getId(propietario) > returnAux)
            {
                returnAux = propietario->getId(propietario);
            }
        }

    }
    return (returnAux+1);
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_informarListadoVacio(ArrayList* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->isEmpty(this);

        if(returnAux == 1)
        {
            printf("\nEl listado de Propietarios se encuentra vacio");
        }
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

ePropietario* ePropietario_buscarPorId(ArrayList* this, int idPropietario)
{
    ePropietario* propietario = NULL;
    if(this != NULL)
    {
        for(int i=0 ; i<this->len(this) ; i++)
        {
            propietario = (ePropietario*) this->get(this, i);

            if(propietario->getId(propietario) == idPropietario)
            {
                break;
            }
            else
            {
                propietario = NULL;
            }
        }
    }
    return propietario;
}
//-----------------------------------------------------------------------------------------------//

ePropietario* ePropietario_pedirIdYBuscar(ArrayList* this)
{
    ePropietario* propietario = NULL;
    int id;

    if(this != NULL)
    {
        id = pedirIntValido(PROPIETARIO_MSJ_INGRESE_ID, PROPIETARIO_MSJ_REINGRESE_ID, PROPIETARIO_ID_MIN, PROPIETARIO_ID_MAX);
        propietario = ePropietario_buscarPorId(this, id);
    }
    return propietario;
}
//-----------------------------------------------------------------------------------------------//


/**************************** ENTRADA DE DATOS ***************************************************/
char* ePropietario_pedirNombre()
{
    return constructorStringParametrizado(PROPIETARIO_MSJ_INGRESE_NOMBRE, PROPIETARIO_MSJ_REINGRESE_NOMBRE, PROPIETARIO_LARGO_NOMBRE);
}
//-----------------------------------------------------------------------------------------------//
char* ePropietario_pedirDireccion()
{
    return constructorStringParametrizado(PROPIETARIO_MSJ_INGRESE_DIRECCION, PROPIETARIO_MSJ_REINGRESE_DIRECCION, PROPIETARIO_LARGO_DIRECCION);
}
//-----------------------------------------------------------------------------------------------//
float ePropietario_pedirTarjeta()
{
    return pedirFloatValido(PROPIETARIO_MSJ_INGRESE_TARJETA, PROPIETARIO_MSJ_REINGRESE_TARJETA, 0, PROPIETARIO_LARGO_TARJETA);
}
//-----------------------------------------------------------------------------------------------//
ePropietario* ePropietario_pedirPropietario(ArrayList* this)
{
    ePropietario* propietario = ePropietario_new();

    if(this != NULL && propietario != NULL)
    {
        propietario->setId(propietario, propietario->nextId());
        propietario->setNombre(propietario, propietario->inputNombre());
        propietario->setDireccion(propietario, propietario->inputDireccion());
        propietario->setTarjeta(propietario, propietario->inputTarjeta());
    }
    return propietario;
}
//-----------------------------------------------------------------------------------------------//

/**************************** LISTADO DE DATOS ***************************************************/
void ePropietario_mostrarUno(ePropietario* this, char* mascara)
{
    if(this != NULL)
    {
        printf(mascara, this);
    }
}
//-----------------------------------------------------------------------------------------------//

/**************************** GESTION DE DATOS ***************************************************/
int ePropietario_alta(ArrayList* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_modificacion(ArrayList* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_baja(ArrayList* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_gestionListado(ArrayList* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = this->print(this, ePropietario_mostrarUno, PROPIETARIO_MOSTRAR_UNO_MASCARA, PROPIETARIO_MOSTRAR_UNO_CABECERA, PROPIETARIO_MOSTRAR_UNO_PAGINADO);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//


/**************************** ORDENAMIENTO *******************************************************/
int ePropietario_compararPorCampo(ePropietario* this, ePropietario* that, int nroCampo)
{
    int returnAux = NULL;
    if(this != NULL && that != NULL)
    {
        switch(nroCampo)
        {
            case 1:
                returnAux = this->getId(this) - this->getId(that);
                break;
            case 2:
                returnAux = ePropietario_compararPorNombre(this, that);
                break;
            case 3:
                returnAux = strcmp(this->getDireccion(this), this->getDireccion(that));
                break;
            case 4:
                returnAux = this->getTarjeta(this) - this->getTarjeta(that);
                break;
        }
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorId(ePropietario* this, ePropietario* that)
{
    int returnAux = NULL;
    if(this != NULL && that != NULL)
    {
        returnAux = this->getId(this) - this->getId(that);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorNombre(ePropietario* this, ePropietario* that)
{
    int returnAux = NULL;
    if(this != NULL && that != NULL)
    {
        returnAux = strcmp(this->getNombre(this), this->getNombre(that));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorDireccion(ePropietario* this, ePropietario* that)
{
    int returnAux = NULL;
    if(this != NULL && that != NULL)
    {
        returnAux = strcmp(this->getDireccion(this), this->getDireccion(that));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorTarjeta(ePropietario* this, ePropietario* that)
{
    int returnAux = NULL;
    if(this != NULL && that != NULL)
    {
        returnAux = this->getTarjeta(this) - this->getTarjeta(that);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_ordenarPorNombre(ArrayList* this)
{
    int returnAux = CHECK_POINTER;

    if(this != NULL)
    {
        returnAux = OK;
        this->sort(this, ePropietario_compararPorNombre, ASC);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_ordenarPorTarjeta(ArrayList* this)
{
    int returnAux = CHECK_POINTER;

    if(this != NULL)
    {
        returnAux = OK;
        this->sort(this, ePropietario_compararPorTarjeta, ASC);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

