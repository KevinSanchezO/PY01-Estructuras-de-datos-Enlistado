#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

#include <iostream>
#include "atributoint.hpp"
#include "atributochar.hpp"
#include "atributobool.hpp"
using namespace std;

/*****Nombre***********************************************
 * Elemento
 *****Descripción******************************************
 * Es la clase que se encarga de administrar los elementos
 *****Atributos********************************************
 * int aIdentificador 
 * char* apNombre
 * AtributoInt *apPrimerInt
 * AtributoChar *apPrimerChar
 * AtributoBool *apPrimerBool
 * Elemento *apSig
 * Elemento *apAnt
 *****Métodos**********************************************
 * Elemento
 * void mostrarAtributos
 * void mostrarAtributosEstructura
 * void ingresarAtributoInt
 * void ingresarAtributoAlfa
 * void ingresarAtributoBooleano
 * bool compare
 * void ingresarAtributos
 * void ingresarCopiaInt
 * void ingresarCopiaChar
 * void ingresarCopiaBool
 **********************************************************/
class Elemento{
private:
	int aIdentificador;
	char* apNombre;
	AtributoInt *apPrimerInt;
	AtributoChar *apPrimerChar;
	AtributoBool *apPrimerBool;
	Elemento *apSig;
	Elemento *apAnt;
public:
	/*****Nombre***************************************
	 * Elemento
	 *****Descripción**********************************
	 * Es el constructor de la clase Elemento
	 *****Retorno**************************************
	 * 
	 *****Entradas*************************************
	 * char* pNombre: Es el nombre del elemento
	 * int id: Es el identificador del elemento
	 **************************************************/
	Elemento(char* pNombre, int id){
		aIdentificador = id;
		apNombre = pNombre;
		apPrimerInt = nullptr;
		apPrimerChar = nullptr;
		apPrimerBool = nullptr;
		apSig = nullptr;
	}

	/*****Nombre***************************************
	 * mostrarAtributos
	 *****Descripción**********************************
	 * Se encarga de mostrar los atributos en consola
	 *****Retorno**************************************
	 * 
	 *****Entradas*************************************
	 * 
	 **************************************************/
	void mostrarAtributos(){
		AtributoInt *tempInt = apPrimerInt;
		while(tempInt != nullptr){
			cout<<"Tipo de atributo: "<<tempInt->getTipo()<<" | Tipo de acceso: "<<tempInt->getAcceso()<<" | Tamaño: "<<tempInt->getSize()<<endl;
			tempInt = tempInt->getSig();
		}

		AtributoChar *tempChar = apPrimerChar;
		while(tempChar != nullptr){
			cout<<"Tipo de atributo: "<<tempChar->getTipo()<<" | Tipo de acceso: "<<tempChar->getAcceso()<<" | Tamaño: "<<tempChar->getSize()<<endl;
			tempChar = tempChar->getSig();
		}

		AtributoBool *tempBool = apPrimerBool;
		while(tempBool != nullptr){
			cout<<"Tipo de atributo: "<<tempBool->getTipo()<<" | Tipo de acceso: "<<tempBool->getAcceso()<<" | Tamaño: "<<tempBool->getSize()<<endl;	
			tempBool = tempBool->getSig();
		}
	}

	/*****Nombre***********************************************
	 * mostrarAtributosEstructura
	 *****Descripción******************************************
	 * Se encarga de mostrar los atributos de la estructura
	 *****Retorno**********************************************
	 * 
	 *****Entradas*********************************************
	 * 
	 **********************************************************/
	void mostrarAtributosEstructura(){
		AtributoInt *tempInt = apPrimerInt;
		while(tempInt != nullptr){
			cout<<"Tipo de atributo: "<<tempInt->getTipo()<<" | Dato: "<<tempInt->getDato()<<" | Tipo de acceso: "<<tempInt->getAcceso()<<" | Tamaño: "<<tempInt->getSize()<<endl;
			tempInt = tempInt->getSig();
		}

		AtributoChar *tempChar = apPrimerChar;
		while(tempChar != nullptr){
			cout<<"Tipo de atributo: "<<tempChar->getTipo()<<" | Dato: "<<tempChar->getDato()<<" | Tipo de acceso: "<<tempChar->getAcceso()<<" | Tamaño: "<<tempChar->getSize()<<endl;
			tempChar = tempChar->getSig();
		}

		AtributoBool *tempBool = apPrimerBool;
		while(tempBool != nullptr){
			cout<<"Tipo de atributo: "<<tempBool->getTipo()<<" | Dato: "<<tempBool->getDato()<<" | Tipo de acceso: "<<tempBool->getAcceso()<<" | Tamaño: "<<tempBool->getSize()<<endl;	
			tempBool = tempBool->getSig();
		}
	}

