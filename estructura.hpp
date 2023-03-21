#ifndef ESTRUCTURA_HPP
#define ESTRUCTURA_HPP

#include <iostream>
#include "elemento.hpp"
using namespace std;

/*****Nombre*****************************************************************
 * Estructura
 *****Descripción************************************************************
 * Es la clase que se encarga de administrar las estructuras
 *****Atributos**************************************************************
 * char *apNombre;
 * char *apTipo;
 * Elemento *apElemento;
 * Elemento *apPrimero;
 * bool aEnlazamiento;
 * bool aCircularidad;
 * bool aInsercionFin;
 * bool aInsercionOrd;
 * Estructura *apSig;
 *****Métodos****************************************************************
 * AtributoChar
 ****************************************************************************/
class Estructura{
	private:
		char *apNombre;
		char *apTipo;
		Elemento *apElemento;
		Elemento *apPrimero;
		bool aEnlazamiento;
		bool aCircularidad;
		bool aInsercionFin;
		bool aInsercionOrd;
		Estructura *apSig;
	public:

		/*****Nombre***************************************************************************
		* Estructura
		*****Descripción***********************************************************************
		* Es el constructor de la clase Estructura
		*****Retorno***************************************************************************
		* 
		*****Entradas**************************************************************************
		 * char *pNombre: Es el nombre de la estructura
		 * char *pTipo: Es el tipo de la estructura
		 * Elemento *pElemento: Es el elemento de la estructura
		 * bool enlazamiento: Indica si quiere enlazamiento simple o doble en la estructura
		 * bool circularidad: Indica si quiere circularidad en la estructura
		 * bool insercionFin: Indica si quiere insercion al final de la estructura
		 * bool insercionOrd: Indica si quiere insercion ordenada en la estructura
		***************************************************************************************/
		Estructura(char *pNombre, char *pTipo, Elemento *pElemento, bool enlazamiento, bool circularidad, bool insercionFin, bool insercionOrd){
			apNombre = pNombre;
			apTipo = pTipo;
			apElemento = pElemento;
			apPrimero = nullptr;
			aEnlazamiento = enlazamiento;
			aCircularidad = circularidad;
			aInsercionFin = insercionFin;
			aInsercionOrd = insercionOrd;
			apSig = nullptr;
		}

		char* getNombre(){
			return apNombre;
		}

		char* getTipo(){
			return apTipo;
		}

		Elemento* getElemento(){
			return apElemento;
		}

		Elemento* getPrimero(){
			return apPrimero;
		}

		bool getEnlazamiento(){
			return aEnlazamiento;
		}

		bool getCircularidad(){
			return aCircularidad;
		}

		bool getInsercionFin(){
			return aInsercionFin;
		}

		bool getInsercionOrd(){
			return aInsercionOrd;
		}

		Estructura* getSig(){
			return apSig;	
		}

		void setSig(Estructura *sig){
			apSig = sig;
		}

		void setPrimero(Elemento *primero){
			apPrimero = primero;
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
};
#endif
