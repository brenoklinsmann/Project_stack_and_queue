#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class StackInt {
	public:
		StackInt( int _size = 10);
		~StackInt ( );

		void push (int x );
		int pop ( void );
		int top ( void ) const;

		bool empty ( void ) const;
		void clear ( void );

		void printArray ( );

	private:
		int *P;
		int topo;
		int capacity;

		void resize ( int);

};