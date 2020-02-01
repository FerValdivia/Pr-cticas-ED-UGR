// Fernando Valdivia del Rosal

#include <iostream>
#include "ingrediente.h"
#include "ingredientes.h"
#include "instrucciones.h"
#include "receta.h"
#include "recetas.h"
#include "color.h"
#include <fstream>
using namespace std;

void MuestraParametros(){
	cout<<"Args: acciones  recetas  ingredientes  ruta_instrucciones\n"<<endl;
}





void CalculoNutrientes(Receta& receta, const Ingredientes& ingredientes){

	float calorias = 0;
	float hc = 0;
	float grasas = 0;
	float proteinas = 0;
	float fibra = 0;
	string nombre;
	unsigned int cantidad;

	Receta::iterator it;

	// Vemos los nutrientes de cada ingrediente y los vamos sumando

	for (it = receta.begin(); it != receta.end(); it++){
		nombre = (*it).first;
		cantidad = (*it).second;

		Ingrediente ingr = ingredientes.get(nombre);

		if (ingr.getNombre() != "Undefined"){

			calorias += (ingr.getCalorias()*cantidad) / 100;
	
			hc += (ingr.getHc()*cantidad) / 100;
	
			grasas += (ingr.getGrasas()*cantidad) / 100;
	
			proteinas += (ingr.getProteinas()*cantidad) / 100;
	
			fibra += (ingr.getFibra()*cantidad) / 100;
		}
	}

	receta.setCalorias(calorias);
	receta.setHc(hc);
	receta.setGrasas(grasas);
	receta.setProteinas(proteinas);
	receta.setFibra(fibra);

}



int main (int argc, char* argv[]){

	if (argc != 5){
		MuestraParametros();
		return 0;
	}


	// Lectura de ingredientes
	string nf =argv[3];
	ifstream f(nf);
	if (!f){
		cout << "No puedo abrir " << nf << endl;
		return 0;
	}

	string linea;
	getline(f,linea);

	Ingredientes ingredientes;
	cout << "Lectura de todos los ingredientes" << endl;
	f >> ingredientes;


	// Lectura de recetas

	nf =argv[2];
	ifstream f2(nf);
	if (!f2){
		cout << "No puedo abrir " << nf << endl;
		return 0;
	}

	Recetas rall;
	cout << "Lectura de todas las recetas" << endl;
	f2 >> rall;


	// Lectura de las acciones

	nf = argv[1];
	ifstream f_acc(nf);
	if (!f_acc){
		cout << "No puedo abrir " << nf << endl;
		return 0;
	}

	acciones acc;
	cout << "Lectura de todas las acciones" << endl;
	f_acc >> acc;


	// Mostrar recetas

	cout << "Las recetas son:" << endl;
	cout << rall;
	

	// Mostramos información de una receta escogida

	string codigo;
	cout << "\n\nIntroduzca el código de una receta: ";
	cin >> codigo;
	Receta* receta = &rall[codigo];					// Usamos un puntero a la receta concreta para evitar hacer cada acceso con rall[codigo]
									// ya que este implica buscarlo cada vez en el map de la clase Recetas

	if (receta->getNombre() != "Undefined"){
		CalculoNutrientes(*receta, ingredientes);
		cout << *receta;


		// Lectura de instrucciones de la receta escogida
		string archivo = argv[4] + receta->getCode() + "m.txt";
		ifstream f3(archivo);
		if (!f3){
			cout << "No puedo abrir " << archivo << endl;
			return 0;
		}

		instrucciones instr(acc);
		cout << "\nInicio lectura de las instrucciones " << archivo << endl;
		f3 >> instr;

		receta->setInstrucciones(instr);

		cout << UNDL(BOLD("Pasos a seguir:")) << endl;
		cout << receta->getInstrucciones() << endl;

	}
	else{
		cout << "No existe el código de la receta." << endl;
		return 0;
	}



	// FUSIONAR DOS RECETAS

	string codigo2;
	Receta receta1, receta2;

	cout << "Introduzca dos códigos de receta: " << endl;
	cin >> codigo >> codigo2;

	receta1 = rall[codigo];
	receta2 = rall[codigo2];

	if (receta1.getNombre() == "Undefined" || receta2.getNombre() == "Undefined"){
		cout << "Código incorrecto." << endl;
		return 0;
	}

	string code = "F_" + receta1.getCode() + "_" + receta2.getCode();
	string nombre = receta1.getNombre() + " y " + receta2.getNombre();

	// Fusionar ingredientes

	list< pair<string,unsigned int> > ingr_fusion;

	ingr_fusion = receta1.getIngredientes();			// Añadimos todos los ingredientes de la receta 1

	list< pair<string,unsigned int> >::iterator it_rf;
	Receta::iterator it_r2;
	bool insertado;

	for (it_r2 = receta2.begin(); it_r2 != receta2.end(); it_r2++){
		insertado = false;

		for (it_rf = ingr_fusion.begin(); it_rf != ingr_fusion.end() && !insertado; it_rf++){
			if ((*it_r2).first == (*it_rf).first){				// Si es el mismo ingrediente sumamos sus cantidades
				(*it_rf).second += (*it_r2).second;
				insertado = true;
			}
		}

		if (!insertado){							// Si no se estaba ya el mismo ingrediente se inserta como uno nuevo
			ingr_fusion.push_back(*it_r2);
		}
	}

	// Creamos la receta fusión

	Receta r_fusion (code, receta1.getPlato(), nombre, ingr_fusion);


	// Unir instrucciones


	// Lectura de instrucciones de la primera receta receta
	string archivo_r1 = argv[4] + receta1.getCode() + "m.txt";
	ifstream fr1(archivo_r1);
	if (!fr1){
		cout << "No puedo abrir " << archivo_r1 << endl;
		return 0;
	}

	instrucciones instr1;
	fr1 >> instr1;

	receta1.setInstrucciones(instr1);


	// Lectura de instrucciones de la primera receta receta
	string archivo_r2 = argv[4] + receta2.getCode() + "m.txt";
	ifstream fr2(archivo_r2);
	if (!fr2){
		cout << "No puedo abrir " << archivo_r2 << endl;
		return 0;
	}

	instrucciones instr2;
	fr2 >> instr2;

	receta1.setInstrucciones(instr2);

	ArbolBinario<string> arbol1, arbol2;

	arbol1 = instr1.getDatos();
	arbol2 = instr2.getDatos();


	ArbolBinario<string> arbol_fusion ("Acompañar");
	arbol_fusion.Insertar_Hi(arbol_fusion.getRaiz(), arbol1);
	arbol_fusion.Insertar_Hd(arbol_fusion.getRaiz(), arbol2);

	instrucciones instr_fusion;
	instr_fusion.setDatos(arbol_fusion);

	r_fusion.setInstrucciones(instr_fusion);



	// Mostramos la receta

	CalculoNutrientes(r_fusion, ingredientes);
	cout << "La receta fusión es:\n" << r_fusion << endl;

	cout << UNDL(BOLD("Pasos a seguir:")) << endl;

	r_fusion.setInstrucciones(instr_fusion);

	cout << r_fusion.getInstrucciones();


}
