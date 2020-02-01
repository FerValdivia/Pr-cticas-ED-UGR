// Fernando Valdivia del Rosal

#ifndef _INSTRUCCIONES_H_
#define _INSTRUCCIONES_H_

#include "arbolbinario.h"
#include "acciones.h"
#include <stack>
#include <string>
using namespace std;

class instrucciones{

	private:
		ArbolBinario<string> datos;
		static acciones acc;

	public:
		// Constructor sin parámetros
		instrucciones ();

		// Constructor (hay que pasarle como parámetro un objeto de la clase acciones)
		instrucciones (acciones& accions);

		// Modificador de acciones
		void setAcciones (acciones& accions);

		// Modificador de datos
		void setDatos (ArbolBinario<string>& dat);

		// Obtener datos (por copia)
		ArbolBinario<string> getDatos() const;

		// Operador >>
		friend istream & operator >> (istream & is, instrucciones & instr);

		// Operador <<
		friend ostream & operator << (ostream & out, const instrucciones & instr);






};

#endif
