#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
private:
	static int carCount;

protected:
	double enginePower;
	double accelerationTo100;
	string drive;

public:
	Car(int id, double price, string name, double enginePower, double accelerationTo100, string drive);
	~Car();

	double GetEnginePower();
	double GetAccelerationTo100();
	string GetDrive();

	double GetPrice() const override;
	void Info() const override;

	static int GetCount();
};