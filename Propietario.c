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
        strcpy(this->nombre, nombre);
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
        strcpy(this->direccion, direccion);
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
        ePropietario_setTarjeta(propietario, tarjeta);
    }
    return propietario;
}
//-----------------------------------------------------------------------------------------------//

/**************************** ENTRADA DE DATOS ***************************************************/
char* ePropietario_pedirNombre()
{
    return eString_newParam(PROPIETARIO_MSJ_INGRESE_NOMBRE, PROPIETARIO_MSJ_REINGRESE_NOMBRE, PROPIETARIO_LARGO_NOMBRE);
}
//-----------------------------------------------------------------------------------------------//
char* ePropietario_pedirDireccion()
{
    return eString_newParam(PROPIETARIO_MSJ_INGRESE_DIRECCION, PROPIETARIO_MSJ_REINGRESE_DIRECCION, PROPIETARIO_LARGO_DIRECCION);
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

        propietario = ePropietario_newParam(eGestion_siguienteId(this, ePropietario_getIdPropietario),
                                            nombre,
                                            direccion,
                                            tarjeta);
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
int ePropietario_modificarUno(void* this)
{
    int returnAux = CHECK_POINTER;
    eMenu menuModificar = {/*titulo del menu*/{"Que desea modificar?"},
                           /*cantidad de opciones*/5,
                           /*codigos*/{1,2,3,
                                       9,0},
                           /*descripciones*/"\n  1. Nombre"
                                            "\n  2. Direccion"
                                            "\n  3. Tarjeta"
                                            "\n  9. FINALIZAR CAMBIOS"
                                            "\n  0. CANCELAR"};
    ePropietario* registro;
    int opcion;
    const int huboCambios = 1;
    char finalizar = 'N';

    if(this != NULL)
    {
        returnAux = OK;
        registro = (ePropietario*) this;
        do
        {
            limpiarPantallaYMostrarTitulo(MSJ_MODIFICANDO_REGISTRO);
            imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);

            imprimirEnPantalla(PROPIETARIO_MOSTRAR_UNO_CABECERA);
            registro->print(registro);
            saltoDeLinea();

            opcion = eMenu_pedirOpcion(&menuModificar);
            switch(opcion)
            {
                case 1:
                    registro->setNombre(ePropietario_pedirNombre());
                    returnAux = huboCambios;
                    break;
                case 2:
                    registro->setDireccion(ePropietario_pedirDireccion());
                    returnAux = huboCambios;
                    break;
                case 3:
                    registro->setTarjeta(ePropietario_pedirTarjeta());
                    returnAux = huboCambios;
                    break;
                case 4:
                    returnAux = huboCambios;
                    break;
                case 5:
                    returnAux = huboCambios;
                    break;
                case 6:
                    returnAux = huboCambios;
                    break;
                case 7:
                    returnAux = huboCambios;
                    break;
                case 8:
                    returnAux = huboCambios;
                    break;
                case 9:
                    finalizar = 'S';
                    break;
                case 0:
                    finalizar = 'S';
                    returnAux = OK;
                    break;
            }
        }
        while(finalizar == 'N');
    }
    return returnAux;
}

/**************************** ORDENAMIENTO *******************************************************/
int ePropietario_compararPorId(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorId(this, that, ePropietario_getIdPropietario);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorNombre(void* this, void* that)
{
    int returnAux;
    ePropietario* pThis = (ePropietario*) this;
    ePropietario* pThat = (ePropietario*) that;

    if(pThis != NULL && pThat != NULL)
    {
        returnAux = strcmp(pThis->getNombre(pThis), pThat->getNombre(pThat));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorDireccion(void* this, void* that)
{
    int returnAux;
    ePropietario* pThis = (ePropietario*) this;
    ePropietario* pThat = (ePropietario*) that;

    if(pThis != NULL && pThat != NULL)
    {
        returnAux = strcmp(pThis->getDireccion(pThis), pThat->getDireccion(pThat));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorTarjeta(void* this, void* that)
{
    int returnAux;
    ePropietario* pThis = (ePropietario*) this;
    ePropietario* pThat = (ePropietario*) that;

    if(pThis != NULL && pThat != NULL)
    {
        returnAux = pThis->getTarjeta(pThis) - pThat->getTarjeta(pThat);
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

