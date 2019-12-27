#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>
using namespace std;

typedef int Clave;
typedef int Valor;

class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;
	void borrar(Clave k);
    vector<Clave> claves() const;
    bool operator==(Diccionario o) const;
    Diccionario operator||(Diccionario o) const;
    Diccionario operator&&(Diccionario o) const;

private:
    struct Asociacion {
        Asociacion(Clave k, Valor v);
        Clave clave;
        Valor valor;
    };

	vector<Asociacion> _diccionario;
};

//Funciones auxiliares
bool pertenece(vector<Clave> v, Clave k);
bool sinRepetidos(vector<Clave> v);
bool esPermutacion(vector<Clave> v1, vector<Clave> v2);

#endif /*__DICCIONARIO_H__*/
