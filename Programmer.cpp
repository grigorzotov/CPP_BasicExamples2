#include <iostream>
#include "Programmer.h"

Programmer::Programmer() :Employee() {
	_programs=0;
}

Programmer::Programmer(const char* name, int years, int programs)
	: Employee(name, years)
	, _programs(programs)
{

}

int Programmer::getSalary() {
	return 2 * _programs + 200;
}

Programmer* Programmer::clone() {
	return new Programmer(*this);
}