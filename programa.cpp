/*****Datos administrativos************************
 * Nombre del archivo: programa
 * Tipo de archivo: cpp
 * Proyecto: Enlistado
 * Autor: Kevin Lanzas, Russell Hidalgo, Kevin Sanchez
 * Empresa: Instituto Tecnologico de Costa Rica (TEC)
 *****Descripción**********************************
 * Sistema para la creación de distintos conjuntos de datos
  de características lineales flexibles por medio de estructuras 
  de datos lineales en memoria.
 *****Versión**************************************
 * ## | Fecha y hora      | Autor
 * 1  | 9/10/2020 1:00 pm | Kevin Sanchez, Kevin Lanzas, Russell Hidalgo
 **************************************************/
#include <iostream>
#include "elemento.hpp"
#include "contenedorelemento.hpp"
#include "contenedorestructura.hpp"
using namespace std;

ContenedorElemento *gContElemento = new ContenedorElemento();
ContenedorEstructura *gContEstructura = new ContenedorEstructura();

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

/*****Nombre***************************************
 * limpiar
 *****Descripción**********************************
 * setea a 0 un char*
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * char *s, char byte, int size
 **************************************************/
void limpiar (char *s, char byte, int size) {
	for (int i = 0; i < size; i++)
		s[i] = byte;
}

/*****Nombre************************************************************************************
 * crearEstructuraAux
 *****Descripción*******************************************************************************
 * Es la auxiliar del metodo crearEstructura el cual le ayuda a terminar de crear la estructura
 *****Retorno***********************************************************************************
 * 
 *****Entradas**********************************************************************************
 * 
 ***********************************************************************************************/

void crearEstructuraAux(char* pNombre, char* pTipo, Elemento *pElemento, bool pEnlazamiento){
	int size = 1;
	char circular[size];
	char insercionFin[size]; 
	char ordenada[size];
	
	if(compare(pTipo,(char*)"Pila") || compare(pTipo,(char*)"Cola")){

		cout<<"\nDesea que la lista inserte los elementos al final"<<endl;
		cout<<"[1. Si | 2. No ]\n>>";
		cin>>insercionFin;

		cout<<"\nDesea que la estructura este ordenada"<<endl;
		cout<<"[1. Si | 2. No ]\n>>";
		cin>>ordenada;

		if (compare(insercionFin,(char*)"1")){
			if(compare(ordenada,(char*)"1")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,false,true,true);
			}else if(compare(ordenada,(char*)"2")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,false,true,false);
			}
		}else if(compare(insercionFin,(char*)"2")){
			if(compare(ordenada,(char*)"1")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,false,false,true);
			}else if(compare(ordenada,(char*)"2")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,false,false,false);
			}
		} else {
			cout<<"\nUna de las opciones de ingreso no es valida"<<endl;
		}
	} else {
	
		cout<<"\nDesea que la estructura sea circular"<<endl;
		cout<<"[1. Si | 2. No ]\n>>";
		cin>>circular;

		cout<<"\nDesea que la lista inserte los elementos al final"<<endl;
		cout<<"[1. Si | 2. No ]\n>>";
		cin>>insercionFin;
		
		cout<<"\nDesea que la estructura este ordenada"<<endl;
		cout<<"[1. Si | 2. No ]\n>>";
		cin>>ordenada;

		if (compare(circular,(char*)"1")){
			if(compare(insercionFin,(char*)"1") && compare(ordenada,(char*)"1")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,true,true,true);
			}else if(compare(insercionFin,(char*)"1") && compare(ordenada,(char*)"2")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,true,true,false);
			}else if(compare(insercionFin,(char*)"2") && compare(ordenada,(char*)"1")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,true,false,true);
			}else if(compare(insercionFin,(char*)"2") && compare(ordenada,(char*)"2")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,true,false,false);
			}
		}else if (compare(circular,(char*)"2")){
			if(compare(insercionFin,(char*)"1") && compare(ordenada,(char*)"1")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,false,true,true);
			}else if(compare(insercionFin,(char*)"1") && compare(ordenada,(char*)"2")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,false,true,false);
			}else if(compare(insercionFin,(char*)"2") && compare(ordenada,(char*)"1")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,false,false,true);
			}else if(compare(insercionFin,(char*)"2") && compare(ordenada,(char*)"2")){
				gContEstructura->ingresarEstructura(pNombre,pTipo,pElemento,pEnlazamiento,false,false,false);
			}
		} else {
			cout<<"\nUna de las opciones de ingreso no es valida"<<endl;
		}
	}
}
/*****Nombre***************************************
 * crearEstructura
 *****Descripción**********************************
 * Se encarga de la creacion de una estructura
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
void crearEstructura(){
	int size = 1;
	char tipo [size];
	char enlaz[size];

	char* nombre;
	nombre = (char*) malloc(100*sizeof(char));
	int identificador; 
	Elemento *elemento;
	
	cout<<"\n\nDigite el nombre de la estructura\n>>";
	cin>>nombre;

	cout<<"\n[ 1. Pila | 2. Cola | 3. Lista]\nDigite el tipo para la estructura \n>>";
	cin>>tipo;

	gContElemento->visualizarElementos();
	
	cout<<"\nDigite el identificador del elemento que desea agregar\n>>";
	cin>>identificador;
	
	if (gContElemento->buscarElemento(identificador)){
		elemento = gContElemento->encontrarElemento(identificador);

		cout<<"\nDigite si desea enlazamiento doble"<<endl;
		cout<<"[1. Si | 2. No ]\n>>";
		cin>>enlaz;
		
		if (compare(tipo,(char*)"1")){
			if(compare(enlaz,(char*)"1")){
				crearEstructuraAux(nombre,(char*)"Pila",elemento,true);
			}else if(compare(enlaz,(char*)"2")){
				crearEstructuraAux(nombre,(char*)"Pila",elemento,false);	
			}
		}else if(compare(tipo,(char*)"2")){
			if(compare(enlaz,(char*)"1")){
				crearEstructuraAux(nombre,(char*)"Cola",elemento,true);	
			}else if(compare(enlaz,(char*)"2")){
				crearEstructuraAux(nombre,(char*)"Cola",elemento,false);
			}
		}else if(compare(tipo,(char*)"3")){
			if(compare(enlaz,(char*)"1")){
				crearEstructuraAux(nombre,(char*)"Lista",elemento,true);	
			}else if(compare(enlaz,(char*)"2")){
				crearEstructuraAux(nombre,(char*)"Lista",elemento,false);
			}	
		} else {
			cout<<"\nNo eligio un tipo de estructura valido"<<endl;
		}
	} else {
		cout<<"\nEl identificador del elemento no existe"<<endl;
	}
}

/*****Nombre*************************************************
 * borrar
 *****Descripción********************************************
 * Se encarga de pedir el nombre de la estructura a borrar
 *****Retorno************************************************
 * 
 *****Entradas***********************************************
 * 
 ************************************************************/
void borrar(){
	char* pNombre;
	pNombre = (char*) malloc(100*sizeof(char));
	gContEstructura->visualizarEstructuras();
	cout<<"\nIngrese el nombre de la estructura a eliminar\n>>";
	cin>>pNombre;
	gContEstructura->borrarEstructuraPila(pNombre);
}

/*****Nombre*************************************************
 * utilizarEstructura
 *****Descripción********************************************
 * Se encarga de pedir el nombre de la estructura a utilizar
 *****Retorno************************************************
 * 
 *****Entradas***********************************************
 * 
 ************************************************************/
void utilizarEstructura(){
	char* pNombre;
	pNombre = (char*) malloc(100*sizeof(char));
	gContEstructura->visualizarEstructuras();
	cout<<"\nIngrese el nombre de la estructura a utilizar\n>>";
	cin>>pNombre;
	gContEstructura->utilizarEstructura(pNombre);
}

/*****Nombre***************************************
 * main
 *****Descripción**********************************
 * Es el menu principal del programa
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
int main (){
	int size = 1;
	char instruccion[size];
	do{
		limpiar(instruccion, 0, size*sizeof(char));
		cout<<"\n\n[          MENU PRINCIPAL          ]"<<endl;
		cout<<"1. Crear elemento"<<endl;
		cout<<"2. Visualizar elementos"<<endl;		
		cout<<"3. Crear Estructura"<<endl;
		cout<<"4. Utilizar estructura"<<endl;
		cout<<"5. Visualizar estructura"<<endl;
		cout<<"6. Eliminar estructura"<<endl;
		cout<<"7. Estado"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"\nIngrese la tarea a realizar\n>>";
		cin>>instruccion;

		if (compare(instruccion, (char*)"0")){
			break;
		}else if (compare(instruccion, (char*)"1")){
			gContElemento->crearElemento();
		}else if (compare(instruccion, (char*)"2")){
			gContElemento->visualizarElementos();
		}else if (compare(instruccion, (char*)"3")){
			crearEstructura();
		}else if (compare(instruccion, (char*)"4")){
			utilizarEstructura();
		}else if (compare(instruccion, (char*)"5")){
			gContEstructura->visualizarEstructuras();
		}else if (compare(instruccion, (char*)"6")){
			borrar();
		}else if (compare(instruccion, (char*)"7")){
			gContElemento->visualizarElementos();
			gContEstructura->visualizarEstadoEstructuras();
		} else {
			cout<<"\nOpcion no valida"<<endl;
		}
	} while(!compare(instruccion, (char*)"0"));
}