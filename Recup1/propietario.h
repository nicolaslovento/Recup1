
typedef struct
{
    int idPropietario;
    char nombre[40];
    char apellido[40];
    char direccion[40];
    char numTarjeta[30];
    int estado;
    int edad;


}ePropietarios;



int devolverSiguienteId(ePropietarios proArray[],int tamp);
void modificarPropietario(ePropietarios proArray[],int tamp);
int darAltaPropietario(ePropietarios proArray[],int tamp);
void mostrarPropietarios(ePropietarios proArray[],int tamp);
void propietariosHardCode(ePropietarios proArray[],int tamp);
void inicializarEstado(ePropietarios proArray[],int tamp);
int devolverIndexLibre(ePropietarios proArray[],int tamp);
