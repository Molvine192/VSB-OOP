#pragma once

#include <iostream>
using namespace std;

class Staff
{
private:
	int id;
	string fullName;
	double balance;
	double salary;
	int sellingPoints;

	static int staffCount;

public:
	Staff(int id, string fullName);
	Staff(int id, string fullName, double salary);
	~Staff();

	int GetID();
	string GetFullName();
	double GetBalance();
	double GetSalary();
	int GetSellingPoints();

	void AddSellingPoints(int points);

	void Payment();
	void Info();

	static int GetCount();
};