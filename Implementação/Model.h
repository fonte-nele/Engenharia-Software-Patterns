#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <string>
#include "Flow.h"
#include "FlowHandle.h"
#include "System.h"
#include "SystemHandle.h"

class Model
{

	public:
	    static Model* createModel(std::string id);
		virtual System* createSystem(std::string id, double value, double max_value) = 0;

	    virtual void addSystem(System *system) = 0;
	    virtual void addFlow(Flow *flow) = 0;

		virtual void execute(int init_time, int time, int step) = 0;
		virtual std::string& getID() = 0;
		virtual void setID(const std::string& id) = 0;

	    typedef std::vector<Flow *>::iterator FlowIterator;
	    virtual FlowIterator flowBegin() = 0;
	    virtual FlowIterator flowEnd() = 0;

	    typedef std::vector<System*>::iterator StockIterator;
	    virtual StockIterator systemBegin() = 0;
	    virtual StockIterator systemEnd() = 0;

	    virtual bool forEach(bool (*f) (System*)) = 0;
	    virtual bool forEach(bool (*f) (Flow*)) = 0;
	    static void addModel(Model* model);
	    
	    template<typename FLOW_TYPE>
		FLOW_TYPE* createFlow(const std::string &id, System *source, System *target, double flow_rate)
		{
			FLOW_TYPE* f = new FLOW_TYPE(id, source, target, flow_rate);

			f->setID(id);
			f->setSource(source);
			f->setTarget(target);
			f->setFlowRate(flow_rate);

			this->addFlow(f);

			return f;
		}
};

#endif