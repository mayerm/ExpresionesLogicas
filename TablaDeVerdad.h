#include <vector>
#include <string>
using std::string;
using std::vector;


class TablaDeVerdad{
public:
	static string getRtaTipoProposicion(vector<char> connectors);
	static bool getValorDeVerdad(bool p, bool q, char connector);
	static vector<bool> getPropAnteriores(char conector, vector<bool> propAnt);
	static string getTipoProposicion(vector<bool> propFinal);
};