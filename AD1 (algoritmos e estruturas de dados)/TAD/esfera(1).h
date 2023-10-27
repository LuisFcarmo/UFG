
typedef struct {
    double raio;

} sphere;

sphere *New_sphere (double raio);
void Destrow_sphere (sphere **reference);
double Get_volume (sphere *esfera);
double Get_Area (sphere *esfera);