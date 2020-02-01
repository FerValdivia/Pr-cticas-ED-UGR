// Fernando Valdivia del Rosal

#include <iostream>
#include "color.h"
#include "recetas.h"

using namespace std;


// Contructor Recetas
Recetas :: Recetas(){}


// Tamaño de Recetas

int Recetas::size (){
	return datos.size();
}

// Operador []
// Recibe el código (que es la clave en el map) y devuelve el valor en el map

Receta& Recetas::operator [] (string code){
	return datos[code];
}

Receta Recetas::operator [] (string code) const{
	return datos.at(code);
}

// Insertar Receta en Recetas (la inserción se hace por referencia)

void Recetas::insertar (Receta& receta){
	datos[receta.getCode()] = receta;
}

// Borrar Receta en Recetas

void Recetas::borrar (string code){
	datos.erase(code);
}




// Operador >>
istream & operator >> (istream & is, Recetas & r){
	Receta recet;

	while (is >> recet){
		r.datos[recet.getCode()] = recet;
	}

	return is;
}


// Operador <<
ostream & operator << (ostream & out, const Recetas & r){

	// Ingrediente y cantidad
	Recetas::const_iterator it;

	for (it = r.begin(); it != r.end(); ++it){
		out << FBLU("CODE: ") << (*it).getCode() << FBLU("\tNOMBRE: ") << (*it).getNombre() << FBLU("\tPLATO:") << (*it).getPlato() << endl;
	}
	
	return out;
}


/***************************************************************************/
// ITERADORES

Recetas::iterator Recetas::begin(){
	iterator iterador;
	iterador.it = datos.begin();
	return iterador;
}

Recetas::iterator Recetas::end(){
	iterator iterador;
	iterador.it = datos.end();
	return iterador;
}

Recetas::const_iterator Recetas::begin() const{
	const_iterator iterador;
	iterador.it = datos.begin();
	return iterador;
}

Recetas::const_iterator Recetas::end() const{
	const_iterator iterador;
	iterador.it = datos.end();
	return iterador;
}

