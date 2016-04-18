#include "AbsStack.h" // Inclui a interface abstrata da pilha
using namespace std;
// Implementando interface via herança.
template <typename Object>
class StackAr : public AbsStack <Object>
{
	public:
		StackAr ( int size =10 );
		~StackAr ();

		void push ( const Object & );
		Object pop ( );
		Object top ( ) const;
		bool isEmpty ( ) const;
		void makeEmpty ( );
		void printArray ();
	private:
		int capacity, topo;
		Object *stack;
		void resize ( int );	
};

#include "stackar.inl"

