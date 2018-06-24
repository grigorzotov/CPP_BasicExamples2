#ifndef SALES_H
#define SALES_H
#include "Employee.h"

class Sales : public virtual  Employee {
public:
	Sales();
	Sales(const char*, int, int);

	int getSales() const { return _sales; }
	void setSales(int sales) { this->_sales = sales; };

	int getSalary();
	Sales* clone();
private:
	int _sales;
};

#endif // !SALES_H

