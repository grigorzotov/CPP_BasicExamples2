#include <iostream>
#include <cassert>
#include <cstring>
#include "Manager.h"

using namespace std;

Manager::Manager(const char* name, int years, int sales, int programs, const char* nickname, int shares) : 
	Employee(name, years), Sales(name, years, sales), Programmer(name, years, programs), _shares(shares) {
	setNickname(nickname);
	setShares(shares);
}

Manager::Manager(const Manager& other) : 
	Employee(other.getName(),other.getYears()), 
	Sales(other.getName(), other.getYears(), other.getSales()),
	Programmer(other.getName(), other.getYears(), other.getPrograms()){
	_nickname = new char[strlen(other._nickname) + 1];
	strcpy(_nickname, other._nickname);
	_shares = other._shares;
}

Manager& Manager::operator=(const Manager& other) {
	if (this != &other) {
		delete[] _nickname;
		_nickname = new char[strlen(other._nickname) + 1];
		strcpy(_nickname, other._nickname);
		_shares = other._shares;
	}
	return *this;
}

Manager::~Manager() {
	delete[] _nickname;
}

void Manager::setNickname(const char* nickname) {
	delete[] _nickname;
	_nickname = new char[strlen(nickname) + 1];
	strcpy(_nickname, nickname);
}

void Manager::setShares(int shares) {
	_shares = shares;
}

int Manager::getSalary() {
	return 3 * _shares + 1000;
}

Manager* Manager::clone() {
	return new Manager(*this);
}
