#include "Staff.h"
#include "DefaultSalary.h"

int Staff::staffCount = 0;

Staff::Staff(int id, string fullName)
{
	this->id = id;
	this->fullName = fullName;
	this->balance = 0;
	this->sellingPoints = 0;
	this->salary = DefaultSalary::GetDefaultSalary();

	Staff::staffCount++;
}

Staff::Staff(int id, string fullName, double salary)
{
	this->id = id;
	this->fullName = fullName;
	this->balance = 0;
	this->sellingPoints = 0;
	this->salary = salary;

	Staff::staffCount++;
}

Staff::~Staff()
{
	Staff::staffCount--;
}

int Staff::GetID()
{
	return this->id;
}

string Staff::GetFullName()
{
	return this->fullName;
}

double Staff::GetBalance()
{
	return this->balance;
}

double Staff::GetSalary()
{
	return this->salary;
}

int Staff::GetSellingPoints()
{
	return this->sellingPoints;
}

void Staff::AddSellingPoints(int points)
{
	this->sellingPoints += points;
}

void Staff::Payment()
{
	this->salary += 500 * (this->sellingPoints / 5);

	this->balance += this->salary;
	this->sellingPoints = 0;
}

void Staff::Info()
{
	cout << "Staff (" << this->id << ") " << this->fullName << " -  salary " << this->salary << "$, selling points " << this->sellingPoints << " this month" << endl;
}

int Staff::GetCount()
{
	return Staff::staffCount;
}