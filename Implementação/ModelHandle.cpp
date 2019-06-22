#include "ModelHandle.h"
#include "Model.h"
#include <iostream>

std::vector<Model*> ModelHandle::models;

Model* ModelHandle::createModel(std::string id)
{
	return ModelBody::createModel(id);
}

System* ModelHandle::createSystem(std::string id, double value, double max_value)
{
  return ModelHandle::pImpl_->createSystem(id, value, max_value);
}

void ModelHandle::addModel(Model* model)
{
	return ModelBody::addModel(model);
}

ModelHandle::ModelHandle(std::string id) 
{
  ModelHandle::pImpl_->setID(id);
}

ModelHandle::ModelHandle(Model& model)
{
	ModelHandle::pImpl_->setID((*new std::string(model.getID())));
   
  StockIterator its = model.systemBegin();
  for(; its != model.systemEnd(); ++its)
    pImpl_->addSystem((*its));
    
  FlowIterator itf = model.flowBegin();
  for(; itf != model.flowEnd(); ++itf)
    pImpl_->addFlow(*itf);
}

ModelHandle::ModelHandle(){}

ModelHandle::~ModelHandle(){ }

ModelHandle& ModelHandle::operator=(ModelHandle& model)
{
	if(this != &model)
  {
    this->id.clear();

		FlowIterator itf = flowBegin();
		while(itf != flowEnd())
    {
      delete (*itf)->getSource();
      delete (*itf)->getTarget();
      delete *itf;
      itf++;
    }

    itf = model.flowBegin();
    while(itf != flowEnd())
    {
        this->addFlow(*itf);
        itf++;
    }

    StockIterator its = systemBegin();
    while(its != systemEnd())
    {
      delete *its;
      its++;
    }
           
    its = model.systemBegin();
    while(its != systemEnd())
    {
      this->addSystem(*its);
      its++;
    }       

    this->id = model.getID();
  }
  return *this;
}

void ModelHandle::execute(int init_time, int time, int step)
{
  ModelHandle::pImpl_->execute(init_time, time, step);
}

void ModelHandle::addSystem(System *system)
{
  ModelHandle::pImpl_->addSystem(system);
}

void ModelHandle::addFlow(Flow* flow)
{
	ModelHandle::pImpl_->addFlow(flow);
}

std::string& ModelHandle::getID()
{
    return pImpl_->getID();
}

void ModelHandle::setID(const std::string& id) 
{
	pImpl_->setID(id);
}

Model::FlowIterator ModelHandle::flowBegin()
{
    return pImpl_->flowBegin();
}

Model::FlowIterator ModelHandle::flowEnd()
{
    return pImpl_->flowEnd();
}

Model::StockIterator ModelHandle::systemBegin()
{
    return pImpl_->systemBegin();
}

Model::StockIterator ModelHandle::systemEnd()
{
    return pImpl_->systemEnd();
}


bool ModelHandle::forEach(bool (*f) (System*))
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

bool ModelHandle::forEach(bool (*f) (Flow*))
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
