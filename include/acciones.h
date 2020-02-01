// Fernando Valdivia del Rosal

#ifndef _ACCIONES_H_
#define _ACCIONES_H_

#include <map>
using namespace std;

class acciones{

	private:
		map<string, unsigned char> datos;

	public:
		// Constructor sin parámetros
		acciones();

		// Operador []
		// Recibe la accion (que es la clave en el map) y devuelve la ariedad de la accion
		unsigned char operator [] (string accion);
		unsigned char operator [] (string accion) const;

		// Insertar accion en acciones (la inserción se hace por referencia)
		void insertar (string accion, unsigned int ariedad);

		// Borrar Receta en Recetas
		void borrar (string accion);

		// Operador >>
		friend istream & operator >> (istream & is, acciones & a);

		// Operador <<
		friend ostream & operator << (ostream & out, const acciones & a);

};


#endif
