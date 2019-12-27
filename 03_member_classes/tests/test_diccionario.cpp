#include "gtest-1.8.1/gtest.h"
#include "../src/Diccionario.h"

#if EJ >= 4
TEST(diccionario, ej4_def) {
	Diccionario d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
}

TEST(diccionario, ej4_obtener) {
	Diccionario d;
	d.definir(1, 4);
	ASSERT_EQ(d.obtener(1), 4);
	d.definir(1, 44);
	ASSERT_EQ(d.obtener(1), 44);
	d.definir(2, 5);
	ASSERT_EQ(d.obtener(1), 44);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(1, 444);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(2, 55);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 55);
}
#endif

#if EJ >= 5
TEST(diccionario, ej5_borrar) {
Diccionario d;
d.definir(1, 1);
ASSERT_TRUE(d.def(1));
d.borrar(1);
ASSERT_FALSE(d.def(1));
d.definir(2,4);
d.definir(3, 9);
d.definir(4,16);
ASSERT_TRUE(d.def(3));
d.borrar(3);
ASSERT_FALSE(d.def(3));
ASSERT_TRUE(d.def(2));
ASSERT_TRUE(d.def(4));
Diccionario dcopia = d;
d.borrar(5);
bool iguales = dcopia == d;
ASSERT_TRUE(iguales); //Chequea si son iguales después de eliminar entrada inexistente
}
#endif

#if EJ >= 6
TEST(diccionario, ej6) {
vector<Clave> v1 = {1,2,3,4,5,6};
vector<Clave> v2 = {3,2,1,5,4,6};
vector<Clave> v3 = {3,2,1,3,4,5};
ASSERT_TRUE(pertenece(v1,4));
ASSERT_FALSE(pertenece(v1,7));
ASSERT_TRUE(sinRepetidos(v1));
ASSERT_FALSE(sinRepetidos(v3));
ASSERT_TRUE(esPermutacion(v1,v2));
ASSERT_FALSE(esPermutacion(v1,v3));
Diccionario d1;
d1.definir(1, 1);
d1.definir(2, 4);
d1.definir(3, 6);
d1.definir(4, 16);
d1.definir(3, 9);
Diccionario d2;
d2.definir(2, 1);
d2.definir(3, 4);
d2.definir(1, 6);
d2.definir(4, 16);
d2.definir(2, 9);
Diccionario d3;
d3.definir(2, 1);
d3.definir(3, 4);
d3.definir(1, 6);
d3.definir(4, 16);
d3.definir(5, 9);
vector<Clave> claves1 = d1.claves();
vector<Clave> claves2 = d2.claves();
vector<Clave> claves3 = d3.claves();
ASSERT_FALSE(pertenece(claves1,5));
ASSERT_TRUE(pertenece(claves1,4));
ASSERT_TRUE(sinRepetidos(claves1));
ASSERT_TRUE(sinRepetidos(claves2));
ASSERT_TRUE(esPermutacion(claves1,claves2));
ASSERT_FALSE(esPermutacion(claves1,claves3));
}


#endif

#if EJ >= 7
TEST(diccionario, ej7) {
Diccionario d1;
d1.definir(1, 1);
d1.definir(2, 4);
d1.definir(3, 6);
d1.definir(4, 16);
d1.definir(3, 9);
Diccionario d2;
d2.definir(2, 1);
d2.definir(3, 4);
d2.definir(1, 6);
d2.definir(4, 16);
d2.definir(2, 9);
bool iguales1y2 = d1 == d2;
ASSERT_FALSE(iguales1y2);
d2.definir(2,4);
d2.definir(3,9);
d2.definir(1,1);
iguales1y2 = d1 == d2;
ASSERT_TRUE(iguales1y2);
}

#endif

#if EJ >= 8
TEST(diccionario, ej8) {
Diccionario d1;
d1.definir(1, 1);
d1.definir(2, 4);
d1.definir(3, 9);
d1.definir(4, 16);
Diccionario d2;
d2.definir(1, 1);
d2.definir(2, 4);
d2.definir(3, 6);
d2.definir(5, 25);
Diccionario d3;
d3.definir(1, 1);
d3.definir(2, 4);
d3.definir(3, 9);
d3.definir(4, 16);
d3.definir(5, 25);
Diccionario d4;
d4.definir(1, 1);
d4.definir(2, 4);
d4.definir(3, 6);
d4.definir(4, 16);
d4.definir(5, 25);
Diccionario union1 = d1 || d2;
bool res1 = union1 == d3;
ASSERT_TRUE(res1);
bool res2 = union1 == d4;
ASSERT_FALSE(res2);
Diccionario d5;
Diccionario union2 = d4 || d5;
bool res3 = union2 == d4;
ASSERT_TRUE(res3);
Diccionario intersec1 = d1 && d2;
bool res4 = d1 == intersec1;
ASSERT_FALSE(res4);
d1.borrar(4);
bool res5 = d1 == intersec1;
ASSERT_TRUE(res5);
ASSERT_EQ(intersec1.obtener(3),9);
}

#endif
