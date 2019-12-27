#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

//Ejercicio 1
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor &c) {
    typename Contenedor::const_iterator min = c.begin();
    for (typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it) {
        if (*it < *min) {
            min = it;
        }
    }
    return *min;
}

//Ejercicio 2
template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor &c) {
    typename Contenedor::value_type suma = 0;
    int length = 0;
    for (typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it) {
        suma = suma + *it;
        length++;
    }
    return suma / length;
}

//Ejercicio 3

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator &desde, const Iterator &hasta) {
    Iterator min = desde;
    for (Iterator it = desde; it != hasta; ++it) {
        if (*it < *min) {
            min = it;
        }
    }
    return *min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator &desde, const Iterator &hasta) {
    typename Iterator::value_type suma = 0;
    int length = 0;
    for (auto it = desde; it != hasta; ++it) {
        suma = suma + *it;
        length++;
    }
    return suma / length;
}

//Ejercicio 4

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type &elem) {
    for (typename Contenedor::iterator it = c.begin(); it != c.end(); ++it) {
        if (elem == *it) {
            c.erase(it--);
        }
    }
}

//Ejercicio 5
template<class Contenedor>
bool ordenado(Contenedor &c) {
    bool res = true;
    typename Contenedor::const_iterator mayor = c.begin();
    mayor++;
    for (typename Contenedor::const_iterator menor = c.begin(); mayor != c.end(); ++menor) {
        if (*menor > *mayor) {
            res = false;
            break;
        }
        ++mayor;
    }
    return res;
}

//Ejercicio 6
template<class Contenedor>
pair<Contenedor, Contenedor> split(const Contenedor &c, const typename Contenedor::value_type &elem) {
    Contenedor prim;
    Contenedor seg;
    for (typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it) {
        if (*it < elem) {
            prim.insert(prim.end(), *it);
        } else {
            seg.insert(seg.end(), *it);
        }
    }
    pair<Contenedor, Contenedor> res = make_pair(prim, seg);
    return res;
}

//Ejercicio 7
template<class Contenedor>
void merge(const Contenedor &c1, const Contenedor &c2, Contenedor &res) {
    typename Contenedor::const_iterator itc1 = c1.begin();
    typename Contenedor::const_iterator itc2 = c2.begin();
    while (itc1 != c1.end() and itc2 != c2.end()) {
        if (*itc1 <= *itc2) {
            res.insert(res.end(), *itc1);
            itc1++;
        } else {
            res.insert(res.end(), *itc2);
            itc2++;
        }
    }
    if (itc1 == c1.end() and itc2 != c2.end()) {
        while (itc2 != c2.end()) {
            res.insert(res.end(), *itc2);
            itc2++;
        }
    } else {
        while (itc1 != c1.end()) {
            res.insert(res.end(), *itc1);
            itc1++;
        }
    }
}

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
