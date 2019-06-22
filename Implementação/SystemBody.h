#ifndef SYSTEMBODY_H
#define SYSTEMBODY_H

#include <string>
#include "System.h"
#include "Body.h"

class SystemBody : public Body
{

	public:
		SystemBody();
		SystemBody(const SystemBody &);
		
		~SystemBody();
		SystemBody& operator=(const SystemBody &);
		
		std::string getID() const;
		void setID(const std::string& id);
		double getValue() const;
		void setValue(double value);
		double getMaxValue() const;
		void setMaxValue(double max_value);

	private:
		double max_value;
		double value;
		std::string id;
};

#endif
