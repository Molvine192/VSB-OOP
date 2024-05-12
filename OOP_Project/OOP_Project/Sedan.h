#pragma once

#include "Car.h"

class Sedan : public Car
{
public:
	Sedan(int id, double price, string name, double enginePower, double accelerationTo100, string drive);

	int GetSellingPoints() const override;
	string GetType() const override;
};