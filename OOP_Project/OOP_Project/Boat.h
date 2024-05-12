#pragma once

#include "Vehicle.h"

class Boat : public Vehicle
{
private:
	static int boatCount;

protected:
	string drive; // sailing, motor or sailing-motor

public:
	Boat(int id, double price, string name, string drive);
	~Boat();

	string GetDrive();

	double GetPrice() const override;
	int GetSellingPoints() const override;
	void Info() const override;

	string GetType() const override;

	static int GetCount();
};