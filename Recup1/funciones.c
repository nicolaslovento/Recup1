#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "propietario.h"
#include "autos.h"
#include "estacionamiento.h"
#include "funciones.h"
#include <time.h>
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

void mostrarPorEdad(ePropietarios proArray[],int tamp)
{
    int minimo,maximo,i,flag=0;
    printf("Indique minimo de edad : ");
    scanf("%d",&minimo);
    printf("Indique maximo de edad : ");
    scanf("%d",&maximo);

    if(minimo>0 && maximo<100  && minimo!=maximo)
    {
     printf("Nombre y apellido    |   Direccion     |     Num tarjeta   |     Edad  \n");
    for(i=0;i<tamp;i++)
    {
        if(proArray[i].estado==1 && minimo<=proArray[i].edad && maximo>=proArray[i].edad)
        {
            flag=1;
            printf("%-10s  %-10s      %-10s     %-10s       %-10d\n",proArray[i].nombre,proArray[i].apellido,proArray[i].direccion,proArray[i].numTarjeta,proArray[i].edad);
        }
    }

    }else
    {
        printf("Error.Verifique las edades ingresadas.\n");

    }
}

void mostrarMenu()
{
    printf("1-Alta de propietario \n");
    printf("2-Modificacion de propietario \n");
    printf("3-Baja de propietario \n");
    printf("4-Ingreso de automovil\n");
    printf("5-Mostrar autos \n");
    printf("6-Recaudacion total del estacionamiento \n");
    printf("7-Recaudacion total por marca.\n");
    printf("8-Mostrar propietarios \n");
    printf("9-Mostrar propietario por id \n");
    printf("10-Datos de propietarios marca AUDI .\n");
    printf("11-Lista de autos estacionados,ordenado por patente .\n");
    printf("12-Egreso de auto.\n");
    printf("13-Mostrar Propietarios por edad.\n");
    printf("14-Ordenar propietarios de forma ascendete o descendente.\n");
    printf("15-Salir.\n");
}

void mostrarPropietariosAEleccion(ePropietarios proArray[],int tamp)
{
    int eleccion,i,j,r;
    ePropietarios aux;

    if(proArray!=NULL && tamp>0)
    {
        printf("Como desea ver los propietarios? (1.Ascendente 2.Descendete)\n");
        printf("Opcion: ");
        scanf("%d",&eleccion);


        switch(eleccion)
        {
        case 1:
            for(i=0;i<tamp-1;i++)
            {
                for(j=i+1;j<tamp;j++)
                {
                    if(proArray[i].estado==1 && proArray[j].estado==1)
                    {
                        r=strcmpi(proArray[i].nombre,proArray[j].nombre);
                        if(r>0)
                        {
                            aux=proArray[i];
                            proArray[i]=proArray[j];
                            proArray[j]=aux;


                        }
                    }
                }
            }
            mostrarPropietarios(proArray,tamp);
            break;
        case 2:

            for(i=0;i<tamp-1;i++)
            {
                for(j=i+1;j<tamp;j++)
                {
                    if(proArray[i].estado==1 && proArray[j].estado==1)
                    {
                        r=strcmpi(proArray[i].nombre,proArray[j].nombre);
                        if(r<0)
                        {
                            aux=proArray[i];
                            proArray[i]=proArray[j];
                            proArray[j]=aux;


                        }
                    }
                }
            }
            mostrarPropietarios(proArray,tamp);

            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }
    }else
    {
        printf("Error.\n");
    }
}

void egresosHarcodeo(estacionamiento miEst[])
{
    if(miEst!=NULL)
    {

    int marca[10]={1,1,2,3,2,2,3,4,1,1};
    float importe[10]= {100,200,100,300,100,100,200,200,100,100};
    int i;

    for(i=0;i<10;i++)
    {
        miEst[0].recaudaciones[marca[i]]=importe[i]+miEst[0].recaudaciones[marca[i]];
        miEst[0].recaudacionTotal=importe[i]+miEst[0].recaudacionTotal;
    }

    }else
    {
        printf("Error.\n");
    }
}



void mostrarAutosPorPatente(eAutos autoArray[],int tama,ePropietarios proArray[],int tamp)
{
    if(autoArray!=NULL && tama>0 && proArray!=NULL && tamp>0)
    {
    int i,j,n;
    eAutos aux;
    for(i=0;i<tama-1;i++)
    {
        if(autoArray[i].estado==1 )
        {
            for(j=i+1;j<tama;j++)
            {
                if(autoArray[j].estado==1)
                {
                    n=strcmp(autoArray[i].patente,autoArray[j].patente);
                    if(n>0)
                    {
                        aux=autoArray[i];
                        autoArray[i]=autoArray[j];
                        autoArray[j]=aux;
                    }
                }
            }
        }
    }

    mostrarAutos(autoArray,tama,proArray,tamp);
    }else
    {
        printf("Error.\n");
    }

}


