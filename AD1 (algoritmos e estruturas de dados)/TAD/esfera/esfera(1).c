#include "esfera.h"
#include "stdlib.h"
#define pi 3.1415
sphere *New_sphere (double raio) {
    sphere *esfera = NULL;
    esfera = (sphere*) malloc(sizeof(sphere)*1);
    return esfera;
};

void Destrow_sphere (sphere **reference) {
    sphere *ref_esfera;
    ref_esfera = *reference;
    free(ref_esfera);
    *reference = NULL;
};

double Get_volume (sphere *esfera) {
    double volume = 0;
    double r = esfera->raio;
    r = r * r * r;
    volume = (double) (4/3*pi)*r;
};

double Get_Area (sphere *esfera) {
    double area = 0;
    double raio = esfera->raio;
    raio = raio*raio;
    area = (4*pi)*raio;
};