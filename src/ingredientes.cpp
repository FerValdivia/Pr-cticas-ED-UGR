// Fernando Valdivia del Rosal

#include <iostream>
#include "ingredientes.h"

using namespace std;

Ingredientes::Ingredientes(int num_ingr) : datos_alfabetico(), datos_tipo(){
	datos_alfabetico.reserve(num_ingr);
	datos_tipo.reserve(num_ingr);
};


void Ingredientes :: Insertar (Ingrediente& ingrediente){

	// Inserción en orden alfabético

	size_t indice = 0;
	bool fin = false;

	// Creamos el puntero al objeto ingrediente
	Ingrediente *ingr = new Ingrediente;
	*ingr = ingrediente;
	
	while (indice < datos_alfabetico.size() && !fin){
		
		if ((*datos_alfabetico[indice]).getNombre() <= ingrediente.getNombre()){
		
			indice++;
		}
		else
			fin = true;
	}

	datos_alfabetico.insert( (datos_alfabetico.begin()+indice) , ingr);

	// Inserción en el orden por tipo y a igualdad alfabético

	size_t indice_t = 0;
	fin = false;

	// Actualizamos los índices del vector que se han desplazado en la inserción del vector datos_alfabetico
	for (size_t i=0; i < datos_tipo.size(); i++){
		if (datos_tipo[i] >= (int)indice)
			datos_tipo[i]++;
	}

	// Buscar lugar entre los tipos
	while ( (indice_t < datos_tipo.size()) && !fin){
		if( (*datos_alfabetico[datos_tipo[indice_t]]).getTipo() < ingrediente.getTipo() )
			indice_t++;
		else
			fin = true;
	}

	fin = false;

	// Buscar lugar entre el tipo
	while ( (indice_t < datos_tipo.size()) && !fin){
		string nomb = (*datos_alfabetico[datos_tipo[indice_t]]).getNombre();
		string type = (*datos_alfabetico[datos_tipo[indice_t]]).getTipo();
		if( nomb < ingrediente.getNombre() && type == ingrediente.getTipo() )
			indice_t++;
		else
			fin = true;
	}

	
	datos_tipo.insert( (datos_tipo.begin()+indice_t) , indice);

}


void Ingredientes :: borrar (string nombre){
	bool encontrado = false;
	size_t indice_alf;			// Donde almacenaremos a dónde apunta datos_tipo del dato correspondiente
	size_t indice_tipo;
	
	// Borrado en vector tipo
	
	for (indice_tipo=0; indice_tipo < datos_tipo.size() && !encontrado; indice_tipo++){

		if ((*datos_alfabetico[datos_tipo[indice_tipo]]).getNombre() == nombre){
			
			indice_alf = datos_tipo[indice_tipo];
			datos_tipo.erase(datos_tipo.begin()+indice_tipo);
			encontrado = true;
		}
	}

	// Actualizamos los índices del vector que se han desplazado

	for (size_t i=0; i < datos_tipo.size(); i++){
		if (datos_tipo[i] >= (int)indice_alf && i != indice_tipo)
			datos_tipo[i]--;
	}

	
	// Borrado en vector alfabético
	if (encontrado){
		delete datos_alfabetico[indice_alf];
		datos_alfabetico.erase(datos_alfabetico.begin()+indice_alf);
	}
}


// Obtener información ingrediente dando su nombre



Ingrediente Ingredientes :: get (string nombre) const{
	Ingrediente ingr_encontrado("Undefined", 0, 0, 0, 0, 0, "");
	bool encontrado = false;
	size_t i = 0;
	
	while ( i < datos_alfabetico.size() && !encontrado ){
	
		if ((*datos_alfabetico[i]).getNombre() == nombre){
			encontrado = true;
		}
		else
			i++;
	}
	
	if (encontrado)
		ingr_encontrado = *datos_alfabetico[i];

	return ingr_encontrado;
}


// Obtener el ingrediente de la posición i alfabéticamente

const Ingrediente& Ingredientes :: get (int i) const{
	return *datos_alfabetico[i];
}



// Modifica el ingrediente de una posición (del orden alfabético) por otro

void Ingredientes :: Modifica (int indice, Ingrediente ingr){
	
	delete datos_alfabetico[indice];
	
	Ingrediente * p_ingr = new Ingrediente;
	*p_ingr = ingr;
	
	datos_alfabetico[indice] = p_ingr;
}


// Sobrecarga del operador [] para obtener el ingrediente de la pos i alfabéticamente

Ingrediente Ingredientes :: operator [] (int indice) const{
	return get(indice);
}


// Sobrecarga del operador [] para obtener el ingrediente por el nombre

Ingrediente Ingredientes :: operator [] (string nombre) const{
	return get(nombre);
}


// Obtener los ingredientes de un tipo

Ingredientes Ingredientes :: getIngredienteTipo (string tipo){

	Ingredientes ingr_tipo;
	
	
	for (size_t i=0; i < datos_alfabetico.size(); i++){
		string actual = (*datos_alfabetico[i]).getTipo();
		actual.pop_back();
		if (actual == tipo)
			ingr_tipo.Insertar(*datos_alfabetico[i]);
	}
	
	return ingr_tipo;
}


// Obtener los distintos tipos de un vector

vector<string> Ingredientes :: getTipos(){

	vector<string> tipos;
	tipos.reserve(10);
	string tipo_antiguo = "";
	
	for (size_t i=0; i < datos_tipo.size(); i++){

		string tipo_nuevo = (*datos_alfabetico[datos_tipo[i]]).getTipo();
		
		if (tipo_nuevo != tipo_antiguo){			
			tipos.push_back(tipo_nuevo);
			tipo_antiguo = tipo_nuevo;
		}
	}

	return tipos;
}


// Imprimir por tipo

ostream& Ingredientes :: ImprimirPorTipo (ostream & os){
	
	for (size_t i=0; i < datos_tipo.size(); i++){
		os << *datos_alfabetico[datos_tipo[i]] << endl;
	}

	return os;
}



// Operador <<

ostream& operator << (ostream & os, const Ingredientes & ingr){
	
	for (int i=0; i < ingr.size(); i++){
		os << ingr[i] << endl;
	}
	
	return os;
}



// Operador >>

istream& operator >> (istream& is, Ingredientes& ingrs){

	// Quitamos la primera línea
	string linea;
	getline(is,linea);

	Ingrediente ingr;

	while (is >> ingr){
		ingrs.Insertar(ingr);
	}

	return is;
}

// Número de Ingrediente que posee el objeto

int Ingredientes :: size() const{

	return datos_alfabetico.size();
}

// Destructor

Ingredientes :: ~Ingredientes (){
	for (size_t i=0; i < datos_alfabetico.size(); i++){
		delete datos_alfabetico[i];
	}
}


/***************************************************************************/
// ITERADORES

Ingredientes::iterator Ingredientes::begin(){
	iterator iterador;
	iterador.it = datos_alfabetico.begin();
	return iterador;
}

Ingredientes::iterator Ingredientes::end(){
	iterator iterador;
	iterador.it = datos_alfabetico.end();
	return iterador;
}

Ingredientes::const_iterator Ingredientes::begin() const{
	const_iterator iterador;
	iterador.it = datos_alfabetico.begin();
	return iterador;
}

Ingredientes::const_iterator Ingredientes::end() const{
	const_iterator iterador;
	iterador.it = datos_alfabetico.end();
	return iterador;
}

