#ifndef CONTENEDORESTRUCTURA_HPP
#define CONTENEDORESTRUCTURA_HPP

#include <iostream>
#include "estructura.hpp"
#include "elemento.hpp"
#include "pila.hpp"
#include "cola.hpp"
#include "lista.hpp"
using namespace std;

/*****Nombre********************************************************************************
 * ContenedorEstructura
 *****Descripción***************************************************************************
 * Es una clase que se encarga de contener las informaciones y acciones de las estructuras
 *****Atributos*****************************************************************************
 *Pila* apPrimeroPila
 *Cola* apPrimeroCola
 *Lista* apPrimero
 *int aCant
 *****Métodos******************************************************************************
 * ContenedorEstructura
 * void ingresarEstructura
 * void ingresarLista
 * void ingresarCola
 * void ingresarPila
 * void visualizarEstructuras
 * void visualizarEstadoEstructuras
 * void borrarEstructuraPila
 * void borrarEstructuraCola
 * void borrarEstructuraLista
 * void utilizarEstructura
 * bool compare
 * bool buscarEstructura
 ******************************************************************************************/
class ContenedorEstructura{

private:
	Pila* apPrimeroPila;
	Cola* apPrimeroCola;
	Lista* apPrimero;
	int aCant;

public:

	/*****Nombre***************************************************************************
	* ContenedorEstructura
	*****Descripción***********************************************************************
	* Es el constructor de la clase ContenedorEstructura
	*****Retorno***************************************************************************
	* 
	*****Entradas**************************************************************************

	***************************************************************************************/
	ContenedorEstructura(){
		apPrimeroPila = nullptr;
		apPrimeroCola = nullptr;
		apPrimero = nullptr;
		aCant = 0;
	}

	/*****Nombre****************************************************************************************************************
	 * ingresarEstructura
	 *****Descripción***********************************************************************************************************
	 * Se encarga de crear la estructura y verificar que tipo de estructura es para mandarla a su respectiva funcion de ingreso
	 *****Retorno***************************************************************************************************************
	 * 
	 *****Entradas**************************************************************************************************************
	* char *pNombre: Es el nombre de la estructura
	* char *pTipo: Es el tipo de la estructura
	* Elemento *pElemento: Es el elemento de la estructura
	* bool enlazamiento: Indica si quiere enlazamiento simple o doble en la estructura
	* bool circularidad: Indica si quiere circularidad en la estructura
	* bool insercionFin: Indica si quiere insercion al final de la estructura
	* bool insercionOrd: Indica si quiere insercion ordenada en la estructura
	 **********************************************************************/
	void ingresarEstructura(char* pNombre, char* pTipo, Elemento *pElemento, bool enlazamiento, bool circularidad, bool insercionFin, bool ordenado){
		Lista *nuevaLista;
		Cola *nuevaCola;
		Pila *nuevaPila;

		if(compare(pTipo,(char*)"Pila")){
			nuevaPila = new Pila(pNombre,pTipo,pElemento,enlazamiento,circularidad,insercionFin,ordenado);
			ingresarPila(nuevaPila);
		}else if (compare(pTipo,(char*)"Cola")){
			nuevaCola = new Cola(pNombre,pTipo,pElemento,enlazamiento,circularidad,insercionFin,ordenado);
			ingresarCola(nuevaCola);
		}else{
			nuevaLista = new Lista(pNombre,pTipo,pElemento,enlazamiento,circularidad,insercionFin,ordenado);
			ingresarLista(nuevaLista);
		}
	}

	/*****Nombre***********************************************************
	 * ingresarLista
	 *****Descripción******************************************************
	 * Se encarga de ingresar una estructura de tipo lista
	 *****Retorno**********************************************************
	 * 
	 *****Entradas*********************************************************
	 * Lista *pNuevo: Es la estructura de tipo lista a insertar
	 **********************************************************************/
	void ingresarLista(Lista *pNuevo){
		if (apPrimero == nullptr){
			apPrimero = pNuevo;
		} else {
			Lista *temp = apPrimero;
			while (temp->getSig() != nullptr){
				temp = temp->getSig();
			}
			temp->setSig(pNuevo);
		}
		aCant++;
	}

	/*****Nombre***********************************************************
	 * ingresarCola
	 *****Descripción******************************************************
	 * Se encarga de ingresar una estructura de tipo cola
	 *****Retorno**********************************************************
	 * 
	 *****Entradas*********************************************************
	 * Cola *pNuevo: Es la estructura de tipo cola a insertar
	 **********************************************************************/
	void ingresarCola(Cola *pNuevo){
		if (apPrimeroCola == nullptr){
			apPrimeroCola = pNuevo;
		} else {
			Cola *temp = apPrimeroCola;
			while (temp->getSig() != nullptr){
				temp = temp->getSig();
			}
			temp->setSig(pNuevo);
		}
		aCant++;
	}

