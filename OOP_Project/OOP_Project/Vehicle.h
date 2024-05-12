#pragma once

#include <iostream>

using namespace std;

class Vehicle
{
private:
	static int vehicleCount;

protected:
	int id;
	double price;
	string name;

public:
	Vehicle(int id, double price, string name);
	~Vehicle();

	int GetID() const;
	string GetName();

	virtual string GetType() const = 0;
	virtual double GetPrice() const = 0;
	virtual int GetSellingPoints() const = 0;
	virtual void Info() const = 0;

	static int GetCount();
};