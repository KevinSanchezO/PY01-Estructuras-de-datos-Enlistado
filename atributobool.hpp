#ifndef ATRIBUTOBOOL_HPP
#define ATRIBUTOBOOL_HPP

/*****Nombre*****************************************************************
 * AtributoBool
 *****Descripción************************************************************
 * Es la clase que se encarga de administrar los atributos de tipo Booleano
 *****Atributos**************************************************************
 * bool aDato
 * int aSize
 * char* apAcceso
 * char* apTipo
 * AtributoBool *apSig
 *****Métodos****************************************************************
 * AtributoBool
 ****************************************************************************/
class AtributoBool{
	private:
		bool aDato;
		int aSize;
		char* apAcceso;
		char* apTipo;
		AtributoBool *apSig;
	public:

		/*****Nombre*******************************************************
		* AtributoBool
		*****Descripción***************************************************
		* Es el constructor de la clase AtributoBool
		*****Retorno*******************************************************
		* 
		*****Entradas******************************************************
		* 
		*******************************************************************/
		AtributoBool(bool dato, int size, char* pAcceso, char* pTipo){
			aDato = dato;
			aSize = size;
			apAcceso = pAcceso;
			apTipo = pTipo;
			apSig = nullptr;
		}

		bool getDato(){
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

		AtributoBool* getSig(){
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

		void setSig(AtributoBool *pAtributo){
			apSig = pAtributo;
		}
};
#endif