// Fernando Valdivia del Rosal

#ifndef _RECETA_H_
#define _RECETA_H_

#include <string>
#include <list>
#include <iostream>
#include "instrucciones.h"
using namespace std;

class Receta{

	private:

		string code;							/**< código */
		unsigned int plato;						/**< plato */
		string nombre;							/**< nombre */
		list< pair<string,unsigned int> > ings;				/**< ingredientes y cantidad */
		float calorias, hc, grasas, proteinas, fibra;			/**< calorias, hidratos de carbono, grasas, proteinas, fibra */
		instrucciones inst;						/**< instrucciones */

	public:

		/**
			@brief Constructor de Receta sin parámetros
		*/
		
		Receta();


		/**
			@brief Constructor de Receta

			@pre Las cantidades de los ings no pueden ser negativas y plat debe ser 1, 2 o 3

			@param cod: code
			@param plat: plato
			@param nomb: nombre
			@param ingr: ings
		*/

		Receta(string cod, unsigned int plat, string nomb, list<pair<string,unsigned int>> ingr);


		/**
			@brief Sobrecarga del operador >>
			@param is stream de entrada
			@param r Receta que recibe valores
			@return is stream de entrada
		*/

		friend istream & operator >> (istream & is, Receta & r);


		/**
			@brief Sobrecarga del operador <<
			@param out stream de salida
			@param r Receta a escribir
			@return os stream de salida
		*/

		friend ostream & operator << (ostream & out, const Receta & r);


		/**
			@brief Obtener nombre de Receta

			@return nombre
		*/

		string getNombre () const;


		/**
			@brief Obtener code de Receta

			@return code
		*/

		string getCode () const;


		/**
			@brief Obtener plato de Receta

			@return plato
		*/

		unsigned int getPlato () const;


		/**
			@brief Obtener calorías de Receta

			@return calorias
		*/

		float getCalorias () const;


		/**
			@brief Obtener hidratos de carbono de Receta

			@return hidratos
		*/

		float getHc () const;


		/**
			@brief Obtener proteínas de Receta

			@return proteinas
		*/

		float getProteinas () const;


		/**
			@brief Obtener grasas de Receta

			@return grasas
		*/

		float getGrasas () const;


		/**
			@brief Obtener fibra de Receta

			@return fibra
		*/

		float getFibra () const;


		/**
			@brief Obtener ingredientes de Receta (por copia)

			@return ings (copia)
		*/

		list< pair<string,unsigned int> > getIngredientes () const;


		/**
			@brief Modificar calorías de Receta

			@param cal: nuevo valor de clorías
			@pre  cal >= 0
		*/

		void setCalorias(float cal);


		/**
			@brief Modificar hc de Receta

			@param hidratos: nuevo valor de hc
			@pre  hidratos >= 0
		*/

		void setHc(float hidratos);


		/**
			@brief Modificar grasas de Receta

			@param gras: nuevo valor de grasas
			@pre  gras >= 0
		*/

		void setGrasas(float gras);


		/**
			@brief Modificar proteinas de Receta

			@param prot: nuevo valor de proteinas
			@pre  prot >= 0
		*/

		void setProteinas(float prot);


		/**
			@brief Modificar fibra de Receta

			@param fibr: nuevo valor de fibra
			@pre  fibr >= 0
		*/

		void setFibra(float fibr);


		/**
			@brief Obtener numero ingredietes de la receta
		*/

		int ningredientes ();


		/**
			@brief Modificar instrucciones

			@param instrucciones: objeto de la clase instrucciones
		*/

		void setInstrucciones (instrucciones& instr);


		/**
			@brief Obtener insturcciones
		*/

		instrucciones& getInstrucciones ();


		/**
		   @brief Iterador de la clase Receta
		*/

		typedef list< pair<string,unsigned int> >::iterator iterator;


		/**
		   @brief Iterador constante de la clase Receta
		*/

		typedef list< pair<string,unsigned int> >::const_iterator const_iterator;

		/**
		   @brief Principio del vector alfabético de Receta
		     
		   @return iterador al principio del vector alfabético de Receta
		*/
		iterator begin();

		/**
		   @brief Final del vector alfabético de Receta
		     
		   @return iterador al final del vector alfabético de Receta
		*/
		iterator end();

		/**
		   @brief Principio del vector alfabético de Receta (constante)
		     
		   @return iterador constante al principio del vector alfabético de Receta
		*/
		const_iterator begin() const;

		/**
		   @brief Final del vector alfabético de Receta (constante)
		     
		   @return iterador constante al final del vector alfabético de Receta
		*/
		const_iterator end() const;
};

#endif
