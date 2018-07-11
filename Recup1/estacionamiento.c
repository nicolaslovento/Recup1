#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "estacionamiento.h"




void cargarPrecios(estacionamiento miEst[])
{
    //cargo precios.
    miEst[0].precios[0]=0;
    miEst[0].precios[1]=150;//alfa romeo
    miEst[0].precios[2]=175;//ferrari
    miEst[0].precios[3]=200;//audi
    miEst[0].precios[4]=250;//Otro
    miEst[0].recaudaciones[0]=0;
    miEst[0].recaudaciones[1]=0;
    miEst[0].recaudaciones[2]=0;
    miEst[0].recaudaciones[3]=0;
    miEst[0].recaudaciones[4]=0;
    miEst[0].recaudacionTotal=0;

}

void recaudacionPorMarca(estacionamiento miEst[])
{
    printf("Recaudaciones: \n");
    printf("Alfa Romeo: $%0.2f\n",miEst[0].recaudaciones[1]);
    printf("Ferrari: $%0.2f \n",miEst[0].recaudaciones[2]);
    printf("Audi: $%0.2f \n",miEst[0].recaudaciones[3]);
    printf("Otras marcas: $%0.2f \n",miEst[0].recaudaciones[4]);

  }

void recaudacionTotal(estacionamiento miEst[])
{


    printf("La recaudacion total es : $%0.2f \n",miEst[0].recaudacionTotal);



}


int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%12);

    return horas ;

}
