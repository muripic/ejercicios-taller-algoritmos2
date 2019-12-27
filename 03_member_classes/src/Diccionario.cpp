#include "Diccionario.h"


Diccionario::Diccionario() {
    _diccionario = vector<Asociacion>();
}

void Diccionario::definir(Clave k, Valor v) {
    bool cambio = false;
    for (int i = 0; i < _diccionario.size(); i++) {
        if (_diccionario[i].clave == k) {
            _diccionario[i].valor = v;
            cambio = true;
            break;
        }
    }
    if (!cambio) {
        Asociacion entrada(k,v);
//        entrada.clave = k; //HACER EL CONSTRUCTOR Y CAMBIAR
//        entrada.valor = v;
        _diccionario.push_back(entrada);
    }
}

Diccionario::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v){
}

bool Diccionario::def(Clave k) const {
    bool res = false;
    for (Asociacion x:_diccionario) {
        if (x.clave == k) {
            res = true;
            break;
        }
    }
    return res;
}

Valor Diccionario::obtener(Clave k) const {
    Valor res = -1;
    for (Asociacion x:_diccionario) {
        if (x.clave == k) {
            res = x.valor;
        }
    }
    return res;
}


void Diccionario::borrar(Clave k) {
    for (int i = 0; i < _diccionario.size(); i++) {
        if (_diccionario[i].clave == k) {
            swap(_diccionario[i], _diccionario[_diccionario.size() - 1]);
            _diccionario.pop_back();
        }
    }
}

//EJERCICIO 6: Funciones auxiliares
bool pertenece(vector<Clave> v, Clave k) {
    bool res = false;
    for (Clave q : v) {
        if (q == k) {
            res = true;
            break;
        }
    }
    return res;
}

bool sinRepetidos(vector<Clave> v) {
    bool res = true;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 1; j < v.size(); j++) {
            if (j != i && v[i] == v[j]) {
                res = false;
                break;
            }
        }
    }
    return res;
}

bool esPermutacion(vector<Clave> v1, vector<Clave> v2) {
    bool res = true;
    if (v1.size() != v2.size()) {
        res = false;
    } else {
        bool v1env2 = true;
        for (int i : v1) {
            if (!pertenece(v2, i)) {
                v1env2 = false;
                break;
            }
        }
        bool v2env1 = true;
        for (int i : v2) {
            if (!pertenece(v1, i)) {
                v2env1 = false;
                break;
            }
        }
        res = v1env2 & v2env1;
    }
    return res;
}

//FIN Funciones auxiliares ejercicio 6-------------------------

vector<Clave> Diccionario::claves() const {
    vector<Clave> res;
    for (Asociacion entrada : _diccionario){
        res.push_back(entrada.clave);
    }
    return res;
}

bool Diccionario::operator==(Diccionario o) const{
    vector<Clave> claves1 = claves();
    vector<Clave> claves2 = o.claves();
    bool mismasClaves = esPermutacion(claves1, claves2);
    bool mismosValores = true;
    if (mismasClaves){
    for (int i = 0; i < _diccionario.size(); i++){
        if (_diccionario[i].valor != o.obtener(_diccionario[i].clave)){
            mismosValores = false;
            break;
        }
    }
    }
    return mismasClaves && mismosValores;
}

Diccionario Diccionario::operator||(Diccionario o) const{
    Diccionario res;
    for (int i = 0; i < _diccionario.size(); i++){
        res.definir(_diccionario[i].clave, _diccionario[i].valor);
    }
    for (Clave k : o.claves()){
        vector<Clave> clavesres = res.claves();
        if (!pertenece(res.claves(), k)){
            res.definir(k, o.obtener(k));
        }
    }
    return res;
}

Diccionario Diccionario::operator&&(Diccionario o) const{
    Diccionario res;
    for (int i = 0; i < _diccionario.size(); i++){
        if (pertenece(o.claves(),_diccionario[i].clave)){
        res.definir(_diccionario[i].clave, _diccionario[i].valor);
        }
    }
    return res;
}