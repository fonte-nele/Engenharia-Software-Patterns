#ifndef HANDLE_H
#define HANDLE_H

//using namespace std;

//#define DEBUGING
#ifdef DEBUGING
    extern int numHandleCreated;
    extern int numHandleDeleted;
#endif

/*!
 \file Bridge.h
 \brief The classes Handle and Body implements "bridge" design pattern (also known as 
	"handle/body idiom").The class Body was implemented based on the class teCounted
	writed by Ricardo Cartaxo and Gilberto Câmara and founded in the geographic library TerraLib.
 \author Prof. Tiago Garcia de Senna Carneiro - UFOP, MG, Brazil
*/

/** 
 * \brief
 *
 * The classes Handle and Body implements the "bridge" design pattern (also known as
 * "handle/body idiom").
 * 
 */
 
template <class T> 
class Handle
{

public:	

	/// constructor
	Handle<T>( )
	{  
		pImpl_ = new T; 
        pImpl_->attach();
        #ifdef DEBUGING
            numHandleCreated++;
        #endif
	}
	
	/// Destructor
	virtual ~Handle<T>()
	{
	    pImpl_->detach();
	    #ifdef DEBUGING
            numHandleDeleted++;
        #endif
	}

	/// copy constructor 
	Handle<T>( const Handle& hd ):pImpl_( hd.pImpl_ ) { pImpl_->attach();  }

	/// assignment operator
	Handle<T>& operator=( const Handle& hd) 
	{
		if (  this != &hd )
		{
			hd.pImpl_->attach();
			pImpl_->detach();	
			pImpl_  = hd.pImpl_;
		}
		return *this;
	}
protected:

	/// referência para a implementação
	T *pImpl_; 
};

#endif