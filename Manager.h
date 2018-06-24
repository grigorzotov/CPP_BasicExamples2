#ifndef MANAGER_H
#define MAGANER_H

#include "Sales.h"
#include "Programmer.h"

class Manager : public Sales, public Programmer {
public:
	Manager(const char* name, int years, int sales, int programs, const char* nickname, int shares);
	Manager(const Manager& other);
	Manager& operator=(const Manager& other);
	~Manager();


	void setNickname(const char* nickname);
	void setShares(int shares);

	const char* getNickname() const { return _nickname; }
	const int getShares() const { return _shares; }

	int getSalary();

	Manager* clone();
private:
	char* _nickname;
	int _shares;
}; 
#endif //!MANAGER_H
