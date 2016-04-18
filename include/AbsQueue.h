template <class Object>
class AbsQueue {
	public:
		AbsQueue ( ) {/*Empty*/} // Default Constructor
		virtual ~AbsQueue ( ) {/*Empty*/} // Default Destructor

		// Basic Members
		virtual void enqueue ( const Object & ) =0;
		virtual Object dequeue ( ) = 0;
		virtual Object getFront ( ) const = 0;

		virtual bool isEmpty ( ) const = 0;
		virtual void makeEmpty ( ) = 0;
	
	private:
		// Disable copy constructor
		AbsQueue ( const AbsQueue<Object> & x) {/*Empty*/}
};