#pragma once

#include "Vehicle.h"

class Helicopter : public Vehicle
{
private:
	static int helicopterCount;

protected:
	double enginePower;

public:
	Helicopter(int id, double price, string name, double enginePower);
	~Helicopter();

	double GetEnginePower();

	double GetPrice() const override;
	int GetSellingPoints() const override;
	void Info() const override;

	string GetType() const override;

	static int GetCount();
};