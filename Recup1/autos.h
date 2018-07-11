
typedef struct
{
    char patente[20];
    int idMarca;
    char marcaNombre[20];
    int idPropietario;
    int estado;
    int idAuto;

}eAutos;







int devolverHorasEstadia();

void autosHardcode(eAutos autoArray[],int tama);
int buscarLugarLibreAuto(eAutos autoArray[],int tama);

int devolverSiguienteIdAuto(eAutos proAuto[],int tama);
void inicializarEstadoAutos(eAutos autoArray[],int tama);
