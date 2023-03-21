#ifndef COLA_HPP
#define COLA_HPP

#include <iostream>
#include "atributobool.hpp"
#include "atributochar.hpp"
#include "atributoint.hpp"
#include "elemento.hpp"
using namespace std;

/*****Nombre***************************************************************
 * Cola
 *****Descripción**********************************************************
 * Es la clase que se encarga de administrar las estructuras de tipo cola
 *****Atributos************************************************************
 * char *apNombre
 * char *apTipo
 * Elemento *apElemento
 * Elemento *apPrimero
 * bool aEnlazamiento
 * bool aCircularidad
 * bool aInsercionFin
 * bool aInsercionOrd
 * Cola *apSig;
 *****Métodos**************************************************************
 * Cola
 * void menuCola
 * void verificarEliminar
 * void eliminarDobleFinal
 * void eliminarSimpleFinal
 * void eliminarDobleInicio
 * void eliminarSimpleInicio
 * void validarInsertar
 * void buscar
 * void buscarInt
 * void buscarIntAlt
 * void buscarChar
 * void buscarCharAlt
 * void buscarBool
 * void buscarBoolAlt
 * void mostrarElementos
 * void insercionDobleFinal
 * void insercionSimpleFinal
 * void insercionDobleInicio
 * void insercionSimpleInicio
 * Elemento* crearElemento
 * bool compare
 **************************************************************************/
class Cola{
	private:
		char *apNombre;
		char *apTipo;
		Elemento *apElemento;
		Elemento *apPrimero;
		Elemento *apUltimo;
		bool aEnlazamiento;
		bool aCircularidad;
		bool aInsercionFin;
		bool aInsercionOrd;
		Cola *apSig;
	public:

		/*****Nombre************************************************************************
		 * Cola
		 *****Descripción*******************************************************************
		 * Es el constructor de la clase Cola
		 *****Retorno***********************************************************************
		 * 
		 *****Entradas**********************************************************************
		 * char *pNombre: Es el nombre de la estructura
		 * char *pTipo: Es el tipo de la estructura
		 * Elemento *pElemento: Es el elemento de la estructura
		 * bool enlazamiento: Indica si quiere enlazamiento simple o doble en la estructura
		 * bool circularidad: Indica si quiere circularidad en la estructura
		 * bool insercionFin: Indica si quiere insercion al final de la estructura
		 * bool insercionOrd: Indica si quiere insercion ordenada en la estructura
		 ***********************************************************************************/
		Cola(char *pNombre,char *pTipo,Elemento *pElemento,bool enlazamiento,bool circularidad,bool insercionFin,bool insercionOrd){
			apNombre = pNombre;
			apTipo = pTipo;
			apElemento = pElemento;
			apPrimero = nullptr;
			apUltimo = nullptr;
			aEnlazamiento = enlazamiento;
			aCircularidad = circularidad;
			aInsercionFin = insercionFin;
			aInsercionOrd = insercionOrd;
			apSig = nullptr;
		}
		 /*****Nombre*******************************************************
		 * menuCola
		 *****Descripción***************************************************
		 * Es el menu de las acciones que puede realizar la estructura cola
		 *****Retorno*******************************************************
		 * 
		 *****Entradas******************************************************
		 * 
		 *******************************************************************/
		void menuCola(){
			int size = 1;
			char instruccion[size];
			do{
				cout<<"\n\n[	MENU COLA	]"<<endl;
				cout<<"1. Insertar"<<endl;
				cout<<"2. Ordenar"<<endl;		
				cout<<"3. Buscar"<<endl;
				cout<<"4. Eliminar"<<endl;
				cout<<"0. Salir"<<endl;
				cout<<"Ingrese la tarea ha realizar\n>>";
				cin>>instruccion;
				if (compare(instruccion, (char*)"0")){
					break;
				}else if (compare(instruccion, (char*)"1")){
					validarInsertar();
				}else if (compare(instruccion, (char*)"2")){
					//ordenarCola();
				}else if (compare(instruccion, (char*)"3")){
					buscar();
				}else if (compare(instruccion, (char*)"4")){
					verificarEliminar();
				}
			}while(!compare(instruccion,(char*)"0"));
		}

