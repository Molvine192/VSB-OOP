#include "Vehicle.h"

int Vehicle::vehicleCount = 0;

Vehicle::Vehicle(int id, double price, string name)
{
	this->id = id;
	this->price = price;
	this->name = name;
	
	Vehicle::vehicleCount++;
}

Vehicle::~Vehicle()
{
	Vehicle::vehicleCount--;
}

int Vehicle::GetID() const
{
	return this->id;
}

string Vehicle::GetName()
{
	return this->name;
}

int Vehicle::GetCount()
{
	return Vehicle::vehicleCount;
}