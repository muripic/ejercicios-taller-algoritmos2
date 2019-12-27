#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
int cantApariciones(int e, vector<int> s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == e) {
            res++;
        }
    }
    return res;
}

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res = vector<int>();
    for (int i = 0; i < s.size(); i++) {
        if (cantApariciones(s[i], res) == 0) {
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> res = vector<int>();
    set<int> conj = set<int>();
    for (int i = 0; i < s.size(); i++) {
        conj.insert(s[i]);
    }
    for (int n : conj) {
        res.push_back(n);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    bool aEnB = true;
    bool bEnA = true;
    for (int i = 0; i < a.size(); i++) {
        if (cantApariciones(a[i], b) == 0) {
            aEnB = false;
            break;
        }
    }
    if (aEnB == true) {
        for (int i = 0; i < b.size(); i++) {
            if (cantApariciones(b[i], a) == 0) {
                bEnA = false;
                break;
            }
        }
        return aEnB && bEnA;
    }
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> conjA = set<int>();
    for (int i = 0; i < a.size(); i++) {
        conjA.insert(a[i]);
    }
    set<int> conjB = set<int>();
    for (int i = 0; i < b.size(); i++) {
        conjB.insert(b[i]);
    }
    return conjA == conjB;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res = map<int, int>();
    for (int i = 0; i < s.size(); i++) {
        res[s[i]] = cantApariciones(s[i], s);
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res = vector<int>();
    map<int, int> dicc = contar_apariciones(s);
    for (int i = 0; i < s.size(); i++) {
        if (dicc[s[i]] == 1) {
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res = set<int>();
    for (int x : a) {
        if (b.count(x) == 1) {
            res.insert(x);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res = map<int, set<int>>();
    for (int i = 0; i < s.size(); i++) {
        res[(s[i] % 10)].insert(s[i]);
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    map<char, char> dicc;
    for (int i = 0; i < tr.size(); i++) {
        dicc[tr[i].first] = tr[i].second;
    }
    for (int i = 0; i < str.size(); i++) {
        if (dicc.count(str[i]) == 1) {
            str[i] = dicc[str[i]];
        }
    }
    return str;
}

// Ejercicio 10
bool hayInterseccionLU(set<LU> a, set<LU> b) {
    bool res = false;
    for (LU x : a) {
        if (b.count(x) == 1) {
            res = true;
            break;
        }
    }
    return res;
}

bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s.size(); j++){
            if (i != j && s[i].libretas()!=s[j].libretas() && hayInterseccionLU(s[i].libretas(),s[j].libretas())){
                res = true;
                break;
            }
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for (int i = 0; i < s.size(); i++){
        if (s[i].adjunto() && s[i].fecha() > (res[s[i].libretas()]).fecha()){
            res[s[i].libretas()] = s[i];
        }
    }
    return res;
}