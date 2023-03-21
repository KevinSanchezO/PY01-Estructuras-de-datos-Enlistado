#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include "atributobool.hpp"
#include "atributochar.hpp"
#include "atributoint.hpp"
#include "elemento.hpp"
using namespace std;

/*****Nombre***************************************************************
 * Lista
 *****Descripción**********************************************************
 * Es la clase que se encarga de administrar las estructuras de tipo lista
 *****Atributos************************************************************
 * char *apNombre
 * char *apTipo
 * Elemento *apElemento
 * Elemento *apPrimero
 * bool aEnlazamiento
 * bool aCircularidad
 * bool aInsercionFin
 * bool aInsercionOrd
 * lista *apSig;
 *****Métodos**************************************************************
 * Lista
 * void menuLista
 * void validarInsertar
 * Elemento* crearElemento
 * bool compare
 **************************************************************************/
class Lista {
	private:
		char *apNombre;
		char *apTipo;
		Elemento *apElemento;
		Elemento *apPrimero;
		bool aEnlazamiento;
		bool aCircularidad;
		bool aInsercionFin;
		bool aInsercionOrd;
		Lista *apSig;
	public:

		/*****Nombre************************************************************************
		 * Lista
		 *****Descripción*******************************************************************
		 * Es el constructor de la clase Lista
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
		Lista(char *pNombre,char *pTipo,Elemento *pElemento,bool enlazamiento,bool circularidad,bool insercionFin,bool insercionOrd){
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

		 /*****Nombre*******************************************************
		 * menuLista
		 *****Descripción***************************************************
		 * Es el menu de las acciones que puede realizar la estructura Lista
		 *****Retorno*******************************************************
		 * 
		 *****Entradas******************************************************
		 * 
		 *******************************************************************/
		void menuLista(){
			int size = 1;
			char instruccion[size];
			do{
				cout<<"\n\n[	MENU LISTA	]"<<endl;
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
					//ordenarLista();
				}else if (compare(instruccion, (char*)"3")){
					//buscarLista();
				}else if (compare(instruccion, (char*)"4")){
					//eliminarLista();
				}
			}while(!compare(instruccion,(char*)"0"));
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
			/*if (aInsercionFin){
				if (aEnlazamiento){
					cout<<"\n\ninsercionDobleFinal();\n\n";
					//insercionDobleFinal();
				} else{
					cout<<"\n\ninsercionSimpleFinal()\n\n";
					//insercionSimpleFinal();
				}
			} else {
				if (aEnlazamiento){
					cout<<"\n\ninsercionDobleInicio();\n\n";
					//insercionDobleInicio();
				} else{
					cout<<"\n\ninsercionSimpleInicio();\n\n";
					//insercionSimpleInicio();
				}
			}*/
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
					cout<<"\nIngrese el dato para rellenar el atributo entero\n>>";
					cin>>i;
					AtributoInt *nuevo = new AtributoInt(i, temp->getSize(), temp->getAcceso(), temp->getTipo());
					copiaNuevo->ingresarCopiaInt(nuevo);
					temp = temp->getSig();
				}

			} if (apElemento->getPrimerChar() != nullptr) {

				AtributoChar *temp = apElemento->getPrimerChar();
				while (temp != nullptr){
					
					char* pNombre;
					pNombre = (char*) malloc(100*sizeof(char));
					cout<<"\nIngrese el dato para rellenar el atributo alfanumerico\n>>";
					cin>>pNombre;
					AtributoChar *nuevo = new AtributoChar(pNombre, temp->getSize(), temp->getAcceso(), temp->getTipo());
					copiaNuevo->ingresarCopiaChar(nuevo);
					temp = temp->getSig();
				}

			} if (apElemento->getPrimerBool() != nullptr){

				AtributoBool *temp = apElemento->getPrimerBool();
				while (temp != nullptr){
					
					int size = 1;
					char instruccion[size];
					bool valor = false;
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

		Lista* getSig(){
			return apSig;	
		}

		void setSig(Lista *sig){
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