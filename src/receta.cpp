// Fernando Valdivia del Rosal

#include <iostream>
#include <sstream>
#include "color.h"
#include "receta.h"

using namespace std;


// Constructor Receta

Receta::Receta(){
	nombre = "Undefined";				// Por defecto, hasta la inicialización el nombre será "Undefined"
}

Receta::Receta(string cod, unsigned int plat, string nomb, list<pair<string,unsigned int>> ingr){
	code= cod;
	plato = plat;
	nombre = nomb;
	ings = ingr;
	calorias = -1;					// Los inicializo a -1 porque como se puede usar la clase sin los datos nutricionales de cada ingrediente
	hc = -1;					// de esta forma entendemos que la Receta no tiene datos, y no que tiene 0 nutrientes de un tipo determinado.
	grasas = -1;					// Es por ello que el el cálculo de los nutrientes en la función calculoNutrientes ya sí se inicializan a 0,
	proteinas = -1;					// de forma que si se consulta un nutriente y se obtiene un 0 entendemos que no posee ese tipo de nutrientes
	fibra = -1;					// y no que no se hayan calculado estos debido a la ausencia de los datos de cada ingrediente.
}

// Operador >>

istream & operator >> (istream & is, Receta & r){

	string receta, codigo, nombre, nom_ingr, dato;
	float cantidad;
	unsigned int plato;
	string ingrediente;
	list<pair<string,unsigned int>> ings;
	
	// Leemos toda la receta
	getline(is, receta, '\n');
	
	istringstream rec;				// Objeto istringstream
	rec.str (receta);				// Asociar "receta" al flujo "rec"
	
	getline(rec, codigo, ';');
	rec >> plato;
	rec.ignore(1);
	getline(rec, nombre, ';');

	// Lectura de ingredientes

	while(!rec.eof()){
		getline(rec, ingrediente, ';');			// Leemos ingrediente de la receta

		size_t encontrado = ingrediente.find_last_of(' ');

		cantidad = stoi(ingrediente.substr(encontrado+1));		// +1 para que no esté el carácter ' '

		nom_ingr = ingrediente.substr(0, encontrado);

		ings.push_back(pair<string,unsigned int>(nom_ingr, cantidad));
	}


	
	r = Receta(codigo, plato, nombre, ings);

	return is;
	
	

}

// Operador <<

ostream & operator << (ostream & out, const Receta & r){

	out << FBLU("CODE: ") << r.code << FBLU("   RECETA: ") << r.nombre << FBLU("   PLATO: ") << r.plato << endl;

	out << UNDL(BOLD("\nIngredientes:\n"));

	list< pair<string,unsigned int> >::const_iterator it;
	for (it = (r.ings).begin(); it != (r.ings).end(); ++it){

		out<<"    "<<(*it).first<<" "<<(*it).second<<"\n";
  	}

	out << UNDL(BOLD("\nInformación Nutricional:")) << endl;
	out << "\tCalorias: " << r.calorias << "\n\tHidratos de Carb.: " << r.hc << "\n\tGrasas: " << r.grasas
			<< "\n\tProteinas: " << r.proteinas  << "\n\tFibra: " << r.fibra << endl;


	return out;
}


// Consultor de nombre

string Receta :: getNombre() const
{
	return nombre;
}

// Consultor de code

string Receta :: getCode () const
{
	return code;
}

// Consultor de plato

unsigned int Receta :: getPlato () const
{
	return plato;
}

// Consultor de calorias

float Receta :: getCalorias() const
{
	return calorias;
}

// Consultor de hidratos

float Receta :: getHc() const
{
	return hc;
}

// Consultor de grasas

float Receta :: getGrasas() const
{
	return grasas;
}

// Consultor de proteinas

float Receta :: getProteinas() const
{
	return proteinas;
}

// Consultor de fibra

float Receta :: getFibra() const
{
	return fibra;
}

// Modificador de calorias

void Receta :: setCalorias(float cal)
{
	if (cal >= 0)
		calorias = cal;
}

// Modificador de hidratos

void Receta :: setHc(float hidratos)
{
	if (hidratos >= 0)
		hc = hidratos;
}

// Modificador de grasas

void Receta :: setGrasas(float gras)
{
	if (gras >= 0)
		grasas = gras;
}

// Modificador de proteinas

void Receta :: setProteinas(float prot)
{
	if (prot >= 0)
		proteinas = prot;
}

// Modificador de fibra

void Receta :: setFibra(float fibr)
{
	if (fibr >= 0)
		fibra = fibr;
}


int Receta :: ningredientes(){
	return ings.size();
}


list< pair<string,unsigned int> > Receta :: getIngredientes() const
{
	return ings;
}

instrucciones& Receta :: getInstrucciones (){
	return inst;
}

void Receta :: setInstrucciones (instrucciones& instr){
	inst = instr;
}


/***************************************************************************/
// ITERADORES

Receta::iterator Receta::begin(){
	iterator iterador;
	iterador = ings.begin();
	return iterador;
}

Receta::iterator Receta::end(){
	iterator iterador;
	iterador = ings.end();
	return iterador;
}

Receta::const_iterator Receta::begin() const{
	const_iterator iterador;
	iterador = ings.begin();
	return iterador;
}

Receta::const_iterator Receta::end() const{
	const_iterator iterador;
	iterador = ings.end();
	return iterador;
}





