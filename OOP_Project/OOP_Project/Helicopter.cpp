#include "Helicopter.h"

int Helicopter::helicopterCount = 0;

Helicopter::Helicopter(int id, double p, string n, double ep) : Vehicle(id, p, n), enginePower(ep)
{
	Helicopter::helicopterCount++;
}

Helicopter::~Helicopter()
{
	Helicopter::helicopterCount--;
}

double Helicopter::GetEnginePower()
{
	return this->enginePower;
}

double Helicopter::GetPrice() const
{
	double epCoef = 0.02 * (int)(this->enginePower / 1000);
	double totalCoef = 1.1 + epCoef;
	return price * totalCoef;
}

int Helicopter::GetSellingPoints() const
{
	return 5;
}

void Helicopter::Info() const
{
	cout << "(" << this->id << ") " << this->GetType() << " - " << this->name << ", " << this->enginePower << "hp, total price: " << this->GetPrice() << "$" << endl;
}

string Helicopter::GetType() const
{
	return "Helicopter";
}

int Helicopter::GetCount()
{
	return Helicopter::helicopterCount;
}