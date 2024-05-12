#pragma once

#include "Car.h"

class SuperCar : public Car
{
public:
	SuperCar(int id, double price, string name, double enginePower, double accelerationTo100, string drive);

	int GetSellingPoints() const override;
	string GetType() const override;
};