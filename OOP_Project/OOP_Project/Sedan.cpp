#include "Sedan.h"

Sedan::Sedan(int id, double p, string n, double ep, double at100, string d) : Car(id, p, n, ep, at100, d) {}

int Sedan::GetSellingPoints() const
{
	return 1;
}

string Sedan::GetType() const
{
	return "Sedan";
}