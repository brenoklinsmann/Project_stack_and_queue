#include "stackint.h"

int main ()
{
	StackInt P (5);
	for (int x =0; x<10; x++){
		P.push( x );
		cout <<"Valor do topo: " << P.top() << endl;
	}
	//cout << "Valor Excluido: " << P.pop() << endl;

	try
	{
		cout << "Valor Excluido: " << P.pop() << endl;
		P.printArray();
	}
	catch (std::length_error &e)
	{
		//cout << e.what() << endl;
		cout << "Capturei uma excessão: " << e.what() << endl;
	}
		
}