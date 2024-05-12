#include "SportCar.h"

SportCar::SportCar(int id, double p, string n, double ep, double at100, string d) : Car(id, p, n, ep, at100, d) {}

int SportCar::GetSellingPoints() const
{
	return 2;
}

string SportCar::GetType() const
{
	return "SportCar";
}