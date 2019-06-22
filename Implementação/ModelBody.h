#ifndef MODELBODY_H
#define MODELBODY_H

#include "Body.h"
#include "Model.h"
#include "System.h"
#include "SystemHandle.h"
#include "Flow.h"
#include "FlowHandle.h"

class ModelBody : public Body
{
	public:
		static Model* createModel(std::string id);
		System* createSystem(std::string id, double value, double max_value);
		
		ModelBody();
		ModelBody(const ModelBody &);
		
		virtual ~ModelBody();
		ModelBody& operator=(const ModelBody &);
		
	    void execute(int init_time, int time, int step);
		std::string& getID();
		void setID(const std::string& id);

		Model::FlowIterator flowBegin();
	    Model::FlowIterator flowEnd();
		Model::StockIterator systemBegin();
	    Model::StockIterator systemEnd();

		bool forEach(bool (*f) (System*));
	    bool forEach(bool (*f) (Flow*)) ;

		static void addModel(Model* model);
		void addSystem(System*system);
		void addFlow(Flow*flow);
	private:
		static std::vector<Model*> models;

		std::vector<System*> stocks;
		std::vector<Flow*> flows;
		std::string id;
};

#endif
