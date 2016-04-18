#include "stackint.h"

StackInt::StackInt ( int _size ) : 
	capacity ( _size ),
	topo ( 0 ),
	P(nullptr)
{
	P = new int [ _size ];
}

StackInt::~StackInt()
{
	delete [] P;
}

void StackInt::resize( int _newCapacity )
{
	int *_P = new int [ _newCapacity ];
	cout<< "capacidade: " << capacity << endl; 
	for ( int x=0; x<capacity; x++)
		_P[x] = P[x];
	delete [] P;
	P = _P; 
	capacity = _newCapacity;
	cout<< "capacidade: " << capacity << endl;
	
}

void StackInt::push (int _newVal)
{
	if ( topo == capacity ) // Não há mais espaço
		resize(  2*capacity );
	P[topo++] = _newVal;
}

bool StackInt::empty ( ) const
{
	return topo == 0;

}

void StackInt::clear ( )
{
	topo = 0;
}
int StackInt::pop ()
{
	if ( empty() )
		throw length_error( "UnderFlow" );
	topo--;
	return P[topo];
}

int StackInt::top () const
{
	if ( empty() )
		throw length_error( "UnderFlow" );
	return P[topo-1];

}

void StackInt::printArray ()
{
	cout << "\n###### PILHA #########" << endl;
	for (int x =0; x<topo; x++)
		cout << P[x] << endl;
	cout << "########################" << endl;
}
