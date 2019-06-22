#include "FlowHandle.h"

FlowHandle::FlowHandle(std::string id, System* source, System* target, double flow_rate) : Handle<FlowBody>()
{
	FlowHandle::pImpl_->setID(id);
	FlowHandle::pImpl_->setSource(source);
	FlowHandle::pImpl_->setTarget(target);
	FlowHandle::pImpl_->setFlowRate(flow_rate);
}

FlowHandle::FlowHandle(Flow& _flow) : Handle<FlowBody>()
{
	FlowHandle::pImpl_->setID(*new std::string(_flow.getID()));
	FlowHandle::pImpl_->setSource(_flow.getSource());
	FlowHandle::pImpl_->setTarget(_flow.getTarget());
}

FlowHandle::FlowHandle() : Handle<FlowBody>(){}

FlowHandle::~FlowHandle(){ }

FlowHandle& FlowHandle::operator=(FlowHandle &other)
{
	if(this != &other)
	{
		FlowHandle::pImpl_->setID(other.getID());
		FlowHandle::pImpl_->setSource(other.getSource());
		FlowHandle::pImpl_->setTarget(other.getTarget());
	}
	return *this;
}

System* FlowHandle::getSource()
{
	return FlowHandle::pImpl_->getSource();
}

void FlowHandle::setSource(System* source) 
{
	FlowHandle::pImpl_->setSource(source);
}

System* FlowHandle::getTarget()
{
	return FlowHandle::pImpl_->getTarget();
}

void FlowHandle::setTarget(System* target) 
{
	FlowHandle::pImpl_->setTarget(target);
}

std::string& FlowHandle::getID() 
{
	return FlowHandle::pImpl_->getID();
}

void FlowHandle::setID(const std::string& id) 
{
	FlowHandle::pImpl_->setID(id);
}

double FlowHandle::getFlowRate()
{
	return FlowHandle::pImpl_->getFlowRate();
}

void FlowHandle::setFlowRate(const double &flow_rate)
{
	FlowHandle::pImpl_->setFlowRate(flow_rate);
}

double FlowHandle::getLastExecution()
{	
	return FlowHandle::pImpl_->getLastExecution();
}

void FlowHandle::setLastExecution(const double &last_execution)
{
	FlowHandle::pImpl_->setLastExecution(last_execution);
}