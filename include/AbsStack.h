#include <iostream>
#include <stdexcept>

template <class Object>
class AbsStack {
	public:
		AbsStack() {/*Empty*/}
		virtual ~AbsStack(){/*Empty*/}


		virtual void push ( const Object & x ) = 0;
		virtual Object pop ( ) = 0;
		virtual Object top ( ) const = 0;

		virtual bool isEmpty ( ) const = 0;
		virtual void makeEmpty ( ) = 0;

	private:
		AbsStack ( const AbsStack & ) { /*Empty*/}	

};

