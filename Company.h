#pragma once
#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"
#include "Sales.h"
#include "Programmer.h"
#include "Manager.h"

typedef Employee* EmployeePtr;

class Company
{
public:
	Company(EmployeePtr*, int numEmployees);
	Company(const Company& company);
	Company& operator = (const Company& other);
	~Company();

	const int getEmployeesCount(){ return _numEmployees; }

	void addEmployee(const Employee* employee)
	{
			_arr[_numEmployees] = employee->clone();
			++_numEmployees;
	}

	void removeSales(int salary)
	{
		for (int i = 0; i < _numEmployees; ++i)
		{
			Sales* sales = dynamic_cast<Sales*>(_arr[i]);
			if (sales != NULL)
			{
				if (sales->getSalary() > salary)
				{
					delete sales;
					for (int j = i; j < _numEmployees - 1; ++j)
					{
						_arr[j] = _arr[j + 1];
					}
					_arr[_numEmployees - 1] = NULL;
					--_numEmployees;
				}
			}
		}
	}

	void removeProgrammer(int salary)
	{
		for (int i = 0; i < _numEmployees; ++i)
		{
			Programmer* programmer = dynamic_cast<Programmer*>(_arr[i]);
			if (programmer != NULL)
			{
				if (programmer->getSalary() > salary)
				{
					delete programmer;
					for (int j = i; j < _numEmployees - 1; ++j)
					{
						_arr[j] = _arr[j + 1];
					}
					_arr[_numEmployees - 1] = NULL;
					--_numEmployees;
				}
			}
		}
	}

	void removeManager(int salary)
	{
		for (int i = 0; i < _numEmployees; ++i)
		{
			Manager* manager = dynamic_cast<Manager*>(_arr[i]);
			if (manager != NULL)
			{
				if (manager->getSalary() < salary)
				{
					delete manager;

					for (int j = i; j < _numEmployees - 1; ++j)
					{
						_arr[j] = _arr[j + 1];
					}
					_arr[_numEmployees - 1] = NULL;
					--_numEmployees;
				}
			}
		}
	}

	void removeEmployee(int salary)
	{
		for (int i = 0; i < _numEmployees; ++i)
		{
			Employee* employee = dynamic_cast<Employee*>(_arr[i]);
			if (employee != NULL)
			{
				if (employee->getYears() < salary)
				{
					delete employee;

					for (int j = i; j < _numEmployees - 1; ++j)
					{
						_arr[j] = _arr[j + 1];
					}
					_arr[_numEmployees - 1] = NULL;
					--_numEmployees;
				}
			}
		}
	}


private:

	void copyCompany(const Company& other);

	void deleteCompany();

	EmployeePtr *_arr;
	int _numEmployees;
	int _capacity;
};

#endif