	/*****Nombre***********************************************************
	 * ingresarPila
	 *****Descripción******************************************************
	 * Se encarga de ingresar una estructura de tipo pila
	 *****Retorno**********************************************************
	 * 
	 *****Entradas*********************************************************
	 * Pila *pNuevo: Es la estructura de tipo pila a insertar
	 **********************************************************************/
	void ingresarPila(Pila *pNuevo){
		if (apPrimeroPila == nullptr){
			apPrimeroPila = pNuevo;
		} else {
			Pila *temp = apPrimeroPila;
			while (temp->getSig() != nullptr){
				temp = temp->getSig();
			}
			temp->setSig(pNuevo);
		}
		aCant++;
	}

	/*****Nombre***********************************************************
	 * visualizarEstructuras
	 *****Descripción******************************************************
	 * Se encarga de mostrar las estructuras en consola
	 *****Retorno**********************************************************
	 * 
	 *****Entradas*********************************************************
	 *
	 **********************************************************************/
	void visualizarEstructuras(){
		cout<<"\n[	VISUALIZANDO ESTRUCTURAS 	]\n";
		
		Lista *tempLista = apPrimero;
		Cola *tempCola = apPrimeroCola;
		Pila *tempPila = apPrimeroPila; 
		int i = 0;
		
		while (tempLista != nullptr){
			cout<<"\n["<<i++<<"] => "<<tempLista->getNombre()<<endl;
			//tempLista->mostrarElementos()
			tempLista = tempLista->getSig();
		}

		while (tempCola != nullptr){
			cout<<"\n["<<i++<<"] => "<<tempCola->getNombre()<<endl;
			//tempCola->mostrarElementos();
			tempCola = tempCola->getSig();
		}

		while (tempPila != nullptr){
			cout<<"\n["<<i++<<"] => "<<tempPila->getNombre()<<endl;
			//tempPila->mostrarElementos();
			tempPila = tempPila->getSig();
		}
	}

	/*****Nombre***********************************************************
	 * visualizarEstadoEstructuras
	 *****Descripción******************************************************
	 * Se encarga de mostrar todo lo relacionado con las estructuras
	 *****Retorno**********************************************************
	 * 
	 *****Entradas*********************************************************
	 *
	 **********************************************************************/
	void visualizarEstadoEstructuras(){
		cout<<"\n[	VISUALIZANDO ESTRUCTURAS 	]\n";
		
		Lista *tempLista = apPrimero;
		Cola *tempCola = apPrimeroCola;
		Pila *tempPila = apPrimeroPila; 
		int i = 0;
		
		while (tempLista != nullptr){
			cout<<"\n["<<i++<<"] => "<<tempLista->getNombre()<<endl;
			//tempLista->mostrarElementos()
			tempLista = tempLista->getSig();
		}

		while (tempCola != nullptr){
			cout<<"\n["<<i++<<"] => "<<tempCola->getNombre()<<endl;
			tempCola->getElemento()->mostrarAtributos();
			tempCola->mostrarElementos();
			tempCola = tempCola->getSig();
		}

		while (tempPila != nullptr){
			cout<<"\n["<<i++<<"] => "<<tempPila->getNombre()<<endl;
			tempPila->getElemento()->mostrarAtributos();
			tempPila->mostrarElementos();
			tempPila = tempPila->getSig();
		}
	}

	/*****Nombre***********************************************************
	 * borrarEstructuraPila
	 *****Descripción******************************************************
	 * Se encarga de eliminar una estructura de tipo pila
	 *****Retorno**********************************************************
	 * 
	 *****Entradas*********************************************************
	 * char* pEliminar: Es el nombre de la estructura a eliminar
	 **********************************************************************/
	void borrarEstructuraPila(char* pEliminar){
        Pila *pBorrado = apPrimeroPila;
        Pila *pAnterior = nullptr;

        while (pBorrado != nullptr) {
            if (compare (pEliminar, pBorrado->getNombre()))
                break;
            pAnterior = pBorrado;
            pBorrado = pBorrado->getSig();
        }

        if (pBorrado != nullptr) {
        	if (pBorrado->getPrimero() == nullptr){
	            if (pAnterior != nullptr)
	                pAnterior->setSig(pBorrado->getSig ());
	            else apPrimeroPila = pBorrado->getSig ();
	            pBorrado->setSig (nullptr);
	            aCant--;
	            cout<<"\nSe elimino la estructura "<<pBorrado->getNombre();
	        } else {
	        	cout<<"\nNo se puede eliminar la estructura, tiene elementos"<<endl;
	        }
        }else{
            borrarEstructuraCola(pEliminar);
        }
    }

