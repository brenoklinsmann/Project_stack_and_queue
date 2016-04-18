template <typename Object>
StackAr<Object>::StackAr( int size ) : 
	capacity ( size ),
	topo ( 0 ),
	stack ( nullptr )
{
	if ( size < 0)
		throw invalid_argument("Argumento Invalido");
	stack = new Object [capacity];

}
template <typename Object>
StackAr<Object>::~StackAr ()
{
	delete [] stack;
}

template <typename Object>
void StackAr<Object>::push ( const Object & newVal )
{
	if ( topo == capacity)
		resize(capacity*2);
	stack[topo++] = newVal;
}

template <typename Object>
void StackAr<Object>::resize ( int newSize )
{
	Object *newStack = new Object [newSize];
	for ( int i =0; i<topo; i++)
		newStack[i] = stack[i];
	delete [] stack;
	stack = newStack;
	capacity = newSize;
}

template <typename Object>
Object StackAr<Object>::pop ()
{
	if ( isEmpty() )
		throw length_error ("Pop() : Underflow");
	topo--;
	return topo;
}

template <typename Object>
Object StackAr<Object>::top () const	
{
	if ( isEmpty() )
		throw length_error ("Top() : Underflow");
	return stack[topo-1];
}

template <typename Object>
bool StackAr<Object>::isEmpty () const 
{
	return (topo == 0);
}

template <typename Object>
void StackAr<Object>::makeEmpty ()
{
	topo = 0;
	cout << "\n>>> PILHA ZERADA\n";
}

template <typename Object>
void StackAr<Object>::printArray()
{
	if ( isEmpty() )
		throw length_error ("PrintArray() : Underflow");
	cout << "\n###### PILHA #########" << endl;
	for (int i =0; i<topo; i++)
		cout << stack[i] << endl;
	cout << "######################" << endl;
	
}
