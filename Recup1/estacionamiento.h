typedef struct
{
    float precios[5];
    float recaudaciones[5];
    float recaudacionTotal;


}estacionamiento;

void recaudacionPorMarca(estacionamiento miEst[]);
void cargarPrecios(estacionamiento []);
int devolverHorasEstadia();
void recaudacionTotal(estacionamiento []);
