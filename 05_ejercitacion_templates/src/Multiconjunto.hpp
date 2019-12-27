#include <vector>
#include "Diccionario.hpp"
#ifndef SOLUCION_MULTICONJUNTO_HPP
#define SOLUCION_MULTICONJUNTO_HPP
using namespace std;

template <class T>
class Multiconjunto {
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> otro) const;

private:
    Diccionario<T, int> _multiconjunto;
};

template <class T>
Multiconjunto<T>::Multiconjunto(){
}

template <class T>
void Multiconjunto<T>::agregar(T x){
    if (_multiconjunto.def(x)){
        _multiconjunto.definir(x, _multiconjunto.obtener(x)+1) ;
    } else {
        _multiconjunto.definir(x,1);
    }
}

template <class T>
int Multiconjunto<T>::ocurrencias(T x) const{
    if (_multiconjunto.def(x)){
        return _multiconjunto.obtener(x);
    } else {
        return 0;
    }
}

template <class T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) const{
    for (T x : _multiconjunto.claves()){
        if (ocurrencias(x) > otro.ocurrencias(x)){
            return false;
        }
    }
    return true;
}

#endif //SOLUCION_MULTICONJUNTO_HPP
