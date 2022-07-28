#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <iomanip>
#include <locale.h>
#include <windows.h>

using namespace std;

//Estructura de datos para el metodo de amortizacion frances
struct datosAmorFrances
{
    float numero_cuotas;
    float monto_credito;
    float interes;
    float amortizacion;
    float saldo;
    float cuota;
    float tasa;
}datos;

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Procedimiento que pide al usuario datos para luego mostrar en pantalla el resultado del metodo de amortizacion frances
void amortizacionFrances(){
    //Datos ingresados por el usuario
    cout << "Ha escogido utilizar el método frances" << endl;
	cout << "\nIngrese el monto del préstamo: ";cin >> datos.monto_credito;
	cout << "Ingrese el número de cuotas: ";cin >> datos.numero_cuotas;
	cout << "Ingrese la tasa de interés: ";cin >> datos.tasa;

    //Consistencia de los datos
    if(datos.monto_credito<0 or  datos.numero_cuotas<0 or datos.tasa<0 ){
        cout<<endl;
		cout<<"Uno o mas datos incorrectos, vuelva a intentarlo por favor: ";
		getch();
		system("cls");
		amortizacionFrances();
    }
	
    // Calculo de las amortizaciones año a año con sus respectivos intereses
	else{

		datos.saldo = datos.monto_credito;
		datos.tasa = datos.tasa/ 100;
        datos.cuota = (datos.monto_credito * (pow((1 + datos.tasa), datos.numero_cuotas)) * datos.tasa) / ((pow((1 + datos.tasa),datos.numero_cuotas) - 1));
        // tabular para acomodar las impresiones
		cout << "\n\t\t\t\tTabla de amortizaciones según el método frances:" << endl;
		cout << "\n\t\t\t\tLa cuota fija es de: " << datos.cuota << endl;
		cout << "\t\t\t\t............................................................\n";
	    cout << "\t\t\t\t  N      CUOTA      INTERÉS      AMORTIZACIÓN      SALDO\n";
		cout << "\t\t\t\t.................  ...........................................\n";
        cout <<"\t\t\t\t "<<" 0"<< "     "<<"  ----"<< "       "<<"  ----"<<"        "<<"  ----"<<"         "<<datos.saldo<<endl;
		for (int i = 0; i < datos.numero_cuotas;i++){
            //usar gotoxy para mover el cursor a la posicion (x,y) para mover toda la tabla al centro
            gotoxy(35,i+15);
            datos.interes = datos.saldo * datos.tasa;
            datos.amortizacion = datos.cuota - datos.interes;
            datos.saldo = datos.saldo - datos.amortizacion;
            cout <<"  "<<i+1 << "      " <<fixed<<setprecision(2) << datos.cuota << "      "    <<fixed<<setprecision(2)<< datos.interes << "       " << fixed<<setprecision(2)<<
            datos.amortizacion << "        " << fixed<<setprecision(2)<<datos.saldo << endl;
		}
    
        cout<<"Presione una tecla para regresar: "<<endl;
        getch();
        system("cls");
        amortizacionFrances();
    }
}
//hacer una funcion que use gotoxy para poner el cursor en la posicion que se le pase como parametro

int main() {
	//uso de la siguiente funcion para poder utilizar todas las letras del abecedario en español
    setlocale(LC_CTYPE,"Spanish");
    amortizacionFrances();
    return 0;
}