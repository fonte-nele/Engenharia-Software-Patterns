#include "FlowBody.h"

FlowBody::FlowBody() : Body(){}

FlowBody::FlowBody(const FlowBody &other) : Body()
{
	this->id = other.id;
	this->source = other.source;
	this->target = other.target;
	this->last_execution = other.last_execution;
}

FlowBody::~FlowBody(){}

FlowBody& FlowBody::operator=(const FlowBody &other)
{
	if(this != &other)
	{
		this->id = other.id;
		this->source = other.source;
		this->target = other.target;
		this->last_execution = other.last_execution;
	}
	return *this;
}

System* FlowBody::getSource()
{
	return source;
}

void FlowBody::setSource(System* source) 
{
	this->source = source;
}

System* FlowBody::getTarget()
{
	return target;
}

void FlowBody::setTarget(System* target) 
{
	this->target = target;
}

std::string& FlowBody::getID() 
{
	return id;
}

void FlowBody::setID(const std::string& id) 
{
	this->id = id;
}

double FlowBody::getFlowRate()
{
	return flow_rate;
}

void FlowBody::setFlowRate(const double &flow_rate)
{
	this->flow_rate = flow_rate;
}

double FlowBody::getLastExecution()
{
	return last_execution;
}

void FlowBody::setLastExecution(const double &last_execution)
{
	this->last_execution = last_execution;
}