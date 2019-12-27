//////////////
// PRELUDIO //
//////////////

// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO = 1;
const Mes FEBRERO = 2;
const Mes MARZO = 3;
const Mes ABRIL = 4;
const Mes MAYO = 5;
const Mes JUNIO = 6;
const Mes JULIO = 7;
const Mes AGOSTO = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE = 10;
const Mes NOVIEMBRE = 11;
const Mes DICIEMBRE = 12;

// Ejercicio 1: esBisiesto
bool esBisiesto(Anio anio) {
    bool res = false;
    if (anio % 100 == 0 && anio % 400 != 0) {
        res = false;
    } else if (anio % 4 == 0) {
        res = true;
    }
    return res;
}

// Ejercicio 2: diasEnMes
int diasEnMes(Anio anio, Mes mes) {
    int res = 30;
    if (mes == FEBRERO && esBisiesto(anio)) {
        res = 29;
    } else if (mes == FEBRERO) {
        res = 28;
    } else if (mes < 8 && mes % 2 == 1) {
        res = 31;
    } else if (mes >= 8 && mes % 2 == 0) {
        res = 31;
    }
    return res;
}

// Para ejercicio 6
class Periodo;

class Fecha {
public:
    // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
    Fecha(Anio anio, Mes mes, Dia dia);

    Anio anio() const;

    Mes mes() const;

    Dia dia() const;

    bool operator==(Fecha o) const;

    bool operator<(Fecha o) const;

    // Ejercicio 7: sumar período a fecha
    void sumar_periodo(Periodo p);

private:
    Anio _anio;
    Mes _mes;
    Dia _dia;

    // Ejercicio 7: sumar a fecha
    void sumar_anios(int anios);

    void sumar_meses(int meses);

    void sumar_dias(int dias);

};

// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia) : _anio(anio), _mes(mes % 12), _dia(dia % diasEnMes(anio, mes)) {
}

Anio Fecha::anio() const {
    return _anio;
}

Mes Fecha::mes() const {
    return _mes;
}

Dia Fecha::dia() const {
    return _dia;
}


// Ejercicio 4: comparadores
bool Fecha::operator==(Fecha o) const {
    return _dia == o._dia && _mes == o._mes && _anio == o._anio;
}

bool Fecha::operator<(Fecha o) const {
    return _anio < o._anio || (_anio == o._anio && _mes < o._mes) ||
           (_anio == o._anio && _mes == o._mes && _dia < o._dia);
}

// Ejercicio 5: comparador distinto
bool operator!=(Fecha f1, Fecha f2) {
    return !(f1.anio() == f2.anio() && f1.mes() == f2.mes() && f1.dia() == f2.dia());
}

// Ejercicio 6: clase período
class Periodo {
public:
    //pre: anios >= 0, meses >= 0, dias >= 0
    Periodo(int anios, int meses, int dias);

    int anios() const;

    int meses() const;

    int dias() const;

private:
    int _anios, _meses, _dias;
};

Periodo::Periodo(int anios, int meses, int dias) : _anios(anios), _meses(meses), _dias(dias) {
}

int Periodo::anios() const {
    return _anios;
}

int Periodo::meses() const {
    return _meses;
}

int Periodo::dias() const {
    return _dias;
}

//Ejercicio 7
void Fecha::sumar_anios(int anios) {
    _anio = _anio + anios;
}

void Fecha::sumar_meses(int meses) {
    _anio = _anio + (_mes + meses) / 12;
    _mes = (_mes + meses) % 12;
}

void Fecha::sumar_dias(int dias) {
    if (dias >= 365) {
        while (dias >= 365) {
            if (esBisiesto(_anio) && _mes < 3) {
                _anio++;
                dias = dias - 366;
            } else {
                _anio++;
                dias = dias - 365;
            }
        }
    }
    if (_dia + dias < diasEnMes(_anio, _mes)) {
        _dia = _dia + dias;
    } else {
        while (_dia + dias >= diasEnMes(_anio, _mes)) {
            _dia = _dia + dias - diasEnMes(_anio, _mes);
            _mes++;
            dias = dias - (diasEnMes(_anio, _mes) - _dia + 1);
        }
    }
};

void Fecha::sumar_periodo(Periodo p) {
    sumar_dias(p.dias());
    sumar_meses(p.meses());
    sumar_anios(p.anios());
}

// Ejercicio 8: clase Intervalo
class Intervalo {
public:
    //pre: desde < hasta
    Intervalo(Fecha desde, Fecha hasta);

    Fecha desde() const;

    Fecha hasta() const;

    int enDias() const;

private:
    Fecha _desde, _hasta;

};

Intervalo::Intervalo(Fecha desde, Fecha hasta) : _desde(desde), _hasta(hasta) {
}

Fecha Intervalo::desde() const {
    return _desde;
}

Fecha Intervalo::hasta() const {
    return _hasta;
}

int Intervalo::enDias() const {
    int diasAnio = 0;
    Anio hastaA = _hasta.anio();
    while (hastaA - _desde.anio() > 0) {
        if (esBisiesto(hastaA)) {
            diasAnio = diasAnio + 366;
        } else {
            diasAnio = diasAnio + 365;
        }
        hastaA--;
    }
    int diasMes = 0;
    Mes hastaM = _hasta.mes();
    while (hastaM - _desde.mes() > 0) {
        hastaM--;
        diasMes = diasMes + diasEnMes(_hasta.anio(), hastaM);
    }
    return diasAnio + diasMes + (_hasta.dia() - _desde.dia());
}