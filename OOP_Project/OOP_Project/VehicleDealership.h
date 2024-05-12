#pragma once

#include "Vehicle.h"
#include "Staff.h"

class VehicleDealership
{
private:
	double balance;
	double prevBalance;
	double sold;
	Vehicle** vehicles;
	Staff** staff;
	int soldThisMonth;

public:
	VehicleDealership(double balance, int vN, int sN);
	~VehicleDealership();

	Vehicle* BuyVehicle(string type, int id, double price, string name, double enginePower, double accelerationTo100, string drive);
	bool SellVehicle(int id, int staffID);

	Staff* AddStaff(int id, string fullName);
	Staff* AddStaff(int id, string fullName, double salary);
	bool RemoveStaff(int id);
	Staff* SearchStaff(int id);

	void Payment();

	void Info();
};