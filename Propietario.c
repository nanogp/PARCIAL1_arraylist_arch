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
#define PROPIETARIO_CARGAR_ARCHIVO_DATOS_TITULO "CARGA ARCHIVO DE DATOS"
#define PROPIETARIO_MSJ_INGRESE_RUTA_DATOS "\nIngrese ruta del archivo de datos:\n"
#define PROPIETARIO_MSJ_REINGRESE_RUTA_DATOS "\nReingrese una ruta valida:\n"
#define PROPIETARIO_MSJ_ARCHIVO_DATOS_ERROR "\nNo pudo abrirse el archivo:\n %s"
int ePropietario_gestionCargarArchivoDatos(ArrayList* this)
{
    int returnAux = CHECK_POINTER;
    FILE* pFile;
    char* ruta;
    char* modoLectura = "rb";
    ePropietario* registro;
    int errorNuevoRegistro = 0;
    int regProcesados = 0;

    if(this != NULL)
    {
        returnAux = CHECK_FILE;

        limpiarPantallaYMostrarTitulo(PROPIETARIO_CARGAR_ARCHIVO_DATOS_TITULO);

        ruta = constructorStringParametrizado(PROPIETARIO_MSJ_INGRESE_RUTA_DATOS, PROPIETARIO_MSJ_REINGRESE_RUTA_DATOS, 255);

        pFile = fopen(ruta, modoLectura);

        if(pFile == NULL)
        {
            printf(PROPIETARIO_MSJ_ARCHIVO_DATOS_ERROR, ruta);
        }
        else
        {
            if(this->len(this) > 0)
            {
                this->clear(this);
            }

            registro = ePropietario_new();
            if(registro != NULL)
            {
                fread(registro, sizeof(ePropietario), 1, pFile);
            }
            else
            {
                errorNuevoRegistro++;
            };

            while(!feof(pFile))
            {

                if(feof(pFile)){break;} //bug ultima lectura doble

                this->add(this, registro);
                this->sort(this, ePropietario_compararPorId, ASC);
                regProcesados++;

                registro = ePropietario_new();
                if(registro != NULL)
                {
                    fread(registro, sizeof(ePropietario), 1, pFile);
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
#define PROPIETARIO_GUARDAR_ARCHIVO_DATOS_TITULO "GUARDAR ARCHIVO DE DATOS"
int ePropietario_gestionGuardarArchivoDatos(ArrayList* this)
{
    int returnAux = CHECK_POINTER;
    FILE* pFile;
    char* ruta;
    char* modoEscritura = "wb";
    ePropietario* registro;
    int errorLecturaRegistro = 0;
    int regProcesados = 0;

    if(this != NULL)
    {
        returnAux = CHECK_FILE;

        limpiarPantallaYMostrarTitulo(PROPIETARIO_GUARDAR_ARCHIVO_DATOS_TITULO);

        ruta = constructorStringParametrizado(PROPIETARIO_MSJ_INGRESE_RUTA_DATOS, PROPIETARIO_MSJ_REINGRESE_RUTA_DATOS, 255);

        pFile = fopen(ruta, modoEscritura);

        if(pFile == NULL)
        {
            printf(PROPIETARIO_MSJ_ARCHIVO_DATOS_ERROR, ruta);
        }
        else
        {
            for(int i=0 ; i<this->len(this) ; i++)
            {
                registro = (ePropietario*) this->get(this, i);

                if(registro != NULL)
                {
                    fwrite(registro, sizeof(ePropietario), 1, pFile);
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
                printf("\nHubo errores leyendo %d registros", errorLecturaRegistro);
            }
        }//endif pFile
    }//endif this

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
                returnAux = this->getId(this) - that->getId(that);
                break;
            case 2:
                returnAux = strcmp(this->getNombre(this), that->getNombre(that));
                break;
            case 3:
                returnAux = strcmp(this->getDireccion(this), that->getDireccion(that));
                break;
            case 4:
                returnAux = this->getTarjeta(this) - that->getTarjeta(that);
                break;
        }
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorId(void* this, void* that)
{
    int returnAux;
    ePropietario* thisP = (ePropietario*) this;
    ePropietario* thatP = (ePropietario*) that;

    if(thisP != NULL && thatP != NULL)
    {
        returnAux = thisP->getId(thisP) - thatP->getId(thatP);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorNombre(void* this, void* that)
{
    int returnAux;
    ePropietario* thisP = (ePropietario*) this;
    ePropietario* thatP = (ePropietario*) that;

    if(thisP != NULL && thatP != NULL)
    {
        returnAux = strcmp(thisP->getNombre(thisP), thatP->getNombre(thatP));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorDireccion(void* this, void* that)
{
    int returnAux;
    ePropietario* thisP = (ePropietario*) this;
    ePropietario* thatP = (ePropietario*) that;

    if(thisP != NULL && thatP != NULL)
    {
        returnAux = strcmp(thisP->getDireccion(thisP), thatP->getDireccion(thatP));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorTarjeta(void* this, void* that)
{
    int returnAux;
    ePropietario* thisP = (ePropietario*) this;
    ePropietario* thatP = (ePropietario*) that;

    if(thisP != NULL && thatP != NULL)
    {
        returnAux = thisP->getTarjeta(thisP) - thatP->getTarjeta(thatP);
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