		 /*****Nombre*****************************************************
		 * verificarEliminar
		 *****Descripción*************************************************
		 * Se encarga de validar las diferentes situaciones de eliminacion
		 *****Retorno*****************************************************
		 * 
		 *****Entradas****************************************************
		 * 
		 *****************************************************************/
		void verificarEliminar(){
			if (aInsercionFin){
				if (aEnlazamiento){
					eliminarDobleFinal();
				} else{
					eliminarSimpleFinal();
				}
			} else {
				if (aEnlazamiento){
					eliminarDobleInicio();
				} else{
					eliminarSimpleInicio();
				}
			}
			cout<<"\nSe elimino el primer elemento en ser ingresado a la estructura"<<endl;
			mostrarElementos();
		}

		 /*****Nombre****************************************************************************************
		 * eliminarDobleFinal
		 *****Descripción************************************************************************************
		 * Se encarga de eliminar un atributo en una estructura de enlazamiento doble y con insercion final
		 *****Retorno****************************************************************************************
		 * 
		 *****Entradas***************************************************************************************
		 * 
		 ****************************************************************************************************/
		void eliminarDobleFinal(){
			if (apPrimero == apUltimo){
				apPrimero = nullptr;
				apUltimo = nullptr;
			} else {
				Elemento *temp = apUltimo->getAnt();
				apUltimo->setAnt(nullptr);
				temp->setSig(nullptr);
				apUltimo = temp;
			}
		}

		 /*****Nombre****************************************************************************************
		 * eliminarSimpleFinal
		 *****Descripción************************************************************************************
		 * Se encarga de eliminar un atributo en una estructura de enlazamiento simple y con insercion final
		 *****Retorno****************************************************************************************
		 * 
		 *****Entradas***************************************************************************************
		 * 
		 ****************************************************************************************************/
		void eliminarSimpleFinal(){
			if (apPrimero == apUltimo){
				apPrimero = nullptr;
				apUltimo = nullptr;
			} else {
				Elemento *temp = apUltimo->getAnt();
				apUltimo->setAnt(nullptr);
				apUltimo = temp;
			}
		}

		 /*****Nombre*********************************************************************************************
		 * eliminarDobleInicio
		 *****Descripción*****************************************************************************************
		 * Se encarga de eliminar un atributo en una estructura de enlazamiento doble y con insercion al inicio
		 *****Retorno*********************************************************************************************
		 * 
		 *****Entradas********************************************************************************************
		 * 
		 *********************************************************************************************************/
		void eliminarDobleInicio(){
			if (apPrimero == apUltimo){
				apPrimero = nullptr;
				apUltimo = nullptr;
			} else {
				Elemento *temp = apPrimero->getSig();
				apPrimero->setSig(nullptr);
				temp->setAnt(nullptr);
				apPrimero = temp;
			}
		}

		 /*****Nombre*********************************************************************************************
		 * eliminarSimpleInicio
		 *****Descripción*****************************************************************************************
		 * Se encarga de eliminar un atributo en una estructura de enlazamiento simple y con insercion al inicio
		 *****Retorno*********************************************************************************************
		 * 
		 *****Entradas********************************************************************************************
		 * 
		 *********************************************************************************************************/
		void eliminarSimpleInicio(){
			if (apPrimero == apUltimo){
				apPrimero = nullptr;
				apUltimo = nullptr;
			} else {
				Elemento *temp = apPrimero->getSig();
				apPrimero->setSig(nullptr);
				apPrimero = temp;
			}
		}

		 /*****Nombre*****************************************************
		 * validarInsertar
		 *****Descripción*************************************************
		 * Se encarga de validar las diferentes situaciones de insercion
		 *****Retorno*****************************************************
		 * 
		 *****Entradas****************************************************
		 * 
		 *****************************************************************/
		void validarInsertar(){
			if (aInsercionFin){
				if (aEnlazamiento){
					insercionDobleFinal();
				} else{
					insercionSimpleFinal();
				}
			} else {
				if (aEnlazamiento){
					insercionDobleInicio();
				} else{
					insercionSimpleInicio();
				}
			}
			cout<<"\nSe ingreso el elemento a la estructura"<<endl;
			mostrarElementos();
		}

		 /*****Nombre************************************************************************
		 * buscar
		 *****Descripción********************************************************************
		 * Es un menu que se encarga de identificar el tipo del atributo que se va a buscar
		 *****Retorno************************************************************************
		 * 
		 *****Entradas***********************************************************************
		 * 
		 ************************************************************************************/
		void buscar(){
			int size = 1;
			char instruccion[size];
			cout<<"\n Digite el tipo que desea buscar [1.int | 2.Char | 3. bool]\n>> ";
			cin>>instruccion;
			if (compare(instruccion, (char*)"1")){
				if(aEnlazamiento == false && aInsercionFin){
					buscarIntAlt();
				}else{
					buscarInt();
				}
			}else if (compare(instruccion, (char*)"2")){
				if(aEnlazamiento == false && aInsercionFin){
					buscarCharAlt();
				}else{
					buscarChar();
				}
				
			}else if (compare(instruccion, (char*)"3")){
				if(aEnlazamiento == false && aInsercionFin){
					buscarBoolAlt();
				}else{
					buscarBool();
				}

			}else{
				cout<<"\n La opcion que ingreso no es valida\n";
			}
		}

