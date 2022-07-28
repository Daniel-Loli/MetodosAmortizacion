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

void amortizacionAleman() {
 	//variables previas
 float nCuotas;
 float prestamo, tasa;	
 
 //variables que usaremos para operar
 float cuota, interes, amortizacion, saldo;   
//Cout escribe lo que aparece en el programa y cin los almacena
 cout << "  Calculo de amortizaciones usando el metodo aleman" << endl;
		  cout << "\n  Digite el monto del prestamo: ";
		  cin >> prestamo;
		  cout << "  Ingrese la cantidad de cuotas: ";
		  cin >> nCuotas;
		  cout << "  Ingrese la tasa (interes): ";
		  cin >> tasa;
		  
		  //Consistenciar
		  if(prestamo<0 or  nCuotas<0 or tasa<0 )
		  {  cout<<endl;
		      cout<<"  Ha ocurrido un error al ingresar los valores, presione cualquier tecla para volver a ingresar: ";
		    getch();
		    system("cls");
		    amortizacionAleman();
	   }
	//---------------------------------------------------------------------------------------------
	
	
	//Calculos
else 	{	  
	saldo = prestamo;
	tasa = tasa / 100;
	amortizacion=saldo/nCuotas;
	 cout << "\n  Metodo De Amortizacion Aleman:" << endl; //Nobre del metodo de amortización
		  cout << "\n  Capital amortizado: " <<amortizacion << endl;
		  //Titulo de la tabla
		  cout << "--------------------------------------------------------------\n";
		  cout << "  PERIODO      CUOTA      INTERES    AMORTIZACION      SALDO\n";
		  cout << "--------------------------------------------------------------\n";
		  //Contenido de la tabla
          cout <<" "<<"   0"<< "     "<<"     ----"<< "       "<<"  ----"<<"        "<<"  ----"<<"         "<<saldo<<endl; 	
		  //Calculo de lo que está adentro de la tabla
		  for (int i = 0; i < nCuotas;i++) {
		    interes = saldo * tasa; 
		    cuota = interes + amortizacion;
		    saldo = saldo - amortizacion;
		    //Muestra en el programa los resultados
    cout <<"    "<<i+1 << "         " <<fixed<<setprecision(2) << cuota << "      "    <<fixed<<setprecision(2)<< interes << "       " << fixed<<setprecision(2)<<
	 amortizacion << "        " << fixed<<setprecision(2)<<saldo << endl;
		     }
         getch();
	  		
		
}
}
int main() {
    amortizacionAleman();
    return 0;
}