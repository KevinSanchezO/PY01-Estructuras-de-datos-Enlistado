#ifndef ATRIBUTOCHAR_HPP
#define ATRIBUTOCHAR_HPP

/*****Nombre*****************************************************************
 * AtributoChar
 *****Descripción************************************************************
 * Es la clase que se encarga de administrar los atributos de tipo char
 *****Atributos**************************************************************
 * bool aDato
 * int aSize
 * char* apAcceso
 * char* apTipo
 * AtributoChar *apSig
 *****Métodos****************************************************************
 * AtributoChar
 ****************************************************************************/
class AtributoChar{
	private:
		char* aDato;
		int aSize;
		char* apAcceso;
		char* apTipo;
		AtributoChar *apSig;
	public:

		/*****Nombre*******************************************************
		* AtributoChar
		*****Descripción***************************************************
		* Es el constructor de la clase AtributoChar
		*****Retorno*******************************************************
		* 
		*****Entradas******************************************************
		* 
		*******************************************************************/
		AtributoChar(char* dato, int size, char* pAcceso, char* pTipo){
			aDato = dato;
			aSize = size;
			apAcceso = pAcceso;
			apTipo = pTipo;
			apSig = nullptr;
		}

		char* getDato(){
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

		AtributoChar* getSig(){
			return apSig;
		}

		void setDato(char* dato){
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

		void setSig(AtributoChar *pAtributo){
			apSig = pAtributo;
		}
};
#endif