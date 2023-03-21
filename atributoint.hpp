#ifndef ATRIBUTOINT_HPP
#define ATRIBUTOINT_HPP

/*****Nombre*****************************************************************
 * AtributoInt
 *****Descripción************************************************************
 * Es la clase que se encarga de administrar los atributos de tipo entero
 *****Atributos**************************************************************
 * bool aDato
 * int aSize
 * char* apAcceso
 * char* apTipo
 * AtributoInt *apSig
 *****Métodos****************************************************************
 * AtributoInt
 ****************************************************************************/
class AtributoInt{
	private:
		int aDato;
		int aSize;
		char* apAcceso;
		char* apTipo;
		AtributoInt *apSig;
	public:

		/*****Nombre*******************************************************
		* AtributoInt
		*****Descripción***************************************************
		* Es el constructor de la clase AtributoInt
		*****Retorno*******************************************************
		* 
		*****Entradas******************************************************
		* 
		*******************************************************************/
		AtributoInt(int dato, int size, char* pAcceso, char* pTipo){
			aDato = dato;
			aSize = size;
			apAcceso = pAcceso;
			apTipo = pTipo;
			apSig = nullptr;
		}

		int getDato(){
			return aDato;
		}

		int getSize(){
			return aSize;
		}

		char* getAcceso(){
			return apAcceso;
		}

		char* getTipo(){
			return apTipo;
		}

		AtributoInt* getSig(){
			return apSig;
		}

		void setDato(bool dato){
			aDato = dato;
		}

		void setSize(int size){
			aSize = size;
		}

		void setAcceso(char* pAcceso){
			apAcceso = pAcceso;
		}

		void setTipo(char* pTipo){
			apTipo = pTipo;
		}

		void setSig(AtributoInt *pAtributo){
			apSig = pAtributo;
		}
};
#endif