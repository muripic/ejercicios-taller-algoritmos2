#include "DiccHash.h"

/* Constructor sin parámetros de la clase */
template<class V>
DiccHash<V>::DiccHash() : _tabla(TAM_INICIAL), _tam(TAM_INICIAL), _cant_claves(0) {
}

/* Destructor */
template<class V>
DiccHash<V>::~DiccHash() {
    for (list<Asociacion> l : _tabla) {
        l.clear();
    }
    _tabla.clear();
}

/* Devuelve true si la clave está definida en el diccionario.
 * - clav : clave a buscar
 */
template<class V>
bool DiccHash<V>::definido(const string &clav) const {
    int pos = fn_hash(clav);
    if (!_tabla[pos].empty()) {
        for (Asociacion i : _tabla[pos]) {
            if (i.clave == clav) {
                return true;
            }

        }
    }
    return false;
}

/* Agrega una clave y su significado al Diccionario.
 * Si la clave a agregar ya se encuentra definida,
 * redefine su significado.
 * - clav : clave a agregar
 * - sig  : significado de la clave a agregar
 *
 * Nota de implementación:
 *
 * Si el factor de carga supera el valor de UMBRAL_FC, se debe
 * redimensionar la tabla al doble de tamaño.
 */

template<class V>
void DiccHash<V>::definir(const string &clav, const V &sig) {
    int pos = fn_hash(clav);
    if (definido(clav)) {
        for (Asociacion a : _tabla[pos]) {
            if (a.clave == clav) {
                a.valor = sig;
            }
        }
    } else {
        Asociacion ent;
        ent.clave = clav;
        ent.valor = sig;
        _tabla[pos].push_back(ent);
        _cant_claves++;
    }
    if (factorCarga() > UMBRAL_FC) {
        redimensionar();
    }
}

/* Pasos a seguir para redimensionar la tabla:
 * - Crear una tabla del doble de tamaño de la original.
 * - Insertar todas las claves de la tabla original en la tabla nueva.
 * - Liberar la memoria reservada para la tabla original.
 */

template<class V>
void DiccHash<V>::redimensionar() {
    _tam = _tam * 2;
    vector<list<Asociacion>> nueva(_tam);
    for (list<Asociacion> l : _tabla) {
        for (Asociacion entrada : l) {
            nueva[fn_hash(entrada.clave)].push_back(entrada);
        }
    }
    for (list<Asociacion> l : _tabla) { //Opcional: Valgrind no encuentra leaks aunque esta parte no esté
        l.clear();
    }
    _tabla = nueva;
}

/* Busca en el diccionario el significado de la clave clav.
 * - clav : clave a buscar
 * Devuelve el significado de clav.
 */
template<class V>
V &DiccHash<V>::significado(const string &clav) {
    int pos = fn_hash(clav);
    auto itr = _tabla[pos].begin();
    for (itr; itr != _tabla[pos].end(); ++itr){
        if (itr->clave == clav) {
            break;
        }
    }
    return itr->valor;
}

/* Borra la clave del diccionario
 * - clav : clave a borrar
 *
 * Precondición: clav está definida en el diccionario */
template<class V>
void DiccHash<V>::borrar(const string &clav) {
    int pos = fn_hash(clav);
    for (auto itr = _tabla[pos].begin(); itr != _tabla[pos].end(); itr++) {
        if (itr->clave == clav) {
            _tabla[pos].erase(itr);
            _cant_claves--;
            break;
        }
    }
}

/* Devuelve la cantidad de claves definidas en el diccionario. */
template<class V>
unsigned int DiccHash<V>::cantClaves() const {
    return _cant_claves;
}

/* Devuelve el conjunto de claves del diccionario. */
template<class V>
set<string> DiccHash<V>::claves() const {
    set<string> claves;
    for (int i = 0; i < _tabla.size(); i++) {
        for (Asociacion entrada : _tabla[i]) {
            claves.insert(entrada.clave);
        }
    }
    return claves;
}

/* SÓLO PARA TESTING
 *
 * Devuelve el factor de carga de la tabla de hash.
 * Factor de carga : cantidad de claves definidas / tamaño de la tabla.
 */
template<class V>
float DiccHash<V>::factorCarga() const {
    return _cant_claves / _tam;
}

/* SÓLO PARA TESTING
 * Devuelve la cantidad de colisiones que tiene el diccionario.
 *
 * Observación: si en una celda de la tabla conviven n elementos,
 * hay n * (n - 1) / 2 colisiones en esa celda.
 */
template<class V>
unsigned int DiccHash<V>::colisiones() const {
    unsigned int suma = 0;
    for (int i = 0; i < _tam; i++) {
        suma += _tabla[i].size() * (_tabla[i].size() - 1) / 2;
    }
    return suma;
}

/* Función de hash.
 * Recordar usar "hash = hash % _tam".
 * (El operador "%" calcula el resto en la división o "módulo").
 * Devuelve la posición de la tabla asociada a la clave dada.
 */


template<class V>
unsigned int DiccHash<V>::fn_hash(const string &str) const {
    int sum = 0;
    //Suma los números correspondientes a los caracteres según la codificación
    for (int i = 0; i < str.size(); i++) {
        sum = 971*sum + int(str[i]);
    }
    return sum % _tam;
}