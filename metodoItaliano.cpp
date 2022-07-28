//librerias
#include<iostream>
#include<string>
#include<conio.h>
#include <windows.h>
#include<locale.h>
using namespace std;

//procedimeinto para el gotoxy
COORD coord={0,0};
void gotoxy(int x, int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void italiano();

//programa principal
int main(){
	setlocale(LC_CTYPE,"Spanish");
	italiano();
	getch();
	return 0;
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
}