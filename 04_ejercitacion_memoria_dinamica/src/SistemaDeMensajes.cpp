#include "SistemaDeMensajes.h"
#include "ConexionJugador.h"
#include <iostream>

using namespace std;

// Completar...
SistemaDeMensajes::SistemaDeMensajes() {
    for (int i = 0; i < 4; i++) {
        _conns[i] = nullptr;
    }
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int i = 0; i < 4; i++) {
        if (_conns[i] != nullptr) {
            delete _conns[i];
        };
    }
    for (int i = 0; i < _proxies.size(); i++) {
            delete _proxies[i];
    }
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

void SistemaDeMensajes::registrarJugador(int id, string ip) { //Tengo un leak en 1 bloque en esta función
    if (registrado(id)) {  //pero no tengo ningún método para modificar id directamente
        delete _conns[id];
    }
    _conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    if (registrado(id)) {
        _conns[id]->enviarMensaje(mensaje);
    }
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    if (registrado(id)) {
        _conns[id] = nullptr;
    };
}

/*Proxy* SistemaDeMensajes::obtenerProxy(int id){
    _proxies.push_back(new Proxy(_conns[id]));
    return _proxies[_proxies.size()-1];
}*/


Proxy* SistemaDeMensajes::obtenerProxy(int id){
    _proxies.push_back(new Proxy(&_conns[id]));
    return _proxies[_proxies.size()-1];
}
