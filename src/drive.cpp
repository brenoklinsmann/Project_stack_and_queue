#include "stackar.h"

int main ()
{
	StackAr<int> V ( 5 );
	
	for ( int x = 0; x<10; x++)
		V.push(x);	
	try
	{
		V.printArray();
		cout << "\n>>> Valor excluido : " << V.pop() << endl;
		cout << "\n>>> Valor do topo : " << V.top() << endl;
		V.makeEmpty();
		V.printArray();
	}
	catch ( length_error &e)
	{
		cout << "\n>>>Capturei um error " << e.what() << endl;
	}
	return EXIT_SUCCESS;
}