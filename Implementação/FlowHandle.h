#ifndef FLOWHANDLE_H
#define FLOWHANDLE_H

#include <string>
#include "Flow.h"
#include "FlowBody.h"
#include "Handle.h"

class FlowHandle : Handle<FlowBody>, public Flow 
{
	public:
	    FlowHandle(std::string id, System* source, System* target, double flow_rate);
	    FlowHandle(Flow& _flow);
	    FlowHandle();
	    
	    virtual ~FlowHandle();
		FlowHandle& operator=(FlowHandle &);
		    
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
};

#endif