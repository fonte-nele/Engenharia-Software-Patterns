#ifndef FLOW_H
#define FLOW_H

#include "System.h"

class Flow
{
	public:
		virtual double execute() 			= 0;
		virtual System* getSource() 		= 0;       
		virtual void setSource(System* source) 		= 0;
		virtual System* getTarget() 		= 0;
		virtual void setTarget(System* target) 		= 0;
		virtual std::string& getID() 		= 0;
		virtual void setID(const std::string& id)	= 0;
		virtual double getFlowRate() 		= 0;
		virtual void setFlowRate(const double &flow_rate) 		= 0;
		virtual double getLastExecution() 	= 0;
		virtual void setLastExecution(const double &flow_rate) 	= 0;
};

#endif