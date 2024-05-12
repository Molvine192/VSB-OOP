#include "Car.h"

int Car::carCount = 0;

Car::Car(int id, double p, string n, double ep, double at100, string d) : Vehicle(id, p, n), enginePower(ep), accelerationTo100(at100), drive(d) 
{ 
	Car::carCount++; 
}

Car::~Car()
{
	Car::carCount--;
}

double Car::GetEnginePower()
{
	return this->enginePower;
}

double Car::GetAccelerationTo100()
{
	return this->accelerationTo100;
}

string Car::GetDrive()
{
	return this->drive;
}

double Car::GetPrice() const
{
	double epCoef = 0.01 * (int)(this->enginePower / 300);
	double at100Coef = max((double)0, 0.03 - 0.005 * (int)this->accelerationTo100);
	double driveCoef = (this->drive == "AWD" ? 0.01 : 0);
	double totalCoef = 1.1 + epCoef + at100Coef + driveCoef;
	return price * totalCoef;
}

void Car::Info() const
{
	cout << "(" << this->id << ") " << this->GetType() << " - " << this->name << ", " << this->drive << " " << this->enginePower << "hp, total price: " << this->GetPrice() << "$" << endl;
}

int Car::GetCount()
{
	return Car::carCount;
}