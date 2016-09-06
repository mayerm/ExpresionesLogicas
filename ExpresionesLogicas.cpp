// ExpresionesLogicas.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <array>
#include "TablaDeVerdad.h"

int main()
{
	array<char, 3> preposiciones;
	array<char, 2> conectores;
	array<bool, 3> negado = { false, false, false };
	bool flag;
	for (int i = 0; i < preposiciones.size(); i++){
		cin >> preposiciones.at(i);
		if (conectores.size() != i)
		{
			do
			{
				flag = false;
				int eol = 0;
				char aux;
				cin >> aux;
				if (aux == '|' || aux == '&' || aux == '>' || aux == '<')
				{
					eol = 0;
					conectores.at(i) = aux;
				}
				else{
					flag = true;
					if (aux == '!')
					{
						eol = 0;
						negado.at(i) = true;
					}
					else
					{						
						cout << "\nDebe ingresar un caracter valido.\n" << "Ingrese los conectores que desee agregar en orden.\n!: Negacion\n|: Disyuncion\n&: Conjuncion\n>: Condicional\n<: Bicondicional\n";
						eol++;
						if (eol == 3)
						{
							cout << "\nDemasiados intentos fallidos. Programa terminado.";
							return 0;
						}
					}
				}
				
			} while (flag);
		}		
		else
		{
			char ultimoNegado;
			cin >> ultimoNegado;
			if (ultimoNegado == '!')
				negado.at(i) = true;
		}
	}
	TablaDeVerdad::getRtaTipoProposicion(preposiciones, conectores, negado);
}

