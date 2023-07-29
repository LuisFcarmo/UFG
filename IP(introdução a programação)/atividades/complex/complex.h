typedef struct
{
    double r, i;
}Complex;

Complex cp_new (double r, double i);
Complex cp_sum(Complex a, Complex b);
void cp_print(Complex c, int i);
Complex cp_mult(Complex a, Complex b);
Complex cp_div (Complex a, Complex b);
double tamanho (Complex a);
double angulo (Complex a);