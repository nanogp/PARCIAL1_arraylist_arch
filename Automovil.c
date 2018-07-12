/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Automovil.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <string.h>

/**************************** GETTERS ************************************************************/
int eAutomovil_getId(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eAutomovil*)this)->idAutomovil;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_getIdPropietario(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eAutomovil*)this)->idPropietario;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eAutomovil_getPatente(void* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = ((eAutomovil*)this)->patente;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_getMarca(void* this)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        returnAux = ((eAutomovil*)this)->marca;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eAutomovil_getMarcaTxt(void* this)
{
    char* returnAux = NULL;
    int codMarca;
    if(this != NULL)
    {
        codMarca = ((eAutomovil*)this)->marca;
        switch(codMarca)
        {
            case ALPHA_ROMEO:
                returnAux = (char*)malloc(sizeof(TXT_ALPHA_ROMEO));
                strcpy(returnAux, TXT_ALPHA_ROMEO);
                break;
            case FERRARI:
                returnAux = (char*)malloc(sizeof(TXT_FERRARI));
                strcpy(returnAux, TXT_FERRARI);
                break;
            case AUDI:
                returnAux = (char*)malloc(sizeof(TXT_AUDI));
                strcpy(returnAux, TXT_AUDI);
                break;
            case OTROS:
                returnAux = (char*)malloc(sizeof(TXT_OTROS));
                strcpy(returnAux, TXT_OTROS);
                break;
        }

    }
    return returnAux;
}
/**************************** SETTERS ************************************************************/
int eAutomovil_setId(void* this, int id)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eAutomovil*)this)->idAutomovil = id;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_setIdPropietario(void* this, int id)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eAutomovil*)this)->idPropietario = id;
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_setPatente(void* this, char* patente)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL && patente != NULL)
    {
        strcpy(((eAutomovil*)this)->patente, patente);
        returnAux = OK;
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_setMarca(void* this, int marca)
{
    int returnAux = CHECK_POINTER;
    if(this != NULL)
    {
        ((eAutomovil*)this)->marca = marca;
        returnAux = OK;
    }
    return returnAux;
}
/**************************** CONSTRUCTORES ******************************************************/
void* eAutomovil_new()
{
    void* automovil;

    automovil = malloc(sizeof(eAutomovil));

    return automovil;
}
//-----------------------------------------------------------------------------------------------//
void* eAutomovil_newParam(int id, int idPropietario, char* patente, int marca)
{
    void* automovil;

    automovil = eAutomovil_new();

    if(automovil != NULL)
    {
        eAutomovil_setId(automovil, id);
        eAutomovil_setIdPropietario(automovil, idPropietario);
        eAutomovil_setPatente(automovil, patente);
        eAutomovil_setMarca(automovil, marca);
    }
    return automovil;
}
/**************************** ENTRADA DE DATOS ***************************************************/
int eAutomovil_pedirPropietario(ArrayList* propietarios)
{
    int returnAux = CHECK_POINTER;
    void* pElement = NULL;

    if(propietarios != NULL)
    {
        returnAux = OK;

        while(pElement == NULL)
        {
            eGestion_listado(propietarios,
                             ePropietario_mostrarUno,
                             PROPIETARIO_LISTADO_TITULO,
                             PROPIETARIO_MOSTRAR_UNO_CABECERA,
                             PROPIETARIO_MSJ_LISTA_VACIA,
                             PROPIETARIO_MOSTRAR_UNO_PAGINADO);
            saltoDeLinea();
            pElement = eGestion_pedirIdYBuscar(propietarios,
                                               ePropietario_getId,
                                               PROPIETARIO_MSJ_INGRESE_ID,
                                               PROPIETARIO_MSJ_REINGRESE_ID,
                                               PROPIETARIO_ID_MIN,
                                               PROPIETARIO_ID_MAX);
            if(pElement == NULL)
            {
                imprimirEnPantalla("\nNo se encontro el ID ingresado");
                pausa();
            }
        }
        returnAux = ePropietario_getId(pElement);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
char* eAutomovil_pedirPatente()
{
    return eString_newParam(AUTOMOVIL_MSJ_INGRESE_PATENTE, AUTOMOVIL_MSJ_REINGRESE_PATENTE, AUTOMOVIL_LARGO_PATENTE);
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_pedirMarca()
{
    int returnAux;
    eMenu menu ={/*titulo del menu*/{"ELEGIR MARCA"},
                           /*cantidad de opciones*/4,
                           /*codigos*/{1,2,3,4},
                           /*descripciones*/{"\n 1. Alfa Romeo"
                                             "\n 2. Ferrari"
                                             "\n 3. Audi"
                                             "\n 4. Otros"}};

    returnAux = eMenu_pedirOpcion(&menu);

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
void* eAutomovil_pedirAutomovil(ArrayList* this, ArrayList* propietarios)
{
    void* automovil;
    char* patente;
    int marca;
    int idPropietario;

    if(this != NULL && propietarios != NULL)
    {
        idPropietario = eAutomovil_pedirPropietario(propietarios);
        patente = eAutomovil_pedirPatente();
        marca = eAutomovil_pedirMarca();

        automovil = eAutomovil_newParam(eGestion_siguienteId(this, eAutomovil_getId),
                                        idPropietario,
                                        patente,
                                        marca);
    }
    return automovil;
}
/**************************** LISTADO DE DATOS ***************************************************/
void eAutomovil_mostrarUno(void* this)
{
    if(this != NULL)
    {
        printf(AUTOMOVIL_MOSTRAR_UNO_MASCARA,
               eAutomovil_getId(this),
               eAutomovil_getIdPropietario(this),
               eAutomovil_getPatente(this),
               eAutomovil_getMarcaTxt(this));
    }
}
/**************************** GESTION DE DATOS ***************************************************/
int eAutomovil_modificarUno(void* this)
{
    int returnAux = CHECK_POINTER;
    eMenu menuModificar = {/*titulo del menu*/{"Que desea modificar?"},
                           /*cantidad de opciones*/4,
                           /*codigos*/{1,2,
                                       9,0},
                           /*descripciones*/"\n  1. Marca"
                                            "\n  2. Patente"
                                            "\n  9. FINALIZAR CAMBIOS"
                                            "\n  0. CANCELAR"};
    void* registro;
    int opcion;
    const int huboCambios = 1;
    char finalizar = 'N';

    if(this != NULL)
    {
        returnAux = OK;
        registro = (eAutomovil*) this;
        do
        {
            limpiarPantallaYMostrarTitulo(MSJ_MODIFICANDO_REGISTRO);
            imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);

            imprimirEnPantalla(AUTOMOVIL_MOSTRAR_UNO_CABECERA);
            eAutomovil_mostrarUno(registro);
            saltoDeLinea();

            opcion = eMenu_pedirOpcion(&menuModificar);
            switch(opcion)
            {
                case 1:
                    eAutomovil_setMarca(registro, eAutomovil_pedirMarca());
                    returnAux = huboCambios;
                    break;
                case 2:
                    eAutomovil_setPatente(registro, eAutomovil_pedirPatente());
                    returnAux = huboCambios;
                    break;
                case 3:
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
char* eAutomovil_parserATexto(void* this, int bufferSize)
{
    char* returnAux = NULL;
    void* automovil;

    if(this != NULL)
    {
        returnAux = eString_new(bufferSize);

        if(returnAux != NULL)
        {
            automovil = (eAutomovil*) this;
            strcpy(returnAux, "");
            strcat(returnAux, intToChar(eAutomovil_getId(automovil)));
            strcat(returnAux, ",");
            strcat(returnAux, intToChar(eAutomovil_getIdPropietario(automovil)));
            strcat(returnAux, ",");
            strcat(returnAux, eAutomovil_getPatente(automovil));
            strcat(returnAux, ",");
            strcat(returnAux, eAutomovil_getMarcaTxt(automovil));
            strcat(returnAux, "\n");
        }
    }

    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
void* eAutomovil_parserAVoid(char* this, int bufferSize)
{
    void* returnAux = NULL;
    int id;
    int idPropietario;
    char patente[bufferSize];
    int marca;

    if(this != NULL)
    {
        sscanf(this, "%d,%d,%[^,],%d", &id, &idPropietario, patente, &marca);
        returnAux = eAutomovil_newParam(id, idPropietario, patente, marca);
    }

    return returnAux;
}
/**************************** ORDENAMIENTO *******************************************************/
int eAutomovil_compararPorId(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorInt(this, that, eAutomovil_getId);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_compararPorIdPropietario(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorInt(this, that, eAutomovil_getIdPropietario);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_compararPorMarca(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorInt(this, that, eAutomovil_getMarca);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_compararPorPatente(void* this, void* that)
{
    int returnAux;

    if(this != NULL && that != NULL)
    {
        returnAux = eGestion_compararPorString(this, that, eAutomovil_getPatente);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_ordenarPorMarca(ArrayList* this)
{
    int returnAux = CHECK_POINTER;

    if(this != NULL)
    {
        returnAux = OK;
        this->sort(this, eAutomovil_compararPorMarca, ASC);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//
int eAutomovil_ordenarPorPatente(ArrayList* this)
{
    int returnAux = CHECK_POINTER;

    if(this != NULL)
    {
        returnAux = OK;
        this->sort(this, eAutomovil_compararPorPatente, ASC);
    }
    return returnAux;
}
//-----------------------------------------------------------------------------------------------//