	/*****Nombre***************************************
	 * ingresarAtributoInt
	 *****Descripción**********************************
	 * Se encarga de ingresar atributos de tipo entero
	 *****Retorno**************************************
	 * 
	 *****Entradas*************************************
	 * 
	 **************************************************/
	void ingresarAtributoInt(){
		int max=0;
		int dato=0;
		char *modoAcceso;
		modoAcceso=(char*) malloc(2*sizeof(char));

		cout<<"\n[     INGRESANDO ATRIBUTO ENTERO     ]"<<endl;
		cout<<"\nIngrese el maximo\n>>";
		cin>>max;
		cout<<"\nIngrese el modo de acceso [r.Lectura | rw.Escritutra y lectura]\n>>";
		cin>>modoAcceso;
		
		if(compare(modoAcceso,(char*)"r")||compare(modoAcceso,(char*)"rw")){
			AtributoInt *nuevo = new AtributoInt(dato,max,modoAcceso,(char*)"Entero");
			if (apPrimerInt == nullptr)
				apPrimerInt = nuevo;
			else{
				AtributoInt *temp = apPrimerInt;
				while (temp->getSig () != nullptr)
					temp = temp->getSig ();
				temp->setSig (nuevo);
			}	
		}else{
			cout<<"\nEl modo de acceso es incorrecto"<<endl;
		}
	}

	/*****Nombre***************************************
	 * ingresarAtributoAlfa
	 *****Descripción**********************************
	 * Se encarga de ingresar atributos de tipo char
	 *****Retorno**************************************
	 * 
	 *****Entradas*************************************
	 * 
	 **************************************************/
	void ingresarAtributoAlfa(){
		int max=0;
		char *dato;
		char *modoAcceso;
		modoAcceso=(char*) malloc(2*sizeof(char));

		cout<<"\n[     INGRESANDO ATRIBUTO ALFANUMERICO     ]"<<endl;
		cout<<"\nIngrese el maximo\n>>";
		cin>>max;
		cout<<"\nIngrese el modo de acceso [r.Lectura | rw.Escritutra y lectura]\n>>";
		cin>>modoAcceso;

		if(compare(modoAcceso,(char*)"r")||compare(modoAcceso,(char*)"rw")){
			AtributoChar *nuevo = new AtributoChar(dato,max,modoAcceso,(char*)"Alfanumerico");
			if (apPrimerChar == nullptr)
				apPrimerChar = nuevo;
			else{
				AtributoChar *temp = apPrimerChar;
				while (temp->getSig () != nullptr)
					temp = temp->getSig ();
				temp->setSig (nuevo);
			}	
		}else{
			cout<<"\nEl modo de acceso es incorrecto"<<endl;
		}
	}

	/*****Nombre***************************************
	 * ingresarAtributoBooleano
	 *****Descripción**********************************
	 * Se encarga de ingresar atributos de tipo Booleano
	 *****Retorno**************************************
	 * 
	 *****Entradas*************************************
	 * 
	 **************************************************/
	void ingresarAtributoBooleano(){
		int max=0;
		bool dato;
		char *modoAcceso;
		modoAcceso=(char*) malloc(2*sizeof(char));

		cout<<"\n[     INGRESANDO ATRIBUTO BOOLEANO     ]"<<endl;
		cout<<"\nIngrese el maximo\n>>";
		cin>>max;
		cout<<"\nIngrese el modo de acceso [r.Lectura | rw.Escritutra y lectura]\n>>";
		cin>>modoAcceso;

		if(compare(modoAcceso,(char*)"r")||compare(modoAcceso,(char*)"rw")){
			AtributoBool *nuevo = new AtributoBool(dato,max,modoAcceso,(char*)"Booleano");
			if (apPrimerBool == nullptr)
				apPrimerBool = nuevo;
			else{
				AtributoBool *temp = apPrimerBool;
				while (temp->getSig () != nullptr)
					temp = temp->getSig ();
				temp->setSig (nuevo);
			}	
		}else{
			cout<<"\nEl modo de acceso es incorrecto"<<endl;
		}
	}

	/*****Nombre***************************************
	* compare
	*****Descripción**********************************
	* compara la totalidad de dos char*
	*****Retorno**************************************
	* un booleano de la comparacion total de dos char*
	*****Entradas*************************************
	* char *s1: Un arreglo de char a compararse
	* char *s2: Otro arreglo de char a compararse
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

	/*****Nombre*****************************************************************
	 * ingresarAtributos
	 *****Descripción************************************************************
	 * Es el menu que se encarga de pedir los datos para ingresar los atributos
	 *****Retorno****************************************************************
	 * 
	 *****Entradas***************************************************************
	 * 
	 ****************************************************************************/
	void ingresarAtributos(){
		int size = 1;
		char instruccion[size];
		do{
			cout<<"\n[      INGRESAR EL TIPO DE ATRIBUTO      ]"<<endl;
			cout<<"1. Numeros Enteros"<<endl;
			cout<<"2. Alfanumerico"<<endl;		
			cout<<"3. Fecha"<<endl;
			cout<<"4. Hora"<<endl;
			cout<<"5. Booleano"<<endl;
			cout<<"0. Terminar de agregar Atributos"<<endl;
			cout<<"\n>>";
			cin>>instruccion;

			if (compare(instruccion, (char*)"0")){
				break;
			}else if (compare(instruccion, (char*)"1")){
				ingresarAtributoInt();
			}else if (compare(instruccion, (char*)"2")){
				ingresarAtributoAlfa();
			}else if (compare(instruccion, (char*)"3")){
				
			}else if (compare(instruccion, (char*)"4")){
				
			}else if (compare(instruccion, (char*)"5")){
				ingresarAtributoBooleano();
			} else {
				cout<<"\nOpcion no valida"<<endl;
			}
		}while(!compare(instruccion, (char*)"0"));
		cout<<"\nSe agrego los atributos al Elemento"<<endl;
	}

	/*****Nombre*********************************************
	 * ingresarCopiaInt
	 *****Descripción*****************************************
	 * Se encarga de ingresar la copia del atributo int
	 *****Retorno*********************************************
	 * 
	 *****Entradas********************************************
	 * AtributoInt *copiaNuevo: Es la copia del atributo int
	 *********************************************************/
	void ingresarCopiaInt(AtributoInt *copiaNuevo){
		if (apPrimerInt == nullptr)
				apPrimerInt = copiaNuevo;
		else{
			AtributoInt *temp = apPrimerInt;
			while (temp->getSig () != nullptr)
				temp = temp->getSig ();
			temp->setSig (copiaNuevo);
		}
	}

	/*****Nombre*********************************************
	 * ingresarCopiaChar
	 *****Descripción*****************************************
	 * Se encarga de ingresar la copia del atributo char
	 *****Retorno*********************************************
	 * 
	 *****Entradas********************************************
	 * AtributoChar *copiaNuevo: Es la copia del atributo char
	 *********************************************************/
	void ingresarCopiaChar(AtributoChar *copiaNuevo){
		if (apPrimerChar == nullptr)
				apPrimerChar = copiaNuevo;
		else{
			AtributoChar *temp = apPrimerChar;
			while (temp->getSig () != nullptr)
				temp = temp->getSig ();
			temp->setSig (copiaNuevo);
		}
	}

	/*****Nombre*********************************************
	 * ingresarCopiaBool
	 *****Descripción*****************************************
	 * Se encarga de ingresar la copia del atributo bool
	 *****Retorno*********************************************
	 * 
	 *****Entradas********************************************
	 * AtributoBool *copiaNuevo: Es la copia del atributo bool
	 *********************************************************/
	void ingresarCopiaBool(AtributoBool *copiaNuevo){
		if (apPrimerBool == nullptr)
				apPrimerBool = copiaNuevo;
		else{
			AtributoBool *temp = apPrimerBool;
			while (temp->getSig () != nullptr)
				temp = temp->getSig ();
			temp->setSig (copiaNuevo);
		}
	}

	int getIdentificador(){
		return aIdentificador;
	}

	char* getNombre(){
		return apNombre;
	}

	AtributoInt* getPrimerInt(){
		return apPrimerInt;
	}

	AtributoChar* getPrimerChar(){
		return apPrimerChar;
	}

	AtributoBool* getPrimerBool(){
		return apPrimerBool;
	}

	Elemento* getSig(){
		return apSig;
	}

	Elemento* getAnt(){
		return apAnt;
	}

	void setIdentificador(int identificador){
		aIdentificador = identificador;
	}

	void setNombre(char* pNombre){
		apNombre = pNombre;
	}

	void setPrimerInt(AtributoInt* pPrimerInt){
		apPrimerInt = pPrimerInt;
	}

	void setPrimerChar(AtributoChar* pPrimerChar){
		apPrimerChar = pPrimerChar;
	}

	void setPrimerBool(AtributoBool* pPrimerBool){
		apPrimerBool = pPrimerBool;
	}

	void setSig(Elemento *pElemento){
		apSig = pElemento;
	}

	void setAnt(Elemento *pElemento){
		apAnt = pElemento;
	}
};
#endif