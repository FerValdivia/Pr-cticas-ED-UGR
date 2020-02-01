// Fernando Valdivia del Rosal

#include <iostream>
#include <string>
#include "ingrediente.h"

using namespace std;

// Constructor de Ingrediente

Ingrediente::Ingrediente(){}

Ingrediente :: Ingrediente (string nomb, float cal, float hb, float prot, float gras, float fibr, string tipo_ingr){
	nombre = nomb;
	calorias = cal;
	hidratos = hb;
	proteinas = prot;
	grasas = gras;
	fibra = fibr;
	tipo = tipo_ingr;
}


// Consultor de nombre

string Ingrediente :: getNombre () const
{
	return nombre;
}


// Consultor de calorías

float Ingrediente :: getCalorias () const
{
	return calorias;
}


// Consultor de hidratos de carbono

float Ingrediente :: getHc () const
{
	return hidratos;
}


// Consultor de proteinas

float Ingrediente :: getProteinas () const
{
	return proteinas;
}


// Consultor de grasas

float Ingrediente :: getGrasas () const
{
	return grasas;
}


// Consultor de fibra

float Ingrediente :: getFibra () const
{
	return fibra;
}


// Consultor de tipo

string Ingrediente :: getTipo () const
{
	return tipo;
}


// Operador >>

istream & operator >> (istream & is, Ingrediente & i){
	string nomb, tipo_ingrediente;
	float cal, hb, prot, gras, fibr;

	getline(is, nomb, ';');
	is >> cal;
	is.ignore(1);
	is >> hb;
	is.ignore(1);
	is >> prot;
	is.ignore(1);
	is >> gras;
	is.ignore(1);
	is >> fibr;
	is.ignore(1);
	getline(is, tipo_ingrediente, '\n');
	i = Ingrediente(nomb, cal, hb, prot, gras, fibr, tipo_ingrediente);

	return is;
}


// Operador <<
ostream & operator << (ostream & out, const Ingrediente & i){

	out << "Ingrediente " << i.getNombre() << ": " << endl;
	out << "\tCalorías: " << i.getCalorias() << endl;
	out << "\tHidratos de carbono: " << i.getHc() << endl;
	out << "\tProteinas: " << i.getProteinas() << endl;
	out << "\tGrasas: " << i.getGrasas() << endl;
	out << "\tFibra: " << i.getFibra() << endl;
	out << "\tTipo de ingrediente: " << i.getTipo() << endl;
	
	return out;
}



// Modificador de nombre

void Ingrediente :: setNombre (string nomb)
{
	nombre = nomb;
}


// Modificador de calorías

void Ingrediente :: setCalorias (float cal)
{
	if (cal >= 0)
		calorias = cal;
}


// Modificador de hidratos de carbono

void Ingrediente :: setHidratos (float hb)
{
	if (hb >= 0 && hb <= 100)
		hidratos = hb;
}


// Modificador de proteinas

void Ingrediente :: setProteinas (float prot)
{
	if (prot >= 0 && prot <= 100)
		proteinas = prot;
}


// Modificador de grasas

void Ingrediente :: setGrasas (float gras)
{
	if (gras >= 0 && gras <= 100)
		grasas = gras;
}


// Modificador de fibra

void Ingrediente :: setFibra (float fibr)
{
	if (fibr >= 0 && fibr <= 100)
		fibra = fibr;
}


// Modificador de tipo

void Ingrediente :: setTipo (string tipo_ingr)
{
	tipo = tipo_ingr;
}


