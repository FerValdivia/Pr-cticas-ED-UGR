// Fernando Valdivia del Rosal

#include <iostream>
#include "instrucciones.h"
using namespace std;

instrucciones::instrucciones(){}

instrucciones::instrucciones (acciones& accions){
	acc = accions;
}

void instrucciones::setAcciones (acciones& accions){
	acc = accions;
}

acciones instrucciones::acc = acciones();

void instrucciones::setDatos (ArbolBinario<string>& dat){
	datos = dat;
}

ArbolBinario<string> instrucciones::getDatos() const{
	return datos;
}

// Operador >>
istream & operator >> (istream & is, instrucciones & instr){
	stack < ArbolBinario<string> > p;
	string accion, ingrediente;
	char caracter;

	while(is >> accion){
		is.get(caracter);

		ArbolBinario<string> arbol(accion);

		if (instr.acc[accion] == '1'){

			if (caracter == '\n'){				// Caracter es '\n'

				arbol.Insertar_Hi(arbol.getRaiz(), p.top());
				p.pop();

			}

			else {						// Caracter es ' '
				getline(is, ingrediente, '\n');

				arbol.Insertar_Hi(arbol.getRaiz(), ingrediente);
			}
		}

		if (instr.acc[accion] == '2'){

			if (caracter == '\n'){

				arbol.Insertar_Hd(arbol.getRaiz(), p.top());
				p.pop();

				arbol.Insertar_Hi(arbol.getRaiz(), p.top());
				p.pop();

			}

			else {

				getline(is, ingrediente, '\n');

				arbol.Insertar_Hd(arbol.getRaiz(), ingrediente);

				arbol.Insertar_Hi(arbol.getRaiz(), p.top());
				p.pop();

			}

		}

		p.push(arbol);
	}

	instr.datos = p.top();
	p.pop();

	return is;
}



// Operador <<
ostream & operator << (ostream & out, const instrucciones & instr){

	string ingrediente;
	ArbolBinario<string>::postorden_iterador it = instr.datos.beginpostorden();

	while (it != instr.datos.endpostorden()){

		if ( instr.acc[(*it)] == 0){			// Si no tiene aridad es un ingrediente (operator [] devuelve el unsigned char 0)
								// Al ser instr constante se usará el const operator [] de acciones

			ingrediente = " " + *it;
		}
		else {						// Si es una acción de aridad 1 o 2

			out << *it << ingrediente << endl;
			ingrediente = "";			// Dejamos el ingrediente vacío para que no vuelva a aparecer si este se refiere al ingr. anterior
		}

		++it;
	}

	return out;

}

