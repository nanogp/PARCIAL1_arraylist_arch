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
        returnAux = this->nombre;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

char* ePropietario_getDireccion(ePropietario* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->direccion;
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
    if(this != NULL && nombre != NULL)
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
    if(this != NULL && direccion != NULL)
    {
        this->direccion = direccion;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_setTarjeta(ePropietario* this, float tarjeta)
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
        //propietario->setTarjeta         = ePropietario_setTarjeta;
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
        //propietario->setTarjeta(propietario, tarjeta);
        ePropietario_setTarjeta(propietario, tarjeta);
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
            imprimirEnPantalla(PROPIETARIO_MSJ_LISTA_VACIA);
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
    ePropietario* propietario;
    char* nombre;
    char* direccion;
    float tarjeta;

    if(this != NULL)
    {
        nombre = ePropietario_pedirNombre();
        direccion = ePropietario_pedirDireccion();
        tarjeta = ePropietario_pedirTarjeta();

        propietario = ePropietario_newParam(ePropietario_siguienteId(this),nombre,direccion,tarjeta);
    }
    return propietario;
}
//-----------------------------------------------------------------------------------------------//

/**************************** LISTADO DE DATOS ***************************************************/
void ePropietario_mostrarUno(ePropietario* this)
{
    if(this != NULL)
    {
        printf(PROPIETARIO_MOSTRAR_UNO_MASCARA,
               this->getId(this),
               this->getNombre(this),
               this->getDireccion(this),
               this->getTarjeta(this));
    }
}
//-----------------------------------------------------------------------------------------------//

/**************************** GESTION DE DATOS ***************************************************/
//int ePropietario_gestionModificacion(ArrayList* this);
//int ePropietario_gestionBaja(ArrayList* this);
int ePropietario_gestionAlta(ArrayList* this)
{
    int returnAux = CHECK_POINTER;
    ePropietario* registro;
    char confirmacion;

    if(this != NULL)
    {
        limpiarPantallaYMostrarTitulo(PROPIETARIO_ALTA_TITULO);

        registro = ePropietario_pedirPropietario(this);

        if(registro != NULL)
        {
            imprimirEnPantalla(PROPIETARIO_MOSTRAR_UNO_CABECERA);
            registro->print(registro);
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
            this->add(this, registro);
            this->sort(this, ePropietario_compararPorId, ASC);
            imprimirEnPantalla(PROPIETARIO_MSJ_ALTA_OK);
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
        returnAux = OK;

        limpiarPantallaYMostrarTitulo(PROPIETARIO_LISTADO_TITULO);

        if(!ePropietario_informarListadoVacio(this))
        {
            returnAux = this->print(this, ePropietario_mostrarUno, PROPIETARIO_MOSTRAR_UNO_CABECERA, PROPIETARIO_MOSTRAR_UNO_PAGINADO);
        }
    }

    pausa();
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//


/**************************** ORDENAMIENTO *******************************************************/
int ePropietario_compararPorCampo(ePropietario* this, ePropietario* that, int nroCampo)
{
    int returnAux;
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
    int returnAux;
    if(this != NULL && that != NULL)
    {
        returnAux = this->getId(this) - this->getId(that);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorNombre(ePropietario* this, ePropietario* that)
{
    int returnAux;
    if(this != NULL && that != NULL)
    {
        returnAux = strcmp(this->getNombre(this), this->getNombre(that));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorDireccion(ePropietario* this, ePropietario* that)
{
    int returnAux;
    if(this != NULL && that != NULL)
    {
        returnAux = strcmp(this->getDireccion(this), this->getDireccion(that));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorTarjeta(ePropietario* this, ePropietario* that)
{
    int returnAux;
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

