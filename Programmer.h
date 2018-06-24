#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "Employee.h"

class Programmer : public virtual  Employee {
public:

	Programmer();
	Programmer(const char* name, int years, int programs);
	
	int getPrograms() const { return _programs; }
	void setSales(int programs) { this->_programs = programs; };

	int getSalary();
	Programmer* clone();
private:
	int _programs;
};

#endif // !PROGRAMMER_H