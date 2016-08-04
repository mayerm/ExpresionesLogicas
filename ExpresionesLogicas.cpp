// ExpresionesLogicas.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <string>
#include "TablaDeVerdad.h";
using std::cin;
using std::cout;

int main()
{
	cout << "Ingrese la cantidad de conectores que desee agregar\n";
	int cantConectores;
	cin >> cantConectores;
	vector<char> conectores(cantConectores);
	string mensaje = "Ingrese los conectores que desee agregar en orden.\n!: Negacion\n|: Disyuncion\n&: Conjuncion\n>: Condicional\n<: Bicondicional\n";
	cout << mensaje;
	char aux;
	int eol = 0;
	for (int i = 0; i < cantConectores; i++){
		cin >> aux;
		if (aux == '|' || aux == '&' || aux == '>' || aux == '<' || aux == '!')
		{
			eol = 0;
			conectores[i] = aux;
		}
		else{
			cout << "\nDebe ingresar un caracter valido.\n" << mensaje;
			i--;
			eol++;
			if (eol == 3)
			{
				cout << "\nDemasiados intentos fallidos. Programa terminado.";
				return 0;
			}
		}
	}
	cout << TablaDeVerdad::getRtaTipoProposicion(conectores);
	return 0;
}