		 /*****Nombre************************************************************************
		 * buscarInt
		 *****Descripción********************************************************************
		 * Se encarga de buscar un atributo entero
		 *****Retorno************************************************************************
		 * 
		 *****Entradas***********************************************************************
		 * 
		 ************************************************************************************/
		void buscarInt(){
			mostrarElementos();
			int num;
			cout<<"\n Digite el elemento que desea buscar\n>>";
			cin>>num;
			Elemento *temp = apPrimero;
			while (temp != nullptr){
				if (temp->getPrimerInt()->getDato() == num){
					cout<<"Se encontro el numero: "<<num<<endl;
					temp->mostrarAtributosEstructura();
					break;
				}
				temp = temp->getSig();
			}
			if(temp == nullptr){
				cout<<"no se encontro "<<num<<endl;
			}
		}

		/*****Nombre*******************************************************************************************
		 * buscarIntAlt
		 *****Descripción**************************************************************************************
		 * Se encarga de buscar un atributo entero cuando el enlazamiento es simple y se inserta por el final
		 *****Retorno******************************************************************************************
		 * 
		 *****Entradas*****************************************************************************************
		 * 
		 ******************************************************************************************************/
		void buscarIntAlt(){
			mostrarElementos();
			int num;
			cout<<"\n Digite el elemento que desea buscar\n>>";
			cin>>num;
			Elemento *temp = apUltimo;
			while (temp != nullptr){
				if (temp->getPrimerInt()->getDato() == num){
					cout<<"Se encontro el numero: "<<num<<endl;
					temp->mostrarAtributosEstructura();
					break;
				}
				temp = temp->getAnt();
			}
			if(temp == nullptr){
				cout<<"no se encontro "<<num<<endl;
			}
		}

		 /*****Nombre************************************************************************
		 * buscarChar
		 *****Descripción********************************************************************
		 * Se encarga de buscar un atributo char
		 *****Retorno************************************************************************
		 * 
		 *****Entradas***********************************************************************
		 * 
		 ************************************************************************************/
		void buscarChar(){
			mostrarElementos();
			char* buscar;
			buscar = (char*) malloc(100*sizeof(char));
			cout<<"\n Digite el elemento que desea buscar\n>>";
			cin>>buscar;
			Elemento *temp = apPrimero;
			while (temp != nullptr){
				if (compare(temp->getPrimerChar()->getDato(),buscar)){
					cout<<"Se encontro el dato alfanumerico: "<<buscar<<endl;
					temp->mostrarAtributosEstructura();
					break;
				}
				temp = temp->getSig();
			}
			if(temp == nullptr){
				cout<<"no se encontro "<<buscar<<endl;
			}
		}

		 /*****Nombre****************************************************************************************
		 * buscarCharAlt
		 *****Descripción************************************************************************************
		 * Se encarga de buscar un atributo char cuando el enlazamiento es simple y se inserta por el final
		 *****Retorno****************************************************************************************
		 * 
		 *****Entradas***************************************************************************************
		 * 
		 ****************************************************************************************************/
		void buscarCharAlt(){
			mostrarElementos();
			char* buscar;
			buscar = (char*) malloc(100*sizeof(char));
			cout<<"\n Digite el elemento que desea buscar\n>>";
			cin>>buscar;
			Elemento *temp = apUltimo;
			while (temp != nullptr){
				if (compare(temp->getPrimerChar()->getDato(),buscar)){
					cout<<"Se encontro el dato alfanumerico: "<<buscar<<endl;
					temp->mostrarAtributosEstructura();
					break;
				}
				temp = temp->getAnt();
			}
			if(temp == nullptr){
				cout<<"no se encontro "<<buscar<<endl;
			}
		}