	/*****Nombre***********************************************************
	 * borrarEstructuraCola
	 *****Descripción******************************************************
	 * Se encarga de eliminar una estructura de tipo Cola
	 *****Retorno**********************************************************
	 * 
	 *****Entradas*********************************************************
	 * char* pEliminar: Es el nombre de la estructura a eliminar
	 **********************************************************************/
    void borrarEstructuraCola(char* pEliminar){
        Cola *pBorrado = apPrimeroCola;
        Cola *pAnterior = nullptr;

        while (pBorrado != nullptr) {
            if (compare (pEliminar, pBorrado->getNombre()))
                break;
            pAnterior = pBorrado;
            pBorrado = pBorrado->getSig();
        }

        if (pBorrado != nullptr) {
        	if (pBorrado->getPrimero() == nullptr){
	            if (pAnterior != nullptr)
	                pAnterior->setSig(pBorrado->getSig ());
	            else apPrimeroCola = pBorrado->getSig ();
	            pBorrado->setSig (nullptr);
	            aCant--;
	            cout<<"\nSe elimino la estructura "<<pBorrado->getNombre();
	        } else {
	        	cout<<"\nNo se puede eliminar la estructura, tiene elementos"<<endl;
	        }
        }else{
            borrarEstructuraLista(pEliminar);
        }
    }

	/*****Nombre***********************************************************
	 * borrarEstructuraLista
	 *****Descripción******************************************************
	 * Se encarga de eliminar una estructura de tipo lista
	 *****Retorno**********************************************************
	 * 
	 *****Entradas*********************************************************
	 * char* pEliminar: Es el nombre de la estructura a eliminar
	 **********************************************************************/
    void borrarEstructuraLista(char* pEliminar){
        Lista *pBorrado = apPrimero;
        Lista *pAnterior = nullptr;

        while (pBorrado != nullptr) {
            if (compare (pEliminar, pBorrado->getNombre()))
                break;
            pAnterior = pBorrado;
            pBorrado = pBorrado->getSig();
        }

        if (pBorrado != nullptr) {
            if (pAnterior != nullptr)
                pAnterior->setSig(pBorrado->getSig ());
            else apPrimero = pBorrado->getSig ();
            pBorrado->setSig (nullptr);
            aCant--;
            cout<<"\nSe elimino la estructura "<<pBorrado->getNombre();
        }else{
            cout<<"\nLa estructura que desea eliminar no existe\n";
        }
    }

	/*****Nombre**************************************************************************
	 * utilizarEstructura
	 *****Descripción*********************************************************************
	 * Se encarga de verificar el tipo de la estructura para mandarlo al menu respectivo
	 *****Retorno*************************************************************************
	 * 
	 *****Entradas************************************************************************
	 * char* pNombre: Es el nombre de la estructura
	 *************************************************************************************/
	void utilizarEstructura(char* pNombre){
		if (buscarEstructura(pNombre)){
			Lista *tempLista = apPrimero;
			Cola *tempCola = apPrimeroCola;
			Pila *tempPila = apPrimeroPila;

			while (tempLista != nullptr){
				if (compare(tempLista->getNombre(),pNombre)){
					tempLista->menuLista();
					break;
				}
				tempLista = tempLista->getSig();
			}
			while (tempCola != nullptr){
				if (compare(tempCola->getNombre(),pNombre)){
					tempCola->menuCola();
					break;
				}
				tempCola = tempCola->getSig();
			}
			while (tempPila != nullptr){
				if (compare(tempPila->getNombre(),pNombre)){
					tempPila->menuPila();
					break;
				}
				tempPila = tempPila->getSig();
			}
		}else{
			cout<<"\nLa estructura que ingreso no existe"<<endl;
		}
	}

	/*****Nombre***************************************
	 * compare
	 *****Descripción**********************************
	 * compara la totalidad de dos char*
	 *****Retorno**************************************
	 * un booleano de la comparacion total de dos char*
	 *****Entradas*************************************
	 * char *s1, char *s2
	 **************************************************/
	bool compare (char *s1, char *s2) {
		int i = 0;
		while (s1[i] != '\0' || s2[i] != '\0') {
			if (s1[i] != s2[i])
				break;
			i++;
		}
		if (s1[i] == '\0' && s2[i] == '\0')
			return true;
		return false;
	}

	/*****Nombre***********************************************************
	 * buscarEstructura
	 *****Descripción******************************************************
	 * Se encarga de verificar si la estructura existe
	 *****Retorno**********************************************************
	 * Retorna true si la estructura existe de lo contrario retorna false
	 *****Entradas*********************************************************
	 * char* pNombre: Es el nombre de la estructura a verificar
	 **********************************************************************/
	bool buscarEstructura(char* pNombre){
		Lista *tempLista = apPrimero;
		Cola *tempCola = apPrimeroCola;
		Pila *tempPila = apPrimeroPila; 

		if (tempLista != nullptr){
			while (tempLista != nullptr){
				if (compare(tempLista->getNombre(),pNombre)){
					return true;
				}
				tempLista = tempLista->getSig();
			}
		} 
		if (tempCola != nullptr){
			while (tempCola != nullptr){
				if (compare(tempCola->getNombre(),pNombre)){
					return true;
				}
				tempCola = tempCola->getSig();
			}
		}
		if (tempPila != nullptr) {
			while (tempPila != nullptr){
				if (compare(tempPila->getNombre(),pNombre)){
					return true;
				}
				tempPila = tempPila->getSig();
			}
		}
		return false;
	}

};
#endif