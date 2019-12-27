#ifndef SOLUCION_TEMPLATES_HPP
#define SOLUCION_TEMPLATES_HPP
using namespace std;

//Ejercicio 1
template <class N>
N cuadrado(N x) {
    return x * x;
}

//Ejercicio 2
template <class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

//Ejercicio 3
template <class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    if (a.size() >= b.size()) {
        return false;
    } else {
        for (int i = 0; i < a.size(); i++){
            if (a[i] != b[i]){
                return false;
            };
        }
    }
    return true;
}

//Ejercicio 4
template <class Contenedor, class Elem>
Elem maximo(Contenedor c){
    Elem res = c[0];
    for (int i = 1; i < c.size(); i++){
        if (c[i] > res){
            res = c[i];
        }
    }
    return res;
}

//Ejercicio 8
template<class Elem>
vector<Elem> selectionSort(vector <Elem> v) {
    vector <Elem> res;
    while (!v.empty()) {
        //Buscar el minimo
        Elem minimo = v[0];
        int posminimo = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < minimo) {
                minimo = v[i];
                posminimo = i;
            }
        }
        //Agregar el mínimo a res y borrarlo de v
        res.push_back(minimo);
        swap(v[posminimo],v[v.size()-1]);
        v.pop_back();
    }
    return res;
}

#endif //SOLUCION_TEMPLATES_HPP
