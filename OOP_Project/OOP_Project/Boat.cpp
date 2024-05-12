#include "Boat.h"

int Boat::boatCount = 0;

Boat::Boat(int id, double p, string n, string d) : Vehicle(id, p, n), drive(d) 
{ 
	Boat::boatCount++; 
}

Boat::~Boat()
{
	Boat::boatCount--;
}

string Boat::GetDrive()
{
	return this->drive;
}

double Boat::GetPrice() const
{
	double epCoef = this->drive == "sailing-motor" ? 0.1 : this->drive == "motor" ? 0.05 : 0;
	double totalCoef = 1.1 + epCoef;
	return price * totalCoef;
}

int Boat::GetSellingPoints() const
{
	return 4;
}

void Boat::Info() const
{
	cout << "(" << this->id << ") " << this->GetType() << " - " << this->name << ", " << this->drive << ", total price: " << this->GetPrice() << "$" << endl;
}

string Boat::GetType() const
{
	return "Boat";
}

int Boat::GetCount()
{
	return Boat::boatCount;
}