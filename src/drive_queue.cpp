#include "queuear.h"

int main ()
{	
	int size = 100;
	QueueAr<int> queue( size );
	
	for ( int i = 0; i<20; i++)
		queue.enqueue(i);

	cout << "\n>>> Valor deletado : "<< queue.dequeue() << endl;
	queue.makeEmpty();
	try
	{
	queue.getFront();
	cout << "\n>>> Valor deletado : "<< queue.dequeue() << endl;
	}
	catch ( out_of_range &e )
	{
		cerr << "Capturei um erro "<< e.what() << endl;
	}


}