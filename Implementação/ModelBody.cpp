#include "ModelBody.h"
#include "ModelHandle.h"
#include <iostream>
using namespace std;

std::vector<Model*> ModelBody::models;

Model* Model::createModel(std::string id)
{
	return ModelBody::createModel(id);
}

Model* ModelBody::createModel(std::string id)
{
	Model* model = new ModelHandle(id);
	Model::addModel(model);
	return model;
}

System* ModelBody::createSystem(std::string id, double value, double max_value)
{
	System* s = new SystemHandle(id, value, max_value);

	this->addSystem(s);
	return s;
}

void Model::addModel(Model* model)
{
	return ModelBody::addModel(model);
}

void ModelBody::addModel(Model* model)
{
	models.push_back(model);
}

ModelBody::ModelBody() : Body(){}

ModelBody::ModelBody(const ModelBody &other)
{
	//this->id = other.id;
	//this->models = other.models;
	//this->flows = other.flows;
	Model::FlowIterator itf = flowBegin();
    while(itf != flowEnd())
    {
        //Deletar os vigentes e Atribuir os novos
        itf++;
    }
    
    Model::StockIterator its = systemBegin();
    while(its != systemEnd())
    {
    	//Deletar os vigentes e Atribuir os novos
       	its++;
    }
}

ModelBody::~ModelBody(){
    Model::FlowIterator itf = flowBegin();
    while(itf != flowEnd())
    {
        delete (SystemHandle*) (*itf)->getSource();
        delete (SystemHandle*) (*itf)->getTarget();
        delete (FlowHandle*) *itf;
        itf++;
    }

    Model::StockIterator its = systemBegin();
    while(its != systemEnd())
    {
        delete (SystemHandle*) *its;
       	its++;
    }
}

ModelBody& ModelBody::operator=(const ModelBody &other)
{
	Model::FlowIterator itf = flowBegin();
    while(itf != flowEnd())
    {
        //Deletar os vigentes e Atribuir os novos
        itf++;
    }

    Model::StockIterator its = systemBegin();
    while(its != systemEnd())
    {
    	//Deletar os vigentes e Atribuir os novos
       	its++;
    }
	
	return *this;
}

void ModelBody::execute(int init_time, int time, int step)
{
	Model::FlowIterator it;
	System *source;
	System *target;

	for(int j = init_time; j < time; j+=step)
	{
		it = flowBegin();
        while(it != flowEnd())
        {
			(*it)->setLastExecution((*it)->execute());
			it++;
		}

        it = flowBegin();
		while(it != flowEnd())
		{
			source = (*it)->getSource();
			target = (*it)->getTarget();
			source->setValue(source->getValue() - (*it)->getLastExecution());
			target->setValue(target->getValue() + (*it)->getLastExecution());
			it++;
		}
	}

}

void ModelBody::addSystem(System *system)
{
	stocks.push_back(system);
}

void ModelBody::addFlow(Flow* flow) 
{
	flows.push_back(flow);
}

std::string& ModelBody::getID()
{
	return id;
}

void ModelBody::setID(const std::string& id) 
{
	this->id = id;
}

Model::Model::FlowIterator ModelBody::flowBegin()
{
    return flows.begin();
}

Model::Model::FlowIterator ModelBody::flowEnd()
{
    return flows.end();
}

Model::Model::StockIterator ModelBody::systemBegin()
{
    return stocks.begin();
}

Model::Model::StockIterator ModelBody::systemEnd()
{
    return stocks.end();
}


bool ModelBody::forEach(bool (*f) (System*))
{
	Model::StockIterator it = systemBegin();
	for(;it != systemEnd(); it++)
	{
		if(!f(*it))
			break;
		else
			return false;
	}
	return true;
}

bool ModelBody::forEach(bool (*f) (Flow*))
{
	Model::FlowIterator it = flowBegin();
	for(;it != flowEnd(); it++)
	{
		if(f(*it))
			break;
		else
			return false;

	}
	return true;
}
