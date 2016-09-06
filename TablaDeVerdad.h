#include <array>
#include <iostream>
using namespace std;

#ifndef TablaDeVerdad
#define TablaDeVerdad
void getRtaTipoProposicion(array<char, 3> a, array<char, 2> b, array<bool, 3> c);
bool getValorDeVerdad(bool p, bool q, char connector);
template <size_t n>
void getTipoProposicion(array<bool, n> propFinal);
bool estaNegado(bool value, bool negation);
#endif