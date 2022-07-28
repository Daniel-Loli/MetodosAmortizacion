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
        
    }
}
//Procedimiento que pide al usuario datos para luego mostrar en pantalla el resultado del metodo de amortizacion americano
void metodo_usa() {
    system("cls");

    //Titulo del metodo
    gotoxy(35, 1); printf("............................................\n");
    gotoxy(35, 2); printf(".            MÉTODO AMERICANO              .\n");
    gotoxy(35, 3); printf("............................................\n");

    float a = 0; //cuota periodica de interés
    float a_ultima; //cuota del ultimo año; el Co mas los inetereses
    float tasa_usa; //tasa de interes del periodo
    float capital; //capital inicial prestado (Co)
    int tiempo; //tiempo en años del prestamo
    int i; //contador para el bucle
    int dia, anio; string mes; //Fecha

    //Ingresando la fecha del prestamo
        cout << "En que fecha desea realizar el prestamo?\n";
        cout << "Dia: "; cin >> dia;
        cout << "Mes: "; cin >> mes;
        cout << "año: "; cin >> anio;
        cout << endl;

    //Ingrea y lee el monto a prestar (Co)
        cout << "[#] Ingresa el monto a prestar: ";
        cin >> capital;
    
    //Consistenciar por si el usuario coloca numero negativo
        if (capital < 0) {
            metodo_usa();
        }

    //tiempo en años (recordar que el metodo funciona de esta manera, cuota anual)
        cout << "[#] En cuanto tiempo piensa pagarlo (en años): ";
        cin >> tiempo;

    //tasa de interes del periodo anterior
        cout << "[#] Cuál será la tasa de interés?: ";
        cin >> tasa_usa;

    //Limpiando consola para el proceso de mostrado
        system("cls");

    //Titulo del metodo
        gotoxy(35, 1); printf("............................................\n");
        gotoxy(35, 2); printf(".            MÉTODO AMERICANO              .\n");
        gotoxy(35, 3); printf("............................................\n");


    //Mostrado de datos iniciales del cliente
        gotoxy(80, 5);
        cout << dia << " de " << mes << " de " << anio << "\n\n";

        gotoxy(14, 7);
        cout << "Tabla del préstamo a pagar de S/. " << capital << " al " << tasa_usa << "% anual, durante " << tiempo << " años.\n";

    //Mostrando tabla de cotizaciones
    	//Borde  - arriba (top)
		gotoxy(14, 8);
	    for (i = 0; i < 90; i++) {
	        cout << ".";
	    }
	    cout << "\n\n";
		
		//Menu de muestra
	    gotoxy(24, 10);
	    cout << "Año" << "\t\t" << "Anualidad" << "\t\t" << "Interés" << "\t\t" << "Fecha de pago" << endl;
		
		//Borde - medio (middle)
	    gotoxy(14, 12);
	    for (i = 0; i < 90; i++) {
	        cout << ".";
	    }
	    cout << "\n\n";
		
		//Informacion sobre la amortización
	    for (i = 0; i < tiempo - 1; i++) {
	        a = capital * tasa_usa/100;
	
	        gotoxy(25, 14 + i);
	        cout << i + 1 << "\t\t" << a << "\t\t\t" << a << "\t\t" << dia << " de " << mes << " de " << anio + i + 1 << endl;
	    }
	    
	    //Último periodo de amortización
	    a_ultima = a + capital;
	    gotoxy(25, 14 + tiempo - 1);
	    cout << i + 1 << "   \t\t" << a_ultima << "     \t\t" << a << "\t\t" << dia << " de " << mes << " de " << anio + i + 1 << endl;
		
		//Borde - abajo (bottom)
	    gotoxy(14, 14 + tiempo + 1);
	    for (i = 0; i < 90; i++) {
	        cout << ".";
	    }
	    cout << "\n\n";
        getch();
        system("cls");
}


//procedimeinto del metodo italiano
void italiano(){
	system("cls");
	
	//variables 1
	float prestamo,taza_int,amort;
	int n,i,cap,mon;
	string tipo, moneda; 
	//n=periodo, i=contador, cap=variable de contador
	//titulo
	cout<<"                         ***************************************"<<endl;
	cout<<"                         *   METODO DE AMORTIZACIÓN ITALIANO   *"<<endl;
	cout<<"                         ***************************************"<<endl;
	//elige la moneda
	cout<<" - Elija el tipo de moneda: \n";
	cout<<"    - (1) Soles\n"; //mon=1
	cout<<"    - (2) Dolares\n";    //mon=2
	cout<<"    - (3) Libra esterlinas\n";   //mon=4
	cout<<"   > ";cin>>mon;
	if(mon<0 || mon>3){
		italiano();
	}
	switch(mon){
		case 1:
			moneda="S/. ";
			break;
		case 2:
			moneda="$ ";
			break;
		case 3:
			moneda="£ ";
			break;
	}
	cout<<endl;
	
	//leer el prestamo
	cout<<" - Escriba el monto a prestarse: \n";
	cout<<"   > ";cin>>prestamo;
	//consistenciar
	if(prestamo<0){
		italiano();
	}
	cout<<endl;
	
	//años
	cout<<" - Escriba el tiempo del prestamo en años:\n";//n/12
	cout<<"   > ";cin>>n;
	//consistenciar
	if(n<0){
		italiano();
	}
	cout<<endl;
	
	//la capitalizacion
	cout<<" - Elija el tipo capitalización: \n";
	cout<<"    - (1) Anual\n"; //cap=1
	cout<<"    - (2) Semestral\n";    //cap=2
	cout<<"    - (3) Cuatrimestral\n";//cap=3
	cout<<"    - (4) trimestral\n";   //cap=4
	cout<<"    - (5) Bimestral\n";    //cap=6
	cout<<"    - (6) Mensual\n";      //cap=12
	cout<<"    - (7) Quincenal\n";    //cap=24
	cout<<"   > ";cin>>cap;
	if(cap<0 || cap>7){
		italiano();
	}
	switch(cap){
		case 1:
			n=n*1;
			tipo="Anual";
			break;
		case 2:
			n=n*2;
			tipo="Semestral";
			break;
		case 3:
			n=n*3;
			tipo="Cuatrimestral";
			break;
		case 4:
			n=n*4;
			tipo="Trimestral";
			break;
		case 5:
			n=n*6;
			tipo="Bimestral";
			break;
		case 6:
			n=n*12;
			tipo="Mensual";
			break;
		case 7:
			n=n*24;
			tipo="Quincenal";
			break;
	}
	cout<<endl;
	
	//tipo de interes
	cout<<" - Escriba el taza de interés "<<tipo<<": "<<endl;
	cout<<"   > ";cin>>taza_int;
	if(n<0){
		italiano();
	}
	
	//taza de interes en decimal - ejemplo 4% = 0.04
	taza_int=taza_int/100;
	
	//vectores de la tabla
	float a[10]; //cuota a pagar  
	float in[10]; //interes      
	float A[10]; //cuota de amortizacion  
	float M[10]; //capital amortizado     
	float C[10]; //capital pendiente	  
	a[0]=0;in[0]=0;A[0]=0;M[0]=0,C[0]=prestamo;
	
	//hallar la amortizacion
	amort=prestamo/n;
	for(i=1;i<=n;i++){
		A[i]=amort;   //2500
	}
	
	for(i=1;i<=n;i++){
		
		//interes
		in[i]=taza_int*C[i-1];
		
		//cuota a pagar
		a[i]=in[i]+A[i];
		
		//capital amortizado
		M[i]=M[i-1]+A[i];

		//capital pendiente
		C[i]=C[i-1]- A[i];

	}
	
	//RESULTADOS
	system("cls");
	//titulo
	cout<<"                         ***************************************"<<endl;
	cout<<"                         *   METODO DE AMORTIZACIÓN ITALIANO   *"<<endl;
	cout<<"                         ***************************************"<<endl;
	
	//datos de la amortizacion
	cout<<"  - DATOS"<<endl;
	cout<<"    - PRESTAMO: "<<moneda<<prestamo<<endl;
	cout<<"    - PERIODOS: "<<n<<endl;
	cout<<"    - TAZA DE INTERÉS: "<<taza_int*100<<"% "<<tipo<<endl<<endl;
	
	//adorno con gotoxy
	for(i=4;i<=89;i++){
		gotoxy(i,10);
		cout<<"*";
	}
	
	//titulo de la tabla
	gotoxy(37,11);cout<<"TABLA DE AMORTIZACIÓN";
	
	//adorno con gotoxy
	for(i=4;i<=89;i++){
		gotoxy(i,12);
		cout<<"*";
	}
	
	//nombres de la tabla
	string nombres1[6]={"periodos","cuota a","interés","cuota de","capital","capital"};
	string nombres2[6]={tipo,"pagar"," ","amortizacion","amortizado","pendiente"};
	//variable
	int r;
	
	//mostrar en la tabla lso nombres
	r=4;
	for(i=0;i<6;i++){
		gotoxy(r,13);
		cout<<nombres1[i];
		r +=15;
	}
	r=4;
	for(i=0;i<6;i++){
		gotoxy(r,14);
		cout<<nombres2[i];
		r +=15;
	}
	
	
	//adorno con gotoxy
	for(i=4;i<=89;i++){
		gotoxy(i,15);
		cout<<"*";
	}
	 
	//variable
	int m;
	// mostrar en tabla
	m=16;
	for(i=0;i<=n;i++){
		gotoxy(4,m);
		cout<<i; //periodo
		m+=2;
	}
	m=16;
	for(i=0;i<=n;i++){
		gotoxy(19,m);
		cout<<moneda<<a[i]; //cuota a pagar 
		m+=2;
	}
	m=16;
	for(i=0;i<=n;i++){
		gotoxy(34,m);
		cout<<moneda<<in[i]; //interes  
		m+=2;
	}
	m=16;
	for(i=0;i<=n;i++){
		gotoxy(49,m);
		cout<<moneda<<A[i]; //cuota de amortizacion 
		m+=2;
	}
	m=16;
	for(i=0;i<=n;i++){
		gotoxy(64,m);
		cout<<moneda<<M[i]; //capital amortizado  
		m+=2;
	}
	m=16;
	for(i=0;i<=n;i++){
		gotoxy(79,m);
		cout<<moneda<<C[i]; //capital pendiente
		m+=2;
	}
	
	//adorno con gotoxy
	for(i=4;i<=89;i++){
		gotoxy(i,16+((n+1)*2));
		cout<<"*";
	}
	
	//totales
	//suma de cuota 
	float suma1=0,suma2=0;
	for(i=0;i<=n;i++){
		suma1=suma1 + a[i];
	}
	for(i=0;i<=n;i++){
		suma2=suma2 + in[i];
	}
	gotoxy(4,17+((n+1)*2));cout<<"TOTAL";
	gotoxy(19,17+((n+1)*2));cout<<moneda<<suma1;
	gotoxy(34,17+((n+1)*2));cout<<moneda<<suma2;
	gotoxy(49,17+((n+1)*2));cout<<moneda<<prestamo;
	
	//adorno de gotoxy
	for(i=4;i<=89;i++){
		gotoxy(i,18+((n+1)*2));
		cout<<"*";
	}
	gotoxy(4,20+((n+1)*2));
    cout<<" > Presione una tecla para regresar: ";
    getch();
    system("cls");
    
}

// procedimiento para el metodo aleman
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
	gotoxy(20,5);
	 cout << "\n  Metodo De Amortizacion Aleman:" << endl; //Nombre del metodo de amortización
		  cout << "\n  Capital amortizado: " <<amortizacion << endl;
		  //Titulo de la tabla
		  cout << "--------------------------------------------------------------\n";
		  cout << "  PERIODO     CUOTA     INTERES    AMORTIZACION    SALDO\n";
		  cout << "--------------------------------------------------------------\n";
		  //Contenido de la tabla
          cout <<" "<<"   0"<< "     "<<"   ----"<< "       "<<"----"<<"        "<<"  ----"<<"        "<<saldo<<endl; 	
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

//Función Principal
int main(){
    setlocale(LC_CTYPE,"Spanish");
    system("color f1");
    int opcion;
    do{
        system("cls");
        cout<<"\n\n\n\n\n                                   ***************************************"<<endl;
        cout<<"                                   *   MÉTODOS DE AMORTIZACIÓN DE DEUDAS *"<<endl;
        cout<<"                                   ***************************************"<<endl;
        cout<<"                                   *                                     *"<<endl;
        cout<<"                                   *  1. Utilizar el método frances      *"<<endl;
        cout<<"                                   *  2. Utilizar el método italiano     *"<<endl;
        cout<<"                                   *  3. Utilizar el método aleman       *"<<endl;
        cout<<"                                   *  4. Utilizar el metodo americano    *"<<endl;
        cout<<"                                   *                                     *"<<endl;
        cout<<"                                   *  0. Salir                           *"<<endl;
        cout<<"                                   *                                     *"<<endl;
        cout<<"                                   ***************************************"<<endl;
        cout<<"                                   *                                     *"<<endl;
        cout<<"                                   *  Seleccione una opción:             *"<<endl;
        cout<<"                                   *                                     *"<<endl;
        cout<<"                                   ***************************************"<<endl;
        gotoxy(61,18);
		cin>>opcion;
        switch(opcion){
            case 1:
                system("cls");
                system("color f1");
                amortizacionFrances();
                break;
            case 2:
                system("cls");
                system("color f1");
                italiano();
                break;
            case 3:
                system("cls");
                system("color f1");
                amortizacionAleman();
                break;
            case 4:
                system("cls");
                system("color f1");
                metodo_usa();
                break;
            case 0:
                system("cls");
                system("color f1");
                cout<<"                         ***************************************"<<endl;
                cout<<"                         *                                     *"<<endl;
                cout<<"                         *  Gracias por utilizar el programa   *"<<endl;
                cout<<"                         *                                     *"<<endl;
                cout<<"                         ***************************************"<<endl;
                break;
            default:
                system("cls");
                cout<<"                         ***************************************"<<endl;
                cout<<"                         *                                     *"<<endl;
                cout<<"                         *  Opcion no valida                     *"<<endl;
                cout<<"                         *                                     *"<<endl;
                cout<<"                         ***************************************"<<endl;
                break;

        }
    }while(opcion!=0);
    getch();
    return 0;
}