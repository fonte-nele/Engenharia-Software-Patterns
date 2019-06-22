#ifndef MODELHANDLE_H
#define MODELHANDLE_H

#include "Handle.h"
#include "ModelBody.h"
#include "Model.h"

class ModelHandle : public Handle<ModelBody>, public Model
{
	public:
		static Model* createModel(std::string id);
		System* createSystem(std::string id, double value, double max_value);

		ModelHandle(std::string id);
		ModelHandle(Model& modelHandle);
		ModelHandle();
		virtual ~ModelHandle();
		ModelHandle& operator=(ModelHandle &);
		
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

	private:
		void addSystem(System*system);
		void addFlow(Flow*flow);

		static std::vector<Model*> models;

		std::vector<System*> stocks;
		std::vector<Flow*> flows;
		std::string id;
};

#endif
