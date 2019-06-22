#include "SystemHandle.h"

SystemHandle::SystemHandle(std::string id, double value, double max_value) : Handle<SystemBody>()
{
	SystemHandle::pImpl_->setID(id);
	SystemHandle::pImpl_->setValue(value);
	SystemHandle::pImpl_->setMaxValue(max_value);
}

SystemHandle::SystemHandle(const System& system) : Handle<SystemBody>()
{
	SystemHandle::pImpl_->setID((*new std::string(system.getID())));
	SystemHandle::pImpl_->setMaxValue((*new double(system.getMaxValue())));
	SystemHandle::pImpl_->setValue((*new double(system.getValue())));
}

SystemHandle::SystemHandle() : Handle<SystemBody>()
{
	SystemHandle::pImpl_->setMaxValue(0.0);
	SystemHandle::pImpl_->setValue(0.0);
}

SystemHandle::~SystemHandle(){ }

SystemHandle& SystemHandle::operator=(const SystemHandle &system_handle)
{
	if(this != &system_handle)
	{
		SystemHandle::pImpl_->setID(system_handle.getID());
		SystemHandle::pImpl_->setMaxValue(system_handle.getMaxValue());
		SystemHandle::pImpl_->setValue(system_handle.getValue());
	}
	return *this;
}

double SystemHandle::getValue() const 
{
	return SystemHandle::pImpl_->getValue();
}

void SystemHandle::setValue(double value)
{
	SystemHandle::pImpl_->setValue(value);
}

double SystemHandle::getMaxValue() const 
{
	return SystemHandle::pImpl_->getMaxValue();
}

void SystemHandle::setMaxValue(double max_value) 
{
	SystemHandle::pImpl_->setMaxValue(max_value);
}

std::string SystemHandle::getID() const
{
	return SystemHandle::pImpl_->getID();
}

void SystemHandle::setID(const std::string& id) 
{
	SystemHandle::pImpl_->setID(id);
}