		 /*****Nombre************************************************************************
		 * buscarBool
		 *****Descripción********************************************************************
		 * Se encarga de buscar un atributo bool
		 *****Retorno************************************************************************
		 * 
		 *****Entradas***********************************************************************
		 * 
		 ************************************************************************************/
		void buscarBool(){
			mostrarElementos();
			char* buscado;
			buscado = (char*) malloc(100*sizeof(char));
			bool buscar;
			cout<<"\n Digite que desea buscar [1.true | 2.false]\n>>";
			cin>>buscado;
			if (compare(buscado, (char*)"1")){
				cout<<"\n Se buscara un elemento que tenga true\n";
				buscar = true;
			}else{
				cout<<"\n Se buscara un elemento que tenga false\n";
				buscar = false;
			}
			Elemento *temp = apPrimero;
			while (temp != nullptr){
				if (temp->getPrimerBool()->getDato() == buscar){
					cout<<"Se encontro el dato booleano: "<<buscar<<endl;
					temp->mostrarAtributosEstructura();
					break;
				}
				temp = temp->getSig();
			}
			if(temp == nullptr){
				cout<<"no se encontro "<<buscar<<endl;
			}
		}

		 /*****Nombre************************************************************************
		 * buscarBoolAlt
		 *****Descripción********************************************************************
		 * Se encarga de buscar un atributo bool
		 *****Retorno************************************************************************
		 * 
		 *****Entradas***********************************************************************
		 * 
		 ************************************************************************************/
		void buscarBoolAlt(){
			mostrarElementos();
			char* buscado;
			buscado = (char*) malloc(100*sizeof(char));
			bool buscar;
			cout<<"\n Digite que desea buscar [1.true | 2.false]\n>>";
			cin>>buscado;
			if (compare(buscado, (char*)"1")){
				cout<<"\n Se buscara un elemento que tenga true\n";
				buscar = true;
			}else{
				cout<<"\n Se buscara un elemento que tenga false\n";
				buscar = false;
			}
			Elemento *temp = apUltimo;
			while (temp != nullptr){
				if (temp->getPrimerBool()->getDato() == buscar){
					cout<<"Se encontro el dato booleano: "<<buscar<<endl;
					temp->mostrarAtributosEstructura();
					break;
				}
				temp = temp->getAnt();
			}
			if(temp == nullptr){
				cout<<"no se encontro "<<buscar<<endl;
			}
		}
		 /*****Nombre*****************************************************
		 * mostrarElementos
		 *****Descripción*************************************************
		 * Se encarga de mostrar los diferentes elementos de la estructura
		 *****Retorno*****************************************************
		 * 
		 *****Entradas****************************************************
		 * 
		 *****************************************************************/
		void mostrarElementos(){
			if (aEnlazamiento == false && aInsercionFin){
				cout<<"\n[  ELEMENTOS EN LA ESTRUCTURA  ]"<<endl;
				Elemento *temp = apUltimo;
				int i = 0;
				while (temp != nullptr){
					cout<<"\n"<<i++<<" => "<<temp->getNombre()<<" | ["<<temp->getIdentificador()<<"]"<<endl;
					temp->mostrarAtributosEstructura();
					temp = temp->getAnt();
				}
			} else {
				cout<<"\n[  ELEMENTOS EN LA ESTRUCTURA  ]"<<endl;
				Elemento *temp = apPrimero;
				int i = 0;
				while (temp != nullptr){
					cout<<"\n"<<i++<<" => "<<temp->getNombre()<<" | ["<<temp->getIdentificador()<<"]"<<endl;
					temp->mostrarAtributosEstructura();
					temp = temp->getSig();
				}
			}
		}

		 /*****Nombre************************************************************************************
		 * insercionDobleFinal
		 *****Descripción********************************************************************************
		 * Se encarga de insertar el elemento cuando el enlazamiento es doble y se ingresa por el final
		 *****Retorno************************************************************************************
		 * 
		 *****Entradas***********************************************************************************
		 * 
		 ************************************************************************************************/
		void insercionDobleFinal(){
			Elemento *copiaNuevo = crearElemento();
			if (apUltimo == nullptr){
				apUltimo = copiaNuevo;
			} else {
				apPrimero->setAnt(copiaNuevo);
				copiaNuevo->setSig(apPrimero);
			}
			apPrimero = copiaNuevo;
		}

		 /*****Nombre************************************************************************************
		 * insercionSimpleFinal
		 *****Descripción********************************************************************************
		 * Se encarga de insertar el elemento cuando el enlazamiento es simple y se ingresa por el final
		 *****Retorno************************************************************************************
		 * 
		 *****Entradas***********************************************************************************
		 * 
		 ************************************************************************************************/
		void insercionSimpleFinal(){
			Elemento *copiaNuevo = crearElemento();
			if (apUltimo == nullptr){
				apUltimo = copiaNuevo;
			} else {
				Elemento *temp = apUltimo;
				while (temp->getAnt() != nullptr){
					temp = temp->getAnt();
				}
				temp->setAnt(copiaNuevo);
			}
			apPrimero = copiaNuevo;
		}

		 /*****Nombre************************************************************************************
		 * insercionDobleInicio
		 *****Descripción********************************************************************************
		 * Se encarga de insertar el elemento cuando el enlazamiento es doble y se ingresa por el inicio
		 *****Retorno************************************************************************************
		 * 
		 *****Entradas***********************************************************************************
		 * 
		 ************************************************************************************************/
		void insercionDobleInicio(){
			Elemento *copiaNuevo = crearElemento();
			if (apPrimero == nullptr){
				apPrimero = copiaNuevo;
			} else {
				apUltimo->setSig(copiaNuevo);
				copiaNuevo->setAnt(apUltimo);
			}
			apUltimo = copiaNuevo;
		}

		 /*****Nombre************************************************************************************
		 * insercionSimpleInicio
		 *****Descripción********************************************************************************
		 * Se encarga de insertar el elemento cuando el enlazamiento es simple y se ingresa por el inicio
		 *****Retorno************************************************************************************
		 * 
		 *****Entradas***********************************************************************************
		 * 
		 ************************************************************************************************/
		void insercionSimpleInicio(){
			Elemento *copiaNuevo = crearElemento();
			if (apPrimero == nullptr){
				apPrimero = copiaNuevo;
			} else {
				Elemento *temp = apPrimero;
				while (temp->getSig() != nullptr){
					temp = temp->getSig();
				}
				temp->setSig(copiaNuevo);
			}
			apUltimo = copiaNuevo;
		}

		 /*****Nombre**************************************************************************************************
		 * crearElemento
		 *****Descripción**********************************************************************************************
		 * Se encarga de crear una copia del elemento que se le asigno a la estructura para guardarse en la estructura
		 *****Retorno**************************************************************************************************
		 * 
		 *****Entradas*************************************************************************************************
		 * 
		 **************************************************************************************************************/
		Elemento* crearElemento(){
			Elemento *copiaNuevo = new Elemento(apElemento->getNombre(), apElemento->getIdentificador());
			if (apElemento->getPrimerInt() != nullptr){

				AtributoInt *temp = apElemento->getPrimerInt();
				while (temp != nullptr){
					int i = 0;
					if (compare(temp->getAcceso(),(char*)"rw")){
						cout<<"\nIngrese el dato para rellenar el atributo entero\n>>";
						cin>>i;
					}
					AtributoInt *nuevo = new AtributoInt(i, temp->getSize(), temp->getAcceso(), temp->getTipo());
					copiaNuevo->ingresarCopiaInt(nuevo);
					temp = temp->getSig();
				}

			} if (apElemento->getPrimerChar() != nullptr) {

				AtributoChar *temp = apElemento->getPrimerChar();
				while (temp != nullptr){
					
					char* pNombre;
					pNombre = (char*) malloc(100*sizeof(char));
					if (compare(temp->getAcceso(),(char*)"rw")){
						cout<<"\nIngrese el dato para rellenar el atributo alfanumerico\n>>";
						cin>>pNombre;
					}
					AtributoChar *nuevo = new AtributoChar(pNombre, temp->getSize(), temp->getAcceso(), temp->getTipo());
					copiaNuevo->ingresarCopiaChar(nuevo);
					temp = temp->getSig();
				}

			} if (apElemento->getPrimerBool() != nullptr){

				AtributoBool *temp = apElemento->getPrimerBool();
				while (temp != nullptr){
					
					int size = 1;
					char instruccion[size];
					bool valor;
					if (compare(temp->getAcceso(),(char*)"rw")){
						cout<<"\nIngrese como desea rellenar el dato logico [1.true | 0.false]\n>>";
						cin>>instruccion;
						if (compare(instruccion, (char*)"1")){
							valor = true;
						} else if (compare(instruccion, (char*)"0")){
							valor = false;
						} else {
							cout<<"\nEl valor que eligio no es valido. Se denominara como false\n";
							valor = false;
						}
					}
					AtributoBool *nuevo = new AtributoBool(valor, temp->getSize(), temp->getAcceso(), temp->getTipo());
					copiaNuevo->ingresarCopiaBool(nuevo);
					temp = temp->getSig();
				}
			}
			return copiaNuevo;
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

		Cola* getSig(){
			return apSig;	
		}

		void setSig(Cola *sig){
			apSig = sig;
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