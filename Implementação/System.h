#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System
{
	public:
		virtual double getMaxValue() const = 0;
		virtual void setMaxValue(double max_value) = 0;
		virtual double getValue() const = 0;
		virtual void setValue(double value) = 0;
		virtual std::string getID() const = 0;
		virtual void setID(const std::string& id) = 0;

		friend double operator+(const System& system, double value);
		friend double operator+(double value, const System& system);
		friend double operator+(const System& system1, const System& system2);
		friend double operator-(const System& system, double value);
		friend double operator-(double value, const System& system);
		friend double operator-(const System& system1, const System& system2);
		friend double operator*(const System& system, double value);
		friend double operator*(double value, const System& system);
		friend double operator*(const System& system1, const System& system2);
		friend double operator/(const System& system, double value);
		friend double operator/(double value, const System& system);
		friend double operator/(const System& system1, const System& system2);
};

inline double operator +(const System& system1, const System& system2)
{
	return system1.getValue() + system2.getValue();
}

inline double operator +( const System& system, double value)
{
	return system.getValue() + value ;
}

inline double operator +(double value, const System& system)
{
	return value + system.getValue();
}

inline double operator -(const System& system1, const System& system2)
{
	return system1.getValue() - system2.getValue();
}

inline double operator -(const System& system, double value)
{
	return system.getValue() - value;
}

inline double operator -(double value, const System& system)
{
	return value - system.getValue();
}

inline double operator *(const System& system1, const System& system2) 
{
	return system1.getValue() * system2.getValue();
}

inline double operator *(const System& system, double value) 
{
	return system.getValue() * value;
}

inline double operator *(double value, const System& system) 
{
	return value * system.getValue();
}

inline double operator /(const System& system1, const System& system2) 
{
	return system1.getValue() / system2.getValue();
}

inline double operator /(const System& system, double value) 
{
	return system.getValue() / value;
}

inline double operator /(double value, const System& system) 
{
	return value / system.getValue();
}

#endif