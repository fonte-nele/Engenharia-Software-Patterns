#ifndef SYSTEMHANDLE_H
#define SYSTEMHANDLE_H

#include <string>
#include "Handle.h"
#include "SystemBody.h"
#include "System.h"

class SystemHandle : public System, Handle<SystemBody>
{
	public:
		SystemHandle(std::string id, double value, double max_value);
		SystemHandle(const System& system);
		SystemHandle();
		
		virtual ~SystemHandle();
		SystemHandle& operator=(const SystemHandle &);
		
		double getValue() const;
		double getMaxValue() const;
		void setMaxValue(double max_value);
		void setValue(double value);
		std::string getID() const;
		void setID(const std::string& id);
};

#endif
