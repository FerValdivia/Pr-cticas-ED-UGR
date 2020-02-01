// Fernando Valdivia del Rosal

/**
  * @file ingrediente.h
  * @brief Fichero cabecera del TDA Ingrediente
  *
  */

#ifndef _INGREDIENTE_H_
#define _INGREDIENTE_H_

#include <iostream>
#include <string>
using namespace std;


/**
  *  @brief T.D.A. Ingrediente
  *
  * Una instancia @e c del tipo de datos abstracto @c Ingrediente es un objeto
  * de un tipo de alimento cuyos parámetros son nombre, tipo, calorías, hidratos
  * proteinas, grasas y fibra.
  *
  * Un ejemplo de su uso:
  * @include test_ingredientes.cpp
  *
  * @author Fernando Valdivia
  * @date Octubre 2019
  */



class Ingrediente
{
	private:
	  /**
	  * @page repIngrediente Rep del TDA Ingrediente
	  *
	  * @section invIngrediente Invariante de la representación
	  *
	  * El invariante es que el nombre no sea vacío, rep.calorias > 0, 0 <= rep.hidratos <= 100, 0 <= rep.proteinas <= 100, 0 <= rep.grasas <= 100,
	  * 0 <= rep.fibra <= 100, rep.tipo puede ser cualquier cadena string
	  *
	  * @section faIngrediente Función de abstracción
	  *
	  * Un objeto válido @e rep del TDA Ingrediente representa una 7-tupla en la que se encuentra el nombre del ingrediente, el tipo, las calorías por
	  * cada 100 gramos, porcentaje de hidratos, proteinas, grasas y fibra.
	  *
	  * (rep.nombre,rep.tipo,rep.calorias,rep.hidratos,rep.proteinas,rep.grasas,rep.fibra)
	  *
	  */
		string nombre;		/**< nombre */
		string tipo;		/**< tipo */
		float calorias;		/**< calorias por cada 100 g */
		float hidratos;		/**< porcentaje hidratos */
		float proteinas;	/**< porcentaje proteínas */
		float grasas;		/**< porcentaje grasas */
		float fibra;		/**< porcentaje fibra */


	public:

		/**
			@brief Constructor de Ingrediente

			@pre Las cantidades no pueden ser negativas

			@param nomb: nombre
			@param cal: calorias
			@param hb: hidratos de carbono
			@param prot: proteinas
			@param gras: grasas
			@param fibr: fibra
			@param tipo_ingr: tipo
		*/
		
		Ingrediente (string nomb, float cal, float hb, float prot, float gras, float fibr, string tipo_ingr);
		

		/**
			@brief Constructor de Ingrediente sin parámetros
		*/

		Ingrediente();


		/**
			@brief Obtener nombre de Ingrediente

			@return nombre
		*/

		string getNombre () const;


		/**
			@brief Obtener calorías de Ingrediente

			@return calorias
		*/

		float getCalorias () const;


		/**
			@brief Obtener hidratos de carbono de Ingrediente

			@return hidratos
		*/

		float getHc () const;


		/**
			@brief Obtener proteínas de Ingrediente

			@return proteinas
		*/

		float getProteinas () const;


		/**
			@brief Obtener grasas de Ingrediente

			@return grasas
		*/

		float getGrasas () const;


		/**
			@brief Obtener fibra de Ingrediente

			@return fibra
		*/

		float getFibra () const;


		/**
			@brief Obtener tipo de Ingrediente

			@return tipo
		*/

		string getTipo () const;


		/**
			@brief Sobrecarga del operador >>
			@param is stream de entrada
			@param i Ingrediente que recibe valores
			@return is stream de entrada
		*/

		friend istream & operator >> (istream & is, Ingrediente & i);


		/**
			@brief Sobrecarga del operador <<
			@param out stream de salida
			@param i Ingrediente a escribir
			@return os stream de salida
		*/

		friend ostream & operator << (ostream & out, const Ingrediente & i);


		/**
			@brief Modificar nombre de Ingrediente

			@param nomb: nuevo nombre
		*/

		void setNombre (string nomb);


		/**
			@brief Modificar calorías de Ingrediente

			@param cal: nuevo valor de calorias
			@pre  cal >= 0
		*/

		void setCalorias (float cal);


		/**
			@brief Modificar hidratos de carbono de Ingrediente

			@param hb: nuevo valor de hidratos
			@pre  hb >= 0  y  hb <= 100
		*/

		void setHidratos (float hb);


		/**
			@brief Modificar proteínas de Ingrediente

			@param prot: nuevo valor de proteinas
			@pre  prot >= 0  y  prot <= 100
		*/

		void setProteinas (float prot);


		/**
			@brief Modificar grasas de Ingrediente

			@param gras: nuevo valor de grasas
			@pre  gras >= 0  y  gras <= 100
		*/

		void setGrasas (float gras);


		/**
			@brief Modificar fibra de Ingrediente

			@param fibr: nuevo valor de fibra
			@pre  fibr >= 0  y  fibr <= 100
		*/

		void setFibra (float fibr);


		/**
			@brief Modificar tipo de Ingrediente

			@param tipo_ingr: string con el nuevo tipo
		*/

		void setTipo (string tipo_ingr);


};

#endif
