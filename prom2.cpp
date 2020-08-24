// Programa que lee varios archivo CSV para texto.
//Creado por Juan Sebastian Gomez Vera.
//Basado en programa de Cesar Aceros


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

using namespace std;
double prom1 = 0;// creamos una variable para almacenar el promdeio1 con un valor nulo.
double prom2 = 0;// creamos una variable para almacenar el promdeio2 con un valor nulo.
double prom3 = 0;// creamos una variable para almacenar el promdeio3 con un valor nulo.
double prom4 = 0;// creamos una variable para almacenar el promdeio4 con un valor nulo.
double promt1 = 0;// creamos una variable para almacenar el promdeio total 1 con un valor nulo.
double promt2 = 0;// creamos una variable para almacenar el promdeio total 2 con un valor nulo.
double promt3 = 0;// creamos una variable para almacenar el promdeio total 3 con un valor nulo.
double promt4 = 0;// creamos una variable para almacenar el promdeio total 4 con un valor nulo.
int num = 0; //creamos una variable para la cantidad de estudiantes por archivo.
double promedios_individuales(const char* archivocvv) //creamos una funcion prom que recive una variable que almacena el archivo.
{
	ifstream archivo(archivocvv); //leemos el archivo y lo almacenamos en una variable.
	string linea; //creamos un string "linea."
	vector<vector<string>> parsedCsv; //creamos un vector.
    int rowcount=0; //Creamos dos contadores
    int colcount=0;
	while (getline (archivo, linea)) { //Leemos una lina del archivo
		stringstream l(linea); //almacenamos esa linea en una variable
		string celda; // creamos un string "Celda"
        vector<string> parsedRow; // creamos un vector.
        colcount=0; // le damos un valor inicial al contador.
		while(getline(l, celda, ',')) { //leemos la variable celda de la linea, separada por comas.
 			parsedRow.push_back(celda);//tomamos de la celda el dato.
            colcount++;//incrementamos colcount en 1.
		}
        rowcount++;//aumentamos rowcount en 1.
        parsedCsv.push_back(parsedRow);
	}
    int n1 = 0;//creamos una variable para almacenar la suma1.
    int n2 = 0;//creamos una variable para almacenar la suma2.
    int n3 = 0;//creamos una variable para almacenar la suma3.
    int n4 = 0;//creamos una variable para almacenar la suma4.
    for (int i=0 ; i<rowcount ; i++){ //para cada variable i, tomamos el rowcount y aumentamos en 1.
        std::string::size_type sz; //creamos un alias para el tamaño del string.
        int j=2; //j siempre inicialmente valdrá 2, esta es la columna que vamos a tomar. Contanto la primera columna como 0. Tenemos que tomar de la 2 a la 5.
        double valor1 = stod(parsedCsv[i][j],&sz); //convertimos ese string en una variabe double.
        n1= n1 + valor1;//la suma aumentará dependiendo del valor.
        j = 3;
        double valor2 = stod(parsedCsv[i][j],&sz);
        n2= n2 + valor2;//la suma aumentará dependiendo del valor.
        j = 4;
        double valor3 = stod(parsedCsv[i][j],&sz);
        n3= n3 + valor3;//la suma aumentará dependiendo del valor.
        j = 5;
        double valor4 = stod(parsedCsv[i][j],&sz);
        n4= n4 + valor4;//la suma aumentará dependiendo del valor.
        j=1; // tomamos esta columna para hacer un contador de alumnos por archivo.
        num=num+1;

    }
    
    prom1= n1/num;//ese promedio será la suma antes definida, dividida por la cantidad de datos.
    prom2= n2/num;//ese promedio será la suma antes definida, dividida por la cantidad de datos.
    prom3= n3/num;//ese promedio será la suma antes definida, dividida por la cantidad de datos.
    prom4= n4/num;//ese promedio será la suma antes definida, dividida por la cantidad de datos.
	archivo.close(); //cerramos el archivo.
    return prom1 and prom2 and prom3 and prom4;// regresamos las variables.

}

double volvernulo(){ //esta funcion se crea para volver nulas las variables y que no se mezclen las notas.
    prom1=0;
    prom2=0;
    prom3=0;
    prom4=0;
    num=0;
    return prom1 and prom2 and prom3 and prom4 and num;// regresamos las variables.
}

double calculo_promediot(){ //esta funcion nos acumulará los promedios en nuevas variables para no perder el valor antes de que se restablezca a 0.
    promt1=prom1+promt1;
    promt2=prom2+promt2;
    promt3=prom3+promt3;
    promt4=prom4+promt4;
    return promt1 and promt2 and promt3 and promt4;// regresamos las variables.
}

double promediototal(){ //esta funcion, por ultimo, divide el valor de los promedios acumulados en 4.
    promt1=promt1/4;
    promt2=promt2/4;
    promt3=promt3/4;
    promt4=promt4/4;
    return promt1 and promt2 and promt3 and promt4;// regresamos las variables.
}

int main()
{
	promedios_individuales("Promedio5Estud.csv"); //llamamos a la funcion prom antes creada ingresando el nombre del archivo a leer.
    cout << "El promedio #1 de las notas es: " << prom1 << " " << prom2 << " " << prom3 << " " << prom4 << endl; // imprimimos un mensaje con los promedios del primer archivo..
    calculo_promediot();
    volvernulo();
    promedios_individuales("Promedio10Estud.csv"); //llamamos a la funcion prom antes creada ingresando el nombre del archivo a leer.
    cout << "El promedio #2 de las notas es: " << prom1 << " " << prom2 << " " << prom3 << " " << prom4 << endl; // imprimimos un mensaje con los promedios del segundo archivo.
    calculo_promediot();
    volvernulo();
    promedios_individuales("Promedio15Estud.csv");//llamamos a la funcion prom antes creada ingresando el nombre del archivo a leer.
    cout << "El promedio #3 de las notas es: " << prom1 << " " << prom2 << " " << prom3 << " " << prom4 << endl; // imprimimos un mensaje con los promedios del tercer archivo..
    calculo_promediot();
    volvernulo();
    promedios_individuales("Promedio20Estud.csv"); //llamamos a la funcion prom antes creada ingresando el nombre del archivo a leer.
    cout << "El promedio #4 de las notas es: " << prom1 << " " << prom2 << " " << prom3 << " " << prom4 << endl; // imprimimos un mensaje con los promedios del ultimo archivo..
	calculo_promediot();
    volvernulo();
    promediototal();
    cout << "El promedio total de las notas es: " << promt1 << " " << promt2 << " " << promt3 << " " << promt4 << endl; // imprimimos un mensaje con los promedios totales.
}