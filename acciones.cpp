// Fernando Valdivia del Rosal

#include <iostream>
#include "acciones.h"
using namespace std;


// Constructor sin parámetros

acciones::acciones(){}


// Operador []
// Recibe la accion (que es la clave en el map) y devuelve la ariedad de la accion

unsigned char acciones::operator [] (string accion){
	return datos[accion];
}

// Operador [] constante
/*
Antes tenía "return datos.at(accion);", que es lo que me dijo en clase como corrección al map de recetas.
Sin embargo el .at genera una excepción cuando busco algo que no está en el map, que es lo que uso en el
operador << de instrucciones. Es por ello por lo que como tienen la misma complejidad y el mismo coste
(logarítmico en tamaño) lo he cambiado por find.
*/
unsigned char acciones::operator [] (string accion) const{
	//return datos.at(accion);
	unsigned char aridad;

	map<string, unsigned char>::const_iterator it;
	it = datos.find(accion);

	if (it != datos.end()){
		aridad = it->second;
	}
	else{
		aridad = 0;
	}

	return aridad;
}


// Insertar accion en acciones (la inserción se hace por referencia)

void acciones::insertar (string accion, unsigned int ariedad){
	datos[accion] = ariedad;
}


// Borrar Receta en Recetas

void acciones::borrar (string accion){
	datos.erase(accion);
}


// Operador >>
istream & operator >> (istream & is, acciones & a){
	string accion;
	unsigned char ariedad;
	
	while (is >> accion){
		is >> ariedad;
		a.datos[accion] = ariedad;
	}

	return is;
}


// Operador <<
ostream & operator << (ostream & out, const acciones & a){

	out << "Las acciones son: " << endl;

	map<string, unsigned char>::const_iterator it;

	for (it = (a.datos).begin(); it != (a.datos).end(); it++){
		cout << (*it).first << " " << (*it).second << endl;
	}
	
	return out;
}

