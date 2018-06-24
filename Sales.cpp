#include "Sales.h"

Sales::Sales() : Employee(){
	this->_sales = 0;
}

Sales::Sales(const char* name, int years, int sales) : Employee(name, years), _sales(sales)
{}

int Sales::getSalary() {
	return 3 * _sales + 100;
}

Sales* Sales::clone() {
	return new Sales(*this);
}