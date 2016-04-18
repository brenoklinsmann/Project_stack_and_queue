#include <iostream>
#include <stdexcept>

#include "AbsQueue.h"
using namespace std;

template <typename Object>
class QueueAr : public AbsQueue<Object>
{
	public:
		QueueAr ( int size = 10 );
		~QueueAr ( );

		void enqueue ( const Object & );
		Object dequeue ();
		Object getFront ( ) const;
		bool isEmpty ( ) const;
		void makeEmpty ( );
	private:
		Object *queue;
		int F; // Front : Aponta para a primeira posição da fila.
		int R; // Rear : Aponta para a última posição da fila;
		int capacity;
		void resize ( int );
			
};

template <typename Object>
QueueAr<Object>::QueueAr ( int size ) :
	F ( -1 ), R ( 0 ),
	capacity ( size ),
	queue ( nullptr )
{
	if ( size < 0 )
		throw invalid_argument ("ARGUMENTO iNVALIDO !");
	queue = new Object [capacity];

}

template <typename Object>
QueueAr<Object>::~QueueAr ()
{
	delete [] queue;
}

template <typename Object>
void QueueAr<Object>::enqueue ( const Object & newVal )
{
	if ( R == F )
		resize ( capacity*2 );
	queue[R] = newVal;
	if ( F == -1 ) F++, R++;
	else if ( R+1 == capacity ) R = 0;
	else R++;
}

template <typename Object>
void QueueAr<Object>::resize ( int newSize ) 
{
	Object *newQueue = new Object [newSize];
	int j = 0;
	for (int i = F; i<capacity; i++, j++)
		newQueue[j] = queue[i];

	for ( int i = 0; i<R ; i++, j++)
		newQueue[j] = queue[i];

	delete [] queue;
	queue = newQueue;
	F = 0, R = j;
	capacity = newSize;
	cout << "\n>>> Resize para " << newSize << endl;
}

template <typename Object>
Object QueueAr<Object>::dequeue ( )
{
	if ( isEmpty() )
		throw out_of_range ("DEQUEUE() : UNDERFLOW !");
	int aux = F;
	F++;
	if ( F == capacity ) F = 0;
	return queue[aux];		
}

template <typename Object>
Object QueueAr<Object>::getFront () const
{
	if ( isEmpty() )
		throw out_of_range ("GETFRONT() : UNDERFLOW !");
	return queue[F];
}

template <typename Object>
bool QueueAr<Object>::isEmpty () const
{
	return ( F== -1 && R == 0 );
}

template <typename Object>
void QueueAr<Object>::makeEmpty ()
{
	F= -1, R =0;
}