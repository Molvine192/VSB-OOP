#pragma once

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
private:
	static int motorcycleCount;

protected:
	double enginePower;
	double accelerationTo100;

public:
	Motorcycle(int id, double price, string name, double enginePower, double accelerationTo100);
	~Motorcycle();

	double GetEnginePower();
	double GetAccelerationTo100();

	double GetPrice() const override;
	int GetSellingPoints() const override;
	void Info() const override;

	string GetType() const override;

	static int GetCount();
};