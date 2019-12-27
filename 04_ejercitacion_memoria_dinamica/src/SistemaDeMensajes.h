#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
//#include "Proxy.h"
#include "Proxy2.h"
#include <string>
#include <vector>

#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    void registrarJugador(int id, string ip);
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    void desregistrarJugador(int);
    Proxy* obtenerProxy(int id);

    ~SistemaDeMensajes();

  private:
    ConexionJugador* _conns[4]; //Arreglo estático de punteros
   // Proxy* _proxy;
    vector<Proxy*> _proxies;
};

#endif
