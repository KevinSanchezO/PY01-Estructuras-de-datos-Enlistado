#ifndef CONTENEDORELEMENTO_HPP
#define CONTENEDORELEMENTO_HPP

#include <iostream>
#include "elemento.hpp"
using namespace std;

/*****Nombre*******************************************************************************
 * ContenedorElemento
 *****Descripción**************************************************************************
 * Es una clase que se encarga de contener las informaciones y acciones de los elementos
 *****Atributos****************************************************************************
 * Elemento *apPrimero
 * int aCantidad
 *****Métodos******************************************************************************
 * ContenedorElemento 
 * void crearElemento
 * void ingresarElemento
 * bool buscarElemento
 * Elemento* encontrarElemento
 * void visualizarElementos
 ******************************************************************************************/
class ContenedorElemento{
private:
	Elemento *apPrimero;
	int aCantidad;
public:
	/*****Nombre***************************************
	 * ContenedorElemento
	 *****Descripción**********************************
	 * Es el constructor de la clase ContenedorElemento
	 *****Retorno**************************************
	 * 
	 *****Entradas*************************************
	 * 
	 **************************************************/	
	ContenedorElemento(){
		aCantidad = 0;
		apPrimero = nullptr;
	}

	/*****Nombre***************************************
	 * crearElemento
	 *****Descripción**********************************
	 * Se encarga de la creacion de un elemento 
	 *****Retorno**************************************
	 * 
	 *****Entradas*************************************
	 * 
	 **************************************************/
	void crearElemento(){
		char* nombre;
		int id;
		nombre = (char*) malloc(100*sizeof(char));
		cout<<"\n[          CREACION DE ELEMENTOS          ]"<<endl;
		cout<<"\nIngrese el nombre del elemento\n>>";
		cin>>nombre;
		do{
			srand (time(NULL));
			id = rand()%99999;
		}while(buscarElemento(id));
		ingresarElemento(nombre, id);
	}

	/*****Nombre******************************************************************
	 * ingresarElemento
	 *****Descripción*************************************************************
	 * Es la auxiliar del metodo crearElemento para terminar de crear el elemento
	 *****Retorno*****************************************************************
	 * 
	 *****Entradas****************************************************************
	 * char* pNombre: El nombre que el usuario le dio al elemento
	 * int aID: El identificador del elemento
	 *****************************************************************************/
	void ingresarElemento(char* pNombre, int aID){
		Elemento *nuevo = new Elemento(pNombre, aID);
		if (apPrimero == nullptr)
			apPrimero = nuevo;
		else{
			Elemento *temp = apPrimero;
			while (temp->getSig () != nullptr)
				temp = temp->getSig ();
			temp->setSig (nuevo);
		}
		nuevo->ingresarAtributos();
	}

	/*****Nombre**************************************************************************
	 * buscarElemento
	 *****Descripción*********************************************************************
	 * Se encarga de verificarr si el elemento ingresado existe mediante su identificador
	 *****Retorno*************************************************************************
	 * Retorna true si el elemento existe de lo contrario retorna false
	 *****Entradas************************************************************************
	 * int id: El identificador de elemento 
	 *************************************************************************************/
	bool buscarElemento(int id){
		Elemento *temp = apPrimero;
		while (temp != NULL){
			if (temp->getIdentificador() == id){
				return true;
			}
			temp = temp->getSig();
		}
		return false;
	}

	/*****Nombre**************************************************************************
	 * encontrarElemento
	 *****Descripción*********************************************************************
	 * Se encarga de encontrar un elemento
	 *****Retorno*************************************************************************
	 * Retorna el elemento al que se esta buscando
	 *****Entradas************************************************************************
	 * int id: El identificador de elemento 
	 *************************************************************************************/
	Elemento* encontrarElemento(int id){
		Elemento *temp = apPrimero;
		while (temp != NULL){
			if (temp->getIdentificador() == id){
				return temp;
			}
			temp = temp->getSig();
		}
		return temp;
	}

	/*****Nombre***************************************
	 * visualizarElementos
	 *****Descripción**********************************
	 * Se encarga de mostrar los elementos en consola
	 *****Retorno**************************************
	 * 
	 *****Entradas*************************************
	 * 
	 **************************************************/
	void visualizarElementos(){
		cout<<"\n[      VISUALIZANDO ELEMENTOS      ]"<<endl;
		Elemento *temp = apPrimero;
		while (temp != nullptr){
			cout<<"\n["<<temp->getIdentificador()<<"] => "<<temp->getNombre()<<endl;
			temp->mostrarAtributos();
			temp = temp->getSig();
		}
	}

};
#endif