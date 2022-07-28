#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <math.h>

using namespace std;

/*Metodo de amortización Frances*/
void metodoFrances(double p, double i, double t, double &a, double &b, double &c)
{
    a = i/(1-pow((1+i),-t));
    b = a * (pow(1 + i, t));
    c = p - b;
}
//pedir datos
void pedirDatos(double &p, double &i, double &t)
{
    cout << "Ingrese el valor del prestamo: ";
    cin >> p;
    cout << "Ingrese el valor de la tasa de interes: ";
    cin >> i;
    cout << "Ingrese el valor del plazo: ";
    cin >> t;
}
//mostrar datos
void mostrarDatos(double a, double b, double c)
{
    cout << "El valor de la cuota mensual es: " << a << endl;
    cout << "El valor del interes mensual es: " << b << endl;
    cout << "El valor de la cuota total es: " << c << endl;
}
//main
int main()
{
    double p, i, t, a, b, c;
    pedirDatos(p, i, t);
    metodoFrances(p, i, t, a, b, c);
    mostrarDatos(a, b, c);
    return 0;
}
