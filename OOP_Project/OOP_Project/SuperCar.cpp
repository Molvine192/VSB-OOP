#include "SuperCar.h"

SuperCar::SuperCar(int id, double p, string n, double ep, double at100, string d) : Car(id, p, n, ep, at100, d) {}

int SuperCar::GetSellingPoints() const
{
	return 3;
}

string SuperCar::GetType() const
{
	return "SuperCar";
}