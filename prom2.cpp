// Programa que lee un archivo CSV para texto.
//Creado por Juan Sebastian Gomez Vera.
//Basado en programa de Cesar Aceros


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

using namespace std;
// creamos las variables en arreglos de punteros para almacenar el acumulador de suma y los promedios de las notas y las notas totales. 
// Las creamos con 6 espacios aunque soo necesitemos las ultimas 4, esto para hacerlo coincidir con el documento.
int n1, n2, n3, n4;
int *notas[6]= {0, 0, &n1, &n2, &n3, &n4};
double nt1=0, nt2=0, nt3=0, nt4=0;
double *notast[6]= {0, 0, &nt1, &nt2, &nt3, &nt4};
int s1=0, s2=0, s3=0, s4=0;
int *suma[6]={0, 0, &s1, &s2, &s3, &s4};
int num;
int numsalones;



double promedios_individuales(const char* archivocvv) //creamos una funcion prom.
{
	ifstream archivo(archivocvv); //leemos el archivo y lo almacenamos en una variable.
	string linea; //creamos un string "linea."
	vector<vector<string>> parsedCsv; //creamos un vector.
    int rowcount=0; 
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
    
    for (int i=0 ; i<rowcount ; i++){ //para cada variable i, va hasta rowcount y aumentamos en 1.
        std::string::size_type sz; //creamos un alias para el tamaño del string.
        int j=1; // tomamos esta columna para hacer un contador de alumnos por archivo.
        num = num + 1;// acumulador de numero de estudiantes.
        for ( j=2 ; j<colcount ; j++){//para cada variable j, va hasta colcount y aumentamos en 1.
            double valor = stod(parsedCsv[i][j],&sz);//convertimos ese string en una variabe double.
            *suma[j]= *suma[j] + valor;//la suma aumentará dependiendo del valor. 
            
        }
        
    }
    
    for ( int n=2 ; n<colcount ; n++){//para cada variable n, va hasta colcount y aumentamos en 1.
        *notas[n]= *suma[n]/num;//ese promedio será la suma antes definida, dividida por la cantidad de estudiantes..
    }

	archivo.close(); //cerramos el archivo.
    return 0 ;// regresamos las variables.

}

double calculo_promediot(){ //acumulador de promedios totales.

    for ( int g=2 ; g<6 ; g++){//para cada variable g, va hasta 6 que son las columnas y aumentamos en 1.
        *notast[g]= *notast[g]+*notas[g];
    }
    return 0;
}

double promediototal(const int salones){ //esta funcion, por ultimo, divide el valor de los promedios totales acumulados en 4.
    for ( int a=2 ; a<6 ; a++){//para cada variable a, va hasta 6 que son las columnas y aumentamos en 1.
        *notast[a]=*notast[a]/salones;
    }
   return 0;

}
double incrementoSalones (){//acumulador de cantidad de archivos, es decir, de salones.
    numsalones= numsalones + 1;
    return numsalones;
}

int main()
{

	promedios_individuales("Promedio5Estud.csv"); //llamamos a la funcion prom antes creada.
    cout << "El promedio #1 de las notas es: " << n1 << " " << n2 << " " << n3 << " " << n4 << endl;//imprimimos mensaje con los promedios por notas.
    calculo_promediot();
    incrementoSalones ();

    //hacemos llo mismo para cada archivo.

    promedios_individuales("Promedio10Estud.csv"); 
    cout << "El promedio #2 de las notas es: " << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    calculo_promediot();
    incrementoSalones ();

    promedios_individuales("Promedio15Estud.csv"); 
    cout << "El promedio #3 de las notas es: " << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    calculo_promediot();
    incrementoSalones ();

    promedios_individuales("Promedio20Estud.csv"); 
    cout << "El promedio #4 de las notas es: " << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    calculo_promediot();
    incrementoSalones ();

    promediototal(numsalones);
    cout << "El promedio total de las notas es: " << nt1 << " " << nt2 << " " << nt3 << " " << nt4 << endl;//imprimimos mensaje con el promedio total por notas.
	return 0;
}