#ifndef FLOWBODY_H
#define FLOWBODY_H

#include <string>
#include "Body.h"
#include "System.h"

class FlowBody : public Body 
{
	public:
	    FlowBody();
	    FlowBody(const FlowBody &);
	    
	    ~FlowBody();
	    FlowBody& operator=(const FlowBody &);
	    
		System* getSource();
		void setSource(System* source);
		System* getTarget();
		void setTarget(System* target_tock);
		std::string& getID();
		void setID(const std::string& id);
		double getFlowRate();
		void setFlowRate(const double &flow_rate);
		double getLastExecution();
		void setLastExecution(const double &last_execution);

	private:
	    System* source;
	    System* target;
	    std::string id;
	    double flow_rate;
 		double last_execution;
};

#endif