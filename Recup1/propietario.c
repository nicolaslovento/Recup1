#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "propietario.h"




void modificarPropietario(ePropietarios proArray[],int tamp)//
{
    int id;
    int i;
    int flag=0;
    char respuesta;
    char nuevaTarjeta[20];
    mostrarPropietarios(proArray,tamp);
    printf(" Ingrese su id: ");
    scanf(" %d",&id);

    for(i=0;i<tamp;i++)
    {
        if(proArray[i].estado==1 && proArray[i].idPropietario==id)
        {
            flag=1;
            printf("Ingrese nueva tarjeta: ");
            scanf(" %s",nuevaTarjeta);
            printf("Esta seguro ?(s/n)");
            fflush(stdin);
            respuesta=getchar();

            if(respuesta=='s')
            {
                strcpy(proArray[i].numTarjeta,nuevaTarjeta);
                 printf("Se modifico con exito \n");break;
            }else
                {
                printf("Operacion cancelada \n");break;
                }
            }


    }




        if(flag==0)
        {
           printf("No se encontro el usuario\n");
        }



    }

int darAltaPropietario(ePropietarios proArray[],int tamp)
{


    int id;
    int index;
    int retorno=-1;
    if(tamp > 0 && proArray != NULL)
    {
        index =devolverIndexLibre(proArray,tamp);


        if(index >= 0 && index<20)
        {

            id = devolverSiguienteId(proArray,tamp);
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(proArray[index].nombre);
            while(validarString(proArray[index].nombre)==0)
            {
                printf("Ingrese nuevamente su nombre (solo letras) : ");
                fflush(stdin);
                gets(proArray[index].nombre);
            }
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(proArray[index].apellido);
            while(validarString(proArray[index].apellido)==0)
            {
                printf("Ingrese nuevamente su apellido (solo letras) : ");
                fflush(stdin);
                gets(proArray[index].apellido);
            }
            printf("Ingrese edad: ");
            scanf("%d",&proArray[index].edad);
            printf("Ingrese direccion: ");
            fflush(stdin);
            gets(proArray[index].direccion);
            printf("Ingrese numero de tarjeta de credito: ");
            gets(proArray[index].numTarjeta);
            proArray[index].idPropietario = id;
            proArray[index].estado = 1;
            printf("Se dio de alta con exito\n");
            retorno = 0;
        }else
        {
            printf("No hay mas lugar\n");
        }
    }
    return retorno;
}

void inicializarEstado(ePropietarios lista[],int tamp)
{
    int i;
    for(i=0;i<tamp;i++)
    {
        lista[i].estado=0;
    }
}


void mostrarPropietarios(ePropietarios proArray[],int tamp){
    int i;
    printf("Id :|  Nombre y Apellido  |  Direccion   |  Numero de Tarjeta \n");
    for (i = 0; i < tamp; i++) {
        if (proArray[i].estado == 1) {


            printf("%-5d %-10s %-10s     %-10s       %-10s \n", proArray[i].idPropietario, proArray[i].nombre,proArray[i].apellido,proArray[i].direccion,proArray[i].numTarjeta);
            printf("\n");
        }
    }
}

void propietariosHardCode(ePropietarios proArray[],int tamp)
{


    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
	char apellido[][20]= {"Gomez","Gutierrez","Jaim","Jhon"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};
    int edad[5]={20,45,65,42};
    int i;
    int index;

    for(i=0;i<4;i++)
    {
            index=devolverIndexLibre(proArray,tamp);
            proArray[index].idPropietario=devolverSiguienteId(proArray,tamp);
            strcpy(proArray[index].nombre,nombre[i]);
            strcpy(proArray[index].apellido,apellido[i]);
            strcpy(proArray[index].direccion,direccion[i]);
            strcpy(proArray[index].numTarjeta,tarjeta[i]);
            proArray[index].edad=edad[i];
            proArray[index].estado = 1;
}

}


int devolverSiguienteId(ePropietarios proArray[],int tamp)
{
    int retorno=-1;
    int i,index=1;
    for(i=0;i<tamp;i++)
    {

        if(proArray[i].estado==0)
        {
            retorno=index;
            break;
        }
        index++;
    }

    return retorno;
}

/** \brief
 *
 * \param lista[] ePropietarios
 * \param tamp int
 * \return Retorna -1, sino hay lugar sino el index.
 *
 */
int devolverIndexLibre(ePropietarios proArray[],int tamp)
{
    int retorno=-1;
    int i;
    for(i=0;i<tamp;i++)
    {
        if(proArray[i].estado==0)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

