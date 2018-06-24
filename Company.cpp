#include "Company.h"


Company::Company(EmployeePtr *arr, int numEmployees)
	: _arr(NULL), _numEmployees(0)
{
	_numEmployees = numEmployees;
	_arr = new EmployeePtr[numEmployees];
	for (int i = 0; i < numEmployees; ++i)
	{
		_arr[i] = arr[i]->clone();
	}
}

Company::Company(const Company& company)
	: _arr(NULL), _numEmployees(0)
{
	copyCompany(company);
}

Company& Company:: operator= (const Company& other)
{
	if (this != &other)
	{
		deleteCompany();
		copyCompany(other);
	}
	return *this;
}

Company::~Company()
{
	deleteCompany();
}


void Company::copyCompany(const Company& other)
{
	_numEmployees = other._numEmployees;
	_arr = new EmployeePtr[_numEmployees];

	for (int i = 0; i < _numEmployees; ++i)
	{
		_arr[i] = other._arr[i]->clone();
	}
}

void Company::deleteCompany()
{
	delete[] _arr;
	_arr = NULL;
}