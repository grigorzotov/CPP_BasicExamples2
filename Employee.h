#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <cstring>

class Employee {

private:
	char* _name;
	int _years;

public:
	Employee();
	Employee(const char*, int);
	Employee(const Employee&);
	Employee& operator=(const Employee& );
	~Employee();

	void setName(const char*);
	void setYears(int);

	const char* getName() const { return _name; }
	int getYears() const { return _years; }
	virtual int getSalary();

	Employee* clone() const;

};

#endif // !EMPLOYEE_H
#pragma once
