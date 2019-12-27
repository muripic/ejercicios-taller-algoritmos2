#include "ColaPrior.h"

template<class T>
ColaPrior<T>::ColaPrior() : _size(0), _v() {
}

template<class T>
int ColaPrior<T>::tam() const {
    return _size;
}

template<class T>
void ColaPrior<T>::encolar(const T &elem) {
    if (_size == 0) {
        _v.push_back(elem);
    } else {
        _v.push_back(elem);
        for (int i = _v.size() - 1; i > 0; i++) {
            if (elem > _v[(i - 1) / 2]) {
                swap(_v[i], _v[(i - 1) / 2]);
                i = (i - 1) / 2;
            } else {
                break;
            }
        }
    }
    _size++;
}

template<class T>
const T &ColaPrior<T>::proximo() const {
    return _v[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
    swap(_v[0], _v[_v.size() - 1]);
    _v.pop_back();
    int i = 0;
    while (i < _v.size()) {
        if (2 * i + 1 == _v.size() - 1 and _v[i] < _v[2 * i + 1]) {
            swap(_v[i], _v[2 * i + 1]);
            i = 2 * i + 1;
        } else if (2 * i + 2 < _v.size() and _v[i] < max(_v[2 * i + 1], _v[2 * i + 2])) {
            if (_v[2 * i + 1] > _v[2 * i + 2]) {
                swap(_v[i], _v[2 * i + 1]);
                i = 2 * i + 1;
            } else {
                swap(_v[i], _v[2 * i + 2]);
                i = 2 * i + 2;
            }
        } else {
            break;
        }
    }
    _size--;
}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T> &elems) {
    // COMPLETAR
}

