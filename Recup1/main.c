#include <stdio.h>
#include <stdlib.h>
#include "propietario.h"
#include "autos.h"
#include "estacionamiento.h"
#include "funciones.h"
#define TAME 40
#define TAMP 20
#define TAMA 50

int main()
{
    int id;
    ePropietarios listaPropietarios[TAMP];
    eAutos listaAutos[TAMA];

    estacionamiento miEst[1];
    cargarPrecios(miEst);
    egresosHarcodeo(miEst);


    inicializarEstado(listaPropietarios,TAMP);
    inicializarEstadoAutos(listaAutos,TAMA);

    propietariosHardCode(listaPropietarios,TAMP);
    autosHardcode(listaAutos,TAMA);

    int opcion;

    while(1){

    mostrarMenu();


    printf("Ingrese una opcion: ");
    scanf(" %d",&opcion);



    switch(opcion)
    {
        case 1:
            darAltaPropietario(listaPropietarios,TAMP);
            system("pause");
            system("cls");

        break;
        case 2:
            modificarPropietario(listaPropietarios,TAMP);
            system("pause");
            system("cls");

        break;
        case 3:

            darBajaPropietario(listaPropietarios,TAMP,listaAutos,TAMA,miEst);
            system("pause");
            system("cls");
        break;
        case 4:
            darAltaAutoEstacionado(listaAutos,TAMA,listaPropietarios,TAMP);
            system("pause");
            system("cls");
        break;
        case 5:
            mostrarAutos(listaAutos,TAMA,listaPropietarios,TAMP);
            system("pause");
            system("cls");
        break;
        case 6:
            recaudacionTotal(miEst);
            system("pause");
            system("cls");
        break;
        case 7:
            recaudacionPorMarca(miEst);
            system("pause");
            system("cls");
        break;
        case 8:
            mostrarPropietarios(listaPropietarios,TAMP);
            system("pause");
            system("cls");
        break;
        case 9:
            mostrarPropietarios(listaPropietarios,TAMP);
            printf("Ingrese id: ");
            scanf(" %d",&id);
            mostrarDatosPorId(listaAutos,TAMA,listaPropietarios,TAMP,id);
            system("pause");
            system("cls");
        break;
        case 10:
            mostrarDatosDeAudi(listaAutos,TAMA,listaPropietarios,TAMP);
            system("pause");
            system("cls");
        break;
        case 11:
            mostrarAutosPorPatente(listaAutos,TAMA,listaPropietarios,TAMP);
            system("pause");
            system("cls");
        break;
        case 12:
            egresoDeAuto(listaAutos,TAMA,listaPropietarios,TAMP,miEst);
            system("pause");
            system("cls");
        break;
        case 13:
            mostrarPorEdad(listaPropietarios,TAMP);
            system("pause");
            system("cls");
            break;
        case 14:
            mostrarPropietariosAEleccion(listaPropietarios,TAMP);
            system("pause");
            system("cls");
            break;
        case 15:
            exit(1);
            break;

        default:
            printf("Ingrese una opcion correcta..\n");
            system("pause");
            system("cls");

        break;
    }
}



    return 0;
}
