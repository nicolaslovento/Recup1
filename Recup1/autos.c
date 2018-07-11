#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autos.h"

#include <time.h>


/*Egreso del automóvil (No estacionados): calcular el valor de la estadía. Para ello se utilizará una función que
se encargará de determinar el tiempo de estadía del auto (Esta función ya se encuentra implementada). Al
mismo tiempo del egreso se debe emitir un ticket por pantalla informando: Nombre del propietario, patente
del auto, marca y valor de la estadía. Utilizar la siguiente tabla de valores:
*/






void autosHardcode(eAutos autoArray[],int tama)
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    char marcaNombre[][20]={"","Alfa romeo","Ferrari","audi","Otro"};

    int i;
    for( i=0;i<10;i++)
    {


        autoArray[i].idPropietario=propietario[i];
        strcpy(autoArray[i].patente,patente[i]);
        autoArray[i].idAuto=id[i];
        autoArray[i].estado=1;
        autoArray[i].idMarca=marca[i];
        strcpy(autoArray[i].marcaNombre,marcaNombre[marca[i]]);//asigno nombre a la id marca

    }

}

int buscarLugarLibreAuto(eAutos autoArray[],int tama)
{
    int retorno=-1;
    int i;
    if(tama > 0 && autoArray != NULL)
    {
        retorno = -2;
        for(i=0;i<tama;i++)
        {
            if(autoArray[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int devolverSiguienteIdAuto(eAutos proAuto[],int tama)
{
    int retorno = 0;
    int i;
    if(tama > 0 && proAuto != NULL)
    {
        for(i=0; i<tama; i++)
        {
            if(proAuto[i].estado == 1)
            {
                    if(proAuto[i].idAuto>retorno)
                    {
                         retorno=proAuto[i].idAuto;
                    }

            }

        }
    }
     return retorno+1;
}



void inicializarEstadoAutos(eAutos autoArray[],int tama)
{
    int i;
    for(i=0;i<tama;i++)
    {
       autoArray[i].estado=0;

    }
}
