// Fernando Valdivia del Rosal

#ifndef _RECETAS_H_
#define _RECETAS_H_

#include "receta.h"
#include <string>
#include <map>
using namespace std;

class Recetas{

private:

	map<string,Receta> datos;
	
public:

	/**
		@brief Constructor de Ingrediente sin parámetros
	*/

	Recetas();


	/**
		@brief Tamaño de Recetas
	*/

	int size ();


	/**
		@brief Operador []
		Recibe el nombre (que es la clave en el map) y devuelve el valor en el map
	*/

	Receta& operator [] (string code);
	Receta operator [] (string code) const;


	/**
		@brief Insertar Receta en Recetas (la inserción se hace por referencia)
	*/

	void insertar (Receta& receta);


	/**
		@brief Borrar Receta en Recetas
	*/

	void borrar (string code);







	/**
		@brief Sobrecarga del operador >>
		@param is stream de entrada
		@param r Recetas que recibe valores
		@return is stream de entrada
	*/

	friend istream & operator >> (istream & is, Recetas & r);


	/**
		@brief Sobrecarga del operador <<
		@param out stream de salida
		@param r Recetas a escribir
		@return os stream de salida
	*/

	friend ostream & operator << (ostream & out, const Recetas & r);


	/**
	   @brief Iterador de la clase Recetas
	*/
	
	class iterator{
		private:
			map<string,Receta>::iterator it;	/**< iterator */
		public:
			// Constructor sin parámetros
			iterator(){};

			// Operadores
			iterator& operator ++(){
				it++;
				return (*this);
			}

			iterator& operator --(){
				it--;
				return (*this);
			}

			bool operator == (const iterator& i){
				return (it == i.it);
			}

			bool operator != (const iterator& i){
				return (it != i.it);
			}
			
			Receta& operator * (){
				return ((*it).second);
			}

			friend class Recetas;
			
	};

	/**
	   @brief Iterador constante de la clase Ingredientes
	*/


	class const_iterator{
		private:
			map<string,Receta>::const_iterator it;	/**< const_iterator */
		public:
			// Constructor sin parámetros
			const_iterator(){};
			
			// Operadores
			const_iterator& operator ++(){
				it++;
				return (*this);
			}

			const_iterator& operator --(){
				it--;
				return (*this);
			}

			bool operator == (const const_iterator& i){
				return (it == i.it);
			}

			bool operator != (const const_iterator& i){
				return (it != i.it);
			}

			const Receta& operator * (){
				return ((*it).second);
			}

			friend class Recetas;

	};

	/**
	   @brief Principio del vector alfabético de Recetas
	     
	   @return iterador al principio del vector alfabético de Recetas
	*/
	iterator begin();

	/**
	   @brief Final del vector alfabético de Recetas
	     
	   @return iterador al final del vector alfabético de Recetas
	*/
	iterator end();

	/**
	   @brief Principio del vector alfabético de Recetas (constante)
	     
	   @return iterador constante al principio del vector alfabético de Recetas
	*/
	const_iterator begin() const;

	/**
	   @brief Final del vector alfabético de Recetas (constante)
	     
	   @return iterador constante al final del vector alfabético de Recetas
	*/
	const_iterator end() const;


};

#endif
