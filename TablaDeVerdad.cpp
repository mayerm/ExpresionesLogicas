#include "TablaDeVerdad.h"

string TablaDeVerdad::getRtaTipoProposicion(vector<char> connectors){
	
	vector<bool> proposicionesRecorridas;
	for (int i = 0; i < connectors.size(); i++)
	{
		proposicionesRecorridas = getPropAnteriores(connectors[i], proposicionesRecorridas);
	}
	return getTipoProposicion(proposicionesRecorridas);	 
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

vector<bool> TablaDeVerdad::getPropAnteriores(char conector, vector<bool> propAnt){
	
	if (propAnt.empty())	
		propAnt = { true, true, false, false };	
	if (conector == '!')
	{
		for(int i = 0; i < propAnt.size(); i++)
		{
			propAnt[i] = !propAnt[i];
		}
		return propAnt;
	}
	for (int i = 0; i < propAnt.size(); i++)
	{
		switch (i){
		case 0:
		case 2:
			propAnt[i] = getValorDeVerdad(propAnt[i], true, conector);
			break;
		case 1:
		default:
			propAnt[i] = getValorDeVerdad(propAnt[i], false, conector);
			break;
		}
	}
	return  propAnt;
}



string TablaDeVerdad::getTipoProposicion(vector<bool> propFinal){
	int cantVerdaderos = 0;
	for (int i = 0; i < propFinal.size(); i++)
	{
		if (propFinal[i])
			cantVerdaderos++;
	}
	if (cantVerdaderos == 0)
		return "Contradiccion";
	else if (cantVerdaderos == 4)
		return "Tautologia";
		else
			return "Contingencia";
}

