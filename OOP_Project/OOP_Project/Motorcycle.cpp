#include "Motorcycle.h"

int Motorcycle::motorcycleCount = 0;

Motorcycle::Motorcycle(int id, double p, string n, double ep, double at100) : Vehicle(id, p, n), enginePower(ep), accelerationTo100(at100)
{
	Motorcycle::motorcycleCount++;
}

Motorcycle::~Motorcycle()
{
	Motorcycle::motorcycleCount--;
}

double Motorcycle::GetEnginePower()
{
	return this->enginePower;
}

double Motorcycle::GetAccelerationTo100()
{
	return this->accelerationTo100;
}

double Motorcycle::GetPrice() const
{
	double epCoef = 0.02 * (int)(this->enginePower / 1000);
	double at100Coef = max((double)0, 0.03 - 0.005 * (int)this->accelerationTo100);
	double totalCoef = 1.1 + epCoef + at100Coef;
	return price * totalCoef;
}

int Motorcycle::GetSellingPoints() const
{
	return 1;
}

void Motorcycle::Info() const
{
	cout << "(" << this->id << ") " << this->GetType() << " - " << this->name << ", " << this->enginePower << "hp, total price: " << this->GetPrice() << "$" << endl;
}

string Motorcycle::GetType() const
{
	return "Motorcycle";
}

int Motorcycle::GetCount()
{
	return Motorcycle::motorcycleCount;
}