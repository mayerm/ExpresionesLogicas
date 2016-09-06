#include "TablaDeVerdad.h"


bool TablaDeVerdad::estaNegado(bool value, bool negation){
	if (negation)
		return !value;
	else
		return value;
}

bool TablaDeVerdad::getValorDeVerdad(bool p, bool q, char conector){
	switch (conector){
		case '|'://OR
			if (p == false && q == false)
				return false;
			else
				return true;
		case '&'://AND
			if (p == true && q == true)
				return true;
			else
				return false;
		case '>'://THEN
			if (p == true && q == false)
				return false;
			else
				return true;
		case '<'://IF AND ONLY IF
			if (p == q)
				return true;
			else
				return false;
		default:
			break;
	}
}

template <size_t n>
void TablaDeVerdad::getTipoProposicion(array<bool, n> propFinal){
	int cantVerdaderos = 0;
	for (int i = 0; i < propFinal.size(); i++)
	{
		if (propFinal[i])
			cantVerdaderos++;
	}
	if (cantVerdaderos == 0)
		cout << "Contradiccion";
	else if (cantVerdaderos == propFinal.size())
		cout << "Tautologia";
	else
		cout << "Contingencia";
}

void TablaDeVerdad::getRtaTipoProposicion(array<char, 3> a, array<char, 2> b, array<bool, 3> c){
	if (a[0] == a[1] && a[1] == a[2])
	{
		array<bool, 2> finalResult = {
			TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
			TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1))
		};
		getTipoProposicion(finalResult);
	}
	else
	{
		if (a[0] == a[1]){

			array<bool, 4> finalResult = {
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1))
			};
			getTipoProposicion(finalResult);
		}
		else if (a[1] == a[2]){

			array<bool, 4> finalResult = {
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1))
			};
			getTipoProposicion(finalResult);
		}
		else if (a[0] == a[2]){
			array<bool, 4> finalResult = {
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1))
			};
			getTipoProposicion(finalResult);
		}
		else
		{
			array<bool, 8> finalResult = {
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(true, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(true, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(true, c.at(2)), b.at(1)),
				TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::getValorDeVerdad(TablaDeVerdad::estaNegado(false, c.at(0)), TablaDeVerdad::estaNegado(false, c.at(1)), b.at(0)), TablaDeVerdad::estaNegado(false, c.at(2)), b.at(1))
			};
			getTipoProposicion(finalResult);
		}

	}

}