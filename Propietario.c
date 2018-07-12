/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Propietario.h"

/**************************** GETTERS ************************************************************/
int ePropietario_getId(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((ePropietario*)this)->idPropietario;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* ePropietario_getNombre(void* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((ePropietario*)this)->nombre;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

char* ePropietario_getDireccion(void* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((ePropietario*)this)->direccion;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

float ePropietario_getTarjeta(void* this)
{
    float returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((ePropietario*)this)->tarjeta;
    }
    return returnAux;
}
/**************************** SETTERS ************************************************************/
int ePropietario_setId(void* this, int id)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((ePropietario*)this)->idPropietario = id;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_setNombre(void* this, char* nombre)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && nombre != NULL)
    {
        strcpy(((ePropietario*)this)->nombre, nombre);
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_setDireccion(void* this, char* direccion)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && direccion != NULL)
    {
        strcpy(((ePropietario*)this)->direccion, direccion);
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

int ePropietario_setTarjeta(void* this, float tarjeta)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((ePropietario*)this)->tarjeta = tarjeta;
        returnAux = OK;
    }
    return returnAux;
}
/**************************** CONSTRUCTORES ******************************************************/
void* ePropietario_new()
{
    void* propietario;

    propietario = malloc(sizeof(ePropietario));

    return propietario;
}
//-----------------------------------------------------------------------------------------------//
void* ePropietario_newParam(int id, char* nombre, char* direccion, float tarjeta)
{
    void* propietario;

    propietario = ePropietario_new();

    if(propietario != NULL)
    {
        ePropietario_setId(propietario, id);
        ePropietario_setNombre(propietario, nombre);
        ePropietario_setDireccion(propietario, direccion);
        ePropietario_setTarjeta(propietario, tarjeta);
    }
    return propietario;
}
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
void* ePropietario_pedirPropietario(ArrayList* this)
{
    void* propietario;
    char* nombre;
    char* direccion;
    float tarjeta;

    if(this != NULL)
    {
        nombre = ePropietario_pedirNombre();
        direccion = ePropietario_pedirDireccion();
        tarjeta = ePropietario_pedirTarjeta();

        propietario = ePropietario_newParam(eGestion_siguienteId(this, ePropietario_getId),
                                            nombre,
                                            direccion,
                                            tarjeta);
    }
    return propietario;
}
/**************************** LISTADO DE DATOS ***************************************************/
void ePropietario_mostrarUno(void* this)
{
    if(this != NULL)
    {
        printf(PROPIETARIO_MOSTRAR_UNO_MASCARA,
               ePropietario_getId(this),
               ePropietario_getNombre(this),
               ePropietario_getDireccion(this),
               ePropietario_getTarjeta(this));
    }
}
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
    void* registro;
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
            ePropietario_mostrarUno(registro);
            saltoDeLinea();

            opcion = eMenu_pedirOpcion(&menuModificar);
            switch(opcion)
            {
                case 1:
                    ePropietario_setNombre(registro, ePropietario_pedirNombre());
                    returnAux = huboCambios;
                    break;
                case 2:
                    ePropietario_setDireccion(registro, ePropietario_pedirDireccion());
                    returnAux = huboCambios;
                    break;
                case 3:
                    ePropietario_setTarjeta(registro, ePropietario_pedirTarjeta());
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
//-----------------------------------------------------------------------------------------------//
char* ePropietario_parserATexto(void* this, int bufferSize)
{
    char* returnAux = NULL;
    void* propietario;

    if(this != NULL)
    {
        returnAux = eString_new(bufferSize);

        if(returnAux != NULL)
        {
            propietario = (ePropietario*) this;
            strcpy(returnAux, "");
            strcat(returnAux, intToChar(ePropietario_getId(propietario)));
            strcat(returnAux, ",");
            strcat(returnAux, ePropietario_getNombre(propietario));
            strcat(returnAux, ",");
            strcat(returnAux, ePropietario_getDireccion(propietario));
            strcat(returnAux, ",");
            strcat(returnAux, floatToChar(ePropietario_getTarjeta(propietario), 0));
            strcat(returnAux, "\n");
        }
    }

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
void* ePropietario_parserAVoid(char* this, int bufferSize)
{
    void* returnAux = NULL;
    int id;
    char nombre[bufferSize];
    char direccion[bufferSize];
    float tarjeta;

    if(this != NULL)
    {
        sscanf(this, "%d,%[^,],%[^,],%f", &id, nombre, direccion, &tarjeta);
        returnAux = ePropietario_newParam(id, nombre, direccion, tarjeta);
    }

    return returnAux;
}
/**************************** ORDENAMIENTO *******************************************************/
int ePropietario_compararPorId(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorInt(this, that, ePropietario_getId);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorNombre(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = strcmp(ePropietario_getNombre((ePropietario*)this), ePropietario_getNombre((ePropietario*)that));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorDireccion(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = strcmp(ePropietario_getDireccion((ePropietario*)this), ePropietario_getDireccion((ePropietario*)that));
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int ePropietario_compararPorTarjeta(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = ePropietario_getTarjeta((ePropietario*)this) - ePropietario_getTarjeta((ePropietario*)that);
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
