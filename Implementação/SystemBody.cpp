#include "SystemBody.h"

SystemBody::SystemBody() : Body(){}

SystemBody::SystemBody(const SystemBody &system_body) : Body()
{
	this->id = system_body.id;
	this->max_value = system_body.max_value;
	this->value = system_body.value;
}

SystemBody::~SystemBody(){ }

SystemBody& SystemBody::operator=(const SystemBody &system_body)
{
	if(this != &system_body){
		this->id = system_body.id;
		this->max_value = system_body.max_value;
		this->value = system_body.value;
	}
	return *this;
}

std::string SystemBody::getID() const{
	return id;
}

void SystemBody::setID(const std::string& id) {
	this->id = id;
}

double SystemBody::getValue() const {
	return value;
}

void SystemBody::setValue(double value) {
	this->value = value;
}

double SystemBody::getMaxValue() const {
	return max_value;
}

void SystemBody::setMaxValue(double max_value) {
	this->max_value = max_value;
}

