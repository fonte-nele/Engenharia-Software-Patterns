#include "Body.h"

//#define DEBUGING
#ifdef DEBUGING
    extern int numBodyCreated;
    extern int numBodyDeleted;
#endif

Body::Body():refCount_(0)
{
    #ifdef DEBUGING
        numBodyCreated++;
    #endif
}

Body::Body(const Body&):refCount_(0)
{
    #ifdef DEBUGING
        numBodyCreated++;
    #endif
}

Body::~Body()
{
    #ifdef DEBUGING
        numBodyDeleted++;
    #endif
}

Body& Body::operator=(const Body &b)
{
    return *this;
}

void Body::attach()
{
    refCount_++;
}

void Body::detach()
{
    if ( --refCount_ == 0 )
    { 
		delete this;
	}
}

int Body::refCount()
{
    return refCount_;
}