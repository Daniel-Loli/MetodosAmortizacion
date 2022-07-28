#include <iostream>
#include <windows.h>
#include <locale.h>


using namespace std;

COORD coord = { 0, 0 };


//Funcion go to (x,y) para mover el lugar del cursor
void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void metodo_usa();


int main(){

    setlocale(LC_CTYPE, "Spanish");


    metodo_usa();

    system("pause");
    return 0;
}

void metodo_usa() {
    system("cls");

    //Titulo del metodo
    gotoxy(35, 1); printf("............................................\n");
    gotoxy(35, 2); printf(".            METODO AMERICANO              .\n");
    gotoxy(35, 3); printf("............................................\n");

    float a = 0; //cuota periodica de interÃ©s
    float a_ultima; //cuota del ultimo año; el Co mas los inetereses
    float tasa_usa; //tasa de interes del periodo
    float capital; //capital inicial prestado (Co)
    int tiempo; //tiempo en aÃ±o del prestamo
    int i; //contador para el bucle
    int dia, anio; string mes; //Fecha

    //Ingresando la fecha del prestamo
        cout << "En que fecha desea realizar el prestamo?\n";
        cout << "Dia: "; cin >> dia;
        cout << "Mes: "; cin >> mes;
        cout << "Anio: "; cin >> anio;
        cout << endl;

    //Ingrea y lee el monto a prestar (Co)
        cout << "[#] Ingresa el monto a prestar: ";
        cin >> capital;
    
    //Consistenciar por si el usuario coloca numero negativo
        if (capital < 0) {
            metodo_usa();
        }

    //tiempo en aÃ±os (recordar que el metodo funciona de esta manera, cuota anual)
        cout << "[#] En cuanto tiempo piensa pagarlo (en aÃ±os): ";
        cin >> tiempo;

    //tasa de interes del periodo anterior
        cout << "[#] CuÃ¡l serÃ¡ la tasa de interÃ©s?: ";
        cin >> tasa_usa;

    //Limpiando consola para el proceso de mostrado
        system("cls");

    //Titulo del metodo
        gotoxy(35, 1); printf("............................................\n");
        gotoxy(35, 2); printf(".            METODO AMERICANO              .\n");
        gotoxy(35, 3); printf("............................................\n");


    //Mostrado de datos iniciales del cliente
        gotoxy(80, 5);
        cout << dia << " de " << mes << " de " << anio << "\n\n";

        gotoxy(14, 7);
        cout << "Tabla del prestamo a pagar de S/. " << capital << " al " << tasa_usa << "% anual, durante " << tiempo << " anios.\n";

    //Mostrando tabla de cotizaciones
    	//Borde  - arriba (top)
		gotoxy(14, 8);
	    for (i = 0; i < 90; i++) {
	        cout << ".";
	    }
	    cout << "\n\n";
		
		//Menu de muestra
	    gotoxy(24, 10);
	    cout << "Anio" << "\t\t" << "Anualidad" << "\t\t" << "Interes" << "\t\t\t" << "Fecha de pago" << endl;
		
		//Borde - medio (middle)
	    gotoxy(14, 12);
	    for (i = 0; i < 90; i++) {
	        cout << ".";
	    }
	    cout << "\n\n";
		
		//Informacion sobre la amortizaciÃ³n
	    for (i = 0; i < tiempo - 1; i++) {
	        a = capital * tasa_usa/100;
	
	        gotoxy(25, 14 + i);
	        cout << i + 1 << "\t\t" << a << "\t\t\t" << a << "\t\t\t" << anio + i + 1 << endl;
	    }
	    
	    //Ãºltimo periodo de amortizaciÃ³n
	    a_ultima = a + capital;
	    gotoxy(25, 14 + tiempo - 1);
	    cout << i + 1 << "   \t\t" << a_ultima << "     \t\t" << a << "\t\t\t" << anio + i + 1 << endl;
		
		//Borde - abajo (bottom)
	    gotoxy(14, 14 + tiempo + 1);
	    for (i = 0; i < 90; i++) {
	        cout << ".";
	    }
	    cout << "\n\n";
}