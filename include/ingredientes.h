// Fernando Valdivia del Rosal

/**
  * @file ingredientes.h
  * @brief Fichero cabecera del TDA Ingredientes
  *
  */

#ifndef _INGREDIENTES_H_
#define _INGREDIENTES_H_

#include <iostream>
#include <vector>
#include "ingrediente.h"
#include <string>
using namespace std;


/**
  *  @brief T.D.A. Ingredientes
  *
  * Una instancia @e c del tipo de datos abstracto @c Ingredientes es un objeto
  * que posee una colección ordenada de objetos de la clase Ingrediente ordenados
  * alfabéticamente por nombre y ordenados por tipo y dentro de cada tipo
  * alfabéticamente por nombre.
  *
  * Un ejemplo de su uso:
  * @include test_ingredientes.cpp
  *
  * @author Fernando Valdivia
  * @date Octubre 2019
  */

class Ingredientes
{
	private:
	  /**
	  * @page repIngredientes Rep del TDA Ingredientes
	  *
	  * @section invIngredientes Invariante de la representación
	  *
	  * El invariante es  rep.datos_alfabetico.size() == rep.datos_tipo.size()
	  *
	  * @section faIngredientes Función de abstracción
	  *
	  * Un objeto válido @e rep del TDA Ingrediente es una dupla en la que se encuentra datos_alfabetico, Vector Dinámico de punteros a objetos Ingrediente
	  * ordenados alfabéticamente, y datos_tipo, Vector Dinámico de enteros que apuntan a los índices de datos_alfabetico y ordenan estos por tipo y a
	  * igualdad de tipo por orden alfabético.
	  *
	  * (rep.datos_alfabetico,rep.tipo)
	  *
	  */
		
		vector<Ingrediente*> datos_alfabetico;	/**< datos_alfabetico */
		vector<int> datos_tipo;			/**< datos_tipo */



	public:


	/**
	   @brief Constructor de Ingredientes

	   @param num_ingr: número de objetos Ingrediente que inicialmente tendrá
	*/

	Ingredientes(int num_ingr = 300);


	/**
	   @brief Inserta ingrediente en los dos vectores de las dos ordenaciones
	     
	   @param ingrediente: objeto de la clase Ingrediente a insertar (se pasa por referencia)
	*/
	void Insertar (Ingrediente& ingrediente);


	/**
	   @brief Borrar una componente del objeto
	     
	   @param nombre: nombre del Ingrediente a borrar
	*/

	void borrar (string nombre);


	/**
	   @brief Obtener información del ingrediente dando su nombre
	     
	   @param nombre: nombre del ingrediente a obtener información

	   @return objeto Ingrediente
	*/

	Ingrediente get (string nombre) const;


	/**
	   @brief Obtener el ingrediente de la posición i alfabéticamente
	     
	   @param i: indice de la componente a obtener
	
	   @pre i < size()

	   @return referencia a la i-ésima componente del vector
	*/


	const Ingrediente& get (int i) const;


	/**
	   @brief Modifica el ingrediente de una posición (del orden alfabético) por otro
	     
	   @param indice: indice del Ingrediente a modificar
	
	   @param ingr: objeto Ingrediente por el que se va a modificar

	   @pre i < size()

	   @return referencia a la i-ésima componente del vector
	*/

	void Modifica (int indice, Ingrediente ingr);


	/**
	   @brief Sobrecarga del operador [] para obtener el ingrediente de la pos i alfabéticamente
	     
	   @param indice: indice del Ingrediente a obtener

	   @pre i < size()

	   @return objeto Ingrediente
	*/

	Ingrediente operator [] (int indice) const;



	/**
	   @brief Sobrecarga del operador [] para obtener el ingrediente por el nombre
	     
	   @param nombre: nombre del Ingrediente a obtener

	   @return objeto Ingrediente
	*/

	Ingrediente operator [] (string nombre) const;


	/**
	   @brief Obtener los ingredientes de un tipo
	     
	   @param tipo: indice el tipo de los Ingrediente a obtener

	   @return objeto Ingredientes con los objetos Ingrediente del tipo correspondiente
	*/

	Ingredientes getIngredienteTipo (string tipo);


	/**
	   @brief Obtener los distintos tipos del objeto
	     
	   @return vector<string> con los distintos nombres de alimento
	*/

	vector<string> getTipos();


	/**
	   @brief Imprimir todos los objetos Ingrediente por tipo
	     
	   @param os stream de salida

	   @return os stream de salida
	*/

	ostream& ImprimirPorTipo (ostream & os);


	
	/**
	   @brief Sobrecarga del operador <<

	   @param os stream de salida

	   @param ingr Ingredientes a escribir

	   @return os stream de salida
	*/

	friend ostream& operator << (ostream & os, const Ingredientes & ingr);


	/**
	   @brief Sobrecarga del operador >>

	   @param is stream de entrada

	   @param ingrs Ingredientes que recibe valores

	   @return is stream de entrada
	*/

	friend istream& operator >> (istream& is, Ingredientes& ingrs);


	/**
	   @brief Número de Ingrediente que posee el objeto
	     
	   @return número de objetos Ingrediente que posee el objeto
	*/

	int size() const;

	/**
	   @brief Destructor (libera la memoria dinámica reservada)
	*/

	~Ingredientes ();

	/**
	   @brief Iterador de la clase Ingredientes
	*/

	class iterator{
		private:
			vector<Ingrediente*>::iterator it;	/**< iterator */
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
			
			Ingrediente& operator * (){
				return (**it);
			}

			friend class Ingredientes;
			
	};

	/**
	   @brief Iterador constante de la clase Ingredientes
	*/


	class const_iterator{
		private:
			vector<Ingrediente*>::const_iterator it;	/**< const_iterator */
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

			const Ingrediente& operator * (){
				return (**it);
			}

			friend class Ingredientes;

	};

	/**
	   @brief Principio del vector alfabético de Ingredientes
	     
	   @return iterador al principio del vector alfabético de Ingredientes
	*/
	iterator begin();

	/**
	   @brief Final del vector alfabético de Ingredientes
	     
	   @return iterador al final del vector alfabético de Ingredientes
	*/
	iterator end();

	/**
	   @brief Principio del vector alfabético de Ingredientes (constante)
	     
	   @return iterador constante al principio del vector alfabético de Ingredientes
	*/
	const_iterator begin() const;

	/**
	   @brief Final del vector alfabético de Ingredientes (constante)
	     
	   @return iterador constante al final del vector alfabético de Ingredientes
	*/
	const_iterator end() const;

};

#endif
