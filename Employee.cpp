#include "Employee.h"

using namespace std;

Employee::Employee() : _name(NULL){
	_years = 0;
}

Employee::Employee(const char* name, int years) {
	setName(name);
	setYears(years);
}

Employee::Employee(const Employee& other) {
	_name = new char[strlen(other._name) + 1];
	strcpy(_name, other._name);
	_years = other._years;
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		delete[] _name;
		_name = new char[strlen(other._name) + 1];
		strcpy(_name, other._name);
		_years = other._years;
	}
	return *this;
}

Employee::~Employee() {
	delete[] _name;
}

void Employee::setName(const char* name) {
	delete[] _name;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
}

void Employee::setYears(int years) {
	_years = years;
}

Employee* Employee::clone() const {
	return new Employee(*this);
}

int Employee::getSalary() {
	return _years * 2 + 500;
}