void mostrarDatosDeAudi(eAutos autoArray[],int tama,ePropietarios proArray[],int tamp)
{
    if(autoArray!=NULL && tama>0 && proArray!=NULL && tamp>0)
    {

    int i;
    int j;
    printf("|   Nombre    |    Apellido    |   patente   |   Marca   |   id auto \n");
    for (i = 0; i < tama; i++)
    {

        if (autoArray[i].idMarca==AUDI && autoArray[i].estado==1)
        {

            for (j = 0; j < tamp; j++)
            {
                if(proArray[j].estado==1 && proArray[j].idPropietario==autoArray[i].idPropietario)

                printf("%s            %-10s         %-10s     %-10s     %-10d\n", proArray[j].nombre, proArray[j].apellido,autoArray[j].patente,autoArray[i].marcaNombre,autoArray[i].idAuto);


            }



        }

    }
    }else
    {
        printf("Error.\n");
    }

}

void mostrarDatosPorId(eAutos autoArray[],int tama,ePropietarios proArray[],int tamp,int id)
{

    int i;
    int j;
    int flag=1;

    for (i = 0; i < tamp; i++)
    {

        if (proArray[i].estado==1 && proArray[i].idPropietario==id)
        {
            printf("Nombre y Apellido: %s  %s \n",proArray[i].nombre, proArray[i].apellido);

            for (j = 0; j < tama; j++)
            {
                if(proArray[i].idPropietario==autoArray[j].idPropietario && autoArray[j].estado==1)
                {

                if(flag==1)
                {
                 printf("Patente   |   Marca     |   id de auto  \n");
                 flag=2;
                }
                printf("%-10s   %-10s        %-10d\n", autoArray[j].patente,autoArray[j].marcaNombre,autoArray[j].idAuto);


                }
        }

    }
    }
   }

void darBajaPropietario(ePropietarios proArray[],int tamp,eAutos autoArray[],int tama,estacionamiento miEst[])
{
    if(proArray!=NULL && tamp>0 && autoArray!=NULL && tama>0 && miEst!=NULL)
    {
    int id;
    int i,j,flag=0;
    int horas;
    float auxRecaudacion=0,precioEstadia;
    char respuesta;
    mostrarPropietarios(proArray,tamp);

    printf(" Ingrese id de propietario: ");
    scanf(" %d",&id);

    for(i=0;i<tamp;i++)
    {
        if(proArray[i].idPropietario==id && proArray[i].estado==1)
        {
            printf("Esta seguro que desea darse de baja? \n");
            scanf(" %c",&respuesta);
            flag=1;
            if(respuesta=='s')
            {
            printf("*********************************************\n");
            printf("* Propietario : %s  %s *\n",proArray[i].nombre,proArray[i].apellido);
            printf("*********************************************\n");

            for(j=0;j<tama;j++)
            {

                if(proArray[i].idPropietario==autoArray[j].idPropietario && autoArray[j].estado==1)
                {
                    flag=2;

                    horas=(rand()%12);
                    precioEstadia=(float)horas*miEst[0].precios[autoArray[j].idMarca];
                    miEst[0].recaudaciones[autoArray[j].idMarca]=precioEstadia+miEst[0].recaudaciones[autoArray[j].idMarca];
                    miEst[0].recaudacionTotal=(float)precioEstadia+miEst[0].recaudacionTotal;
                    auxRecaudacion=precioEstadia+auxRecaudacion;
                    printf("* Auto: %s      Horas: %d                    \n",autoArray[j].marcaNombre,horas);
                    printf("* Precio hora: %0.2f Precio estadia :%0.2f \n",miEst[0].precios[autoArray[j].idMarca],precioEstadia);
                    printf("*********************************************\n");
                    autoArray[j].estado=0;


                }
            }


        }
    }
    }


    if(flag==2)
    {
        printf("Total a pagar : %0.2f \n",auxRecaudacion);
        printf("*********************************************\n");
        proArray[i].estado=0;
    }
    if(flag==0)
    {
        printf("No se encontro el propietario.\n");
    }

    if(flag==1)
    {
        printf("El propietario fue dado de baja pero no tiene autos estacionados.\n");
    }



    }else
    {
        printf("Error.\n");
    }
}


void egresoDeAuto(eAutos autoArray[],int tama,ePropietarios proArray[],int tamp,estacionamiento miEst[])
{
    if(proArray!=NULL && tamp>0 && autoArray!=NULL && tama>0 && miEst!=NULL)
    {

    int i;
    int j;
    int idPropietario;
    int idAuto;
    int horas;
    int flag=0;
    float precioEstadia=0;

    mostrarPropietarios(proArray,tamp);
    printf("Ingrese id de propietario:");
    scanf("%d",&idPropietario);


    for(i=0;i<tamp;i++)
    {

        if(proArray[i].idPropietario==idPropietario && proArray[i].estado==1)
        {
            flag=1;
            mostrarDatosPorId(autoArray,tama,proArray,tamp,idPropietario);
            printf("Ingrese id de auto:\n");
            scanf("%d",&idAuto);

            for(j=0;j<tama;j++)
            {
                flag=2;
                if(autoArray[j].idAuto==idAuto && autoArray[j].estado==1)
                {
                    if(autoArray[j].idPropietario==proArray[i].idPropietario)
                    {

                        horas=devolverHorasEstadia();
                        precioEstadia=(float)horas*miEst[0].precios[autoArray[j].idMarca];
                        miEst[0].recaudaciones[autoArray[j].idMarca]=precioEstadia+miEst[0].recaudaciones[autoArray[j].idMarca];
                        miEst[0].recaudacionTotal=(float)precioEstadia+miEst[0].recaudacionTotal;
                        autoArray[j].estado=0;
                        printf("Nombre propietario: %s\n  Patente: %s\n  Marca: %s\n  Precio por hora: %0.2f\n Horas estacionado: %d\n Precio Estadia: %0.2f\n",proArray[i].nombre,autoArray[j].patente,autoArray[j].marcaNombre,miEst[0].precios[autoArray[j].idMarca],horas,precioEstadia);
                    }

                }

            }

            }


    }

        if(flag==0)
        {
            printf("No se encontro el propietario.\n");
        }
        if(flag==2)
        {
            printf("No se encontro el id del auto.\n");
        }

        }else
        {
            printf("Error.\n");
        }
}


int darAltaAutoEstacionado(eAutos autoArray[],int tama,ePropietarios proArray[],int tamp)
{
    if(proArray!=NULL && tamp>0 && autoArray!=NULL && tama>0 )
    {
    int opcion;

    int id;
    int i;
    int indice;
    char marcaNombre[5][20]={"","Alfa romeo","Ferrari","audi","Otro"};

    indice =buscarLugarLibreAuto(autoArray,tama);
        if(indice >= 0)
        {

            id = devolverSiguienteIdAuto(autoArray,tama);

            autoArray[indice].idAuto=id;
            printf("Ingrese patente: ");
            fflush(stdin);
            gets(autoArray[indice].patente);
            printf("Ingrese marca: \n");
            printf("1.Alfa romeo \n2.Ferrari\n3.Audi\n4.Otro\n");
            printf("Opcion:");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case ALPHA_ROMEO:
                autoArray[indice].idMarca=ALPHA_ROMEO;
                strcpy(autoArray[indice].marcaNombre,marcaNombre[ALPHA_ROMEO]);


                break;
                case FERRARI:
                   autoArray[indice].idMarca=FERRARI;
                   strcpy(autoArray[indice].marcaNombre,marcaNombre[FERRARI]);

                break;
                case AUDI:
                    autoArray[indice].idMarca=AUDI;
                    strcpy(autoArray[indice].marcaNombre,marcaNombre[AUDI]);

                break;
                case OTRO:
                   autoArray[indice].idMarca=OTRO;
                   strcpy(autoArray[indice].marcaNombre,marcaNombre[OTRO]);

                break;
            }
            int idProp;
            mostrarPropietarios(proArray,tamp);
            printf("Ingrese id de propietario:");

            scanf("%d",&idProp);

                for(i=0;i<tamp;i++)
                {
                    if(proArray[i].idPropietario==idProp && proArray[i].estado==1)
                    {
                        autoArray[indice].idPropietario=idProp;
                        autoArray[indice].estado=1;

                        printf("Guardado con exito\n");break;
                    }else
                    {
                        printf("No se encontro el usuario.\n");break;
                    }




                }



        }
    }else
    {
        printf("Error.\n");
    }

        return 0;
    }

void mostrarAutos(eAutos autoArray[],int tama,ePropietarios proArray[],int tamp)
{
    if(proArray!=NULL && tamp>0 && autoArray!=NULL && tama>0)
    {
    int i,j;
    printf("Id auto |  Marca   |   Patente   |    Propietario   \n");
        for(i=0;i<tama;i++)
        {
            if(autoArray[i].estado==1)
            {

                for(j=0;j<tamp;j++)
                {
                    if(autoArray[i].idPropietario==proArray[j].idPropietario)
                    {
                    printf("%d  %15s   %10s  %10s  %s\n",autoArray[i].idAuto,autoArray[i].marcaNombre,autoArray[i].patente,proArray[j].nombre,proArray[j].apellido);
                    }
                }
            }
        }
    }else
    {
        printf("Error.\n");
    }
}



//validaciones



int validarString(char palabra[])
{
    int r,i;
    r=strlen(palabra);
    int retorno=1;
    for(i=0;i<=r;i++)
    {
       if(isdigit(palabra[i]))
    {
        retorno=0;
        break;
    }
    }

    return retorno;
}
