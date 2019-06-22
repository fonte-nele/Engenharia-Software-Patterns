#ifndef BODY_H
#define BODY_H

class Body
{
    public:
        Body();         // Constructor: zero references when the object is being built
        
        virtual ~Body();// Destructor
        
        void attach();  // Increases the number of references to this object
        
        /// Decreases the number of references to this object.
    	/// Destroy it if there are no more references to it
        void detach();
        
        /// Returns the number of references to this object
    	int refCount();
    	
    private:
        /// No copy allowed
    	Body(const Body&);
    	/// Implementation
    	Body& operator=(const Body&);
        int refCount_; 	/// the number of references to this class
};

#endif