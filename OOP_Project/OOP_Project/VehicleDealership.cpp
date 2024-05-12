#include "VehicleDealership.h"
#include "Sedan.h"
#include "SportCar.h"
#include "SuperCar.h"
#include "Motorcycle.h"
#include "Helicopter.h"
#include "Boat.h"

VehicleDealership::VehicleDealership(double b, int vN, int sN) : balance(b), prevBalance(b), sold(0), soldThisMonth(0)
{
	this->vehicles = new Vehicle * [vN];
	for (int i = 0; i < vN; i++)
		this->vehicles[i] = nullptr;

	this->staff = new Staff * [sN];
	for (int i = 0; i < sN; i++)
		this->staff[i] = nullptr;
}

VehicleDealership::~VehicleDealership()
{
	int i = 0;
	while (this->vehicles[i] != nullptr)
	{
		delete this->vehicles[i];
		i++;
	}
	delete[] this->vehicles;

	i = 0;
	while (this->staff[i] != nullptr)
	{
		delete this->staff[i];
		i++;
	}
	delete[] this->staff;
}

Vehicle* VehicleDealership::BuyVehicle(string type, int id, double price, string name, double enginePower, double accelerationTo100, string drive)
{
	Vehicle* newVehicle = nullptr;

	if (!(price > this->balance))
	{
		if (type == "Sedan")
		{
			newVehicle = new Sedan(id, price, name, enginePower, accelerationTo100, drive);
		}
		else if (type == "SportCar")
		{
			newVehicle = new SportCar(id, price, name, enginePower, accelerationTo100, drive);
		}
		else if (type == "SuperCar")
		{
			newVehicle = new SuperCar(id, price, name, enginePower, accelerationTo100, drive);
		}
		else if (type == "Motorcycle")
		{
			newVehicle = new Motorcycle(id, price, name, enginePower, accelerationTo100);
		}
		else if (type == "Helicopter")
		{
			newVehicle = new Helicopter(id, price, name, enginePower);
		}
		else if (type == "Boat")
		{
			newVehicle = new Boat(id, price, name, drive);
		}
	}

	if (newVehicle == nullptr)
	{
		cout << "Failed to buy vehicle: (" << id << ") " << type << " \"" << name << "\", price " << price << ", " << drive << " " << enginePower << "hp, at100 " << accelerationTo100 << endl;
	}
	else
	{
		this->balance -= price;
		this->vehicles[Vehicle::GetCount() - 1] = newVehicle;
		cout << "A new vehicle has been bought: (" << id << ") " << type << " \"" << name << "\", price " << price << endl;
	}
	return newVehicle;
}

bool VehicleDealership::SellVehicle(int id, int staffID)
{
	Staff* staff = SearchStaff(staffID);
	if (staff != nullptr)
	{
		for (int i = 0; i < Vehicle::GetCount(); i++)
		{
			if (this->vehicles[i] != nullptr && this->vehicles[i]->GetID() == id)
			{
				Vehicle* vehicle = this->vehicles[i];
				this->vehicles[i] = this->vehicles[Vehicle::GetCount() - 1];
				this->vehicles[Vehicle::GetCount() - 1] = nullptr;
				cout << "(" << vehicle->GetID() << ") " << vehicle->GetType() << " " << vehicle->GetName() << " was successfully sold for " << vehicle->GetPrice() << "$." << endl;
				this->balance += vehicle->GetPrice();
				this->sold += vehicle->GetPrice();
				staff->AddSellingPoints(vehicle->GetSellingPoints());
				delete vehicle;
				return true;
			}
		}
	}
	
	cout << "Failed to sell. Vehicle with ID (" << id << ") does not exist." << endl;
	return false;
}

Staff* VehicleDealership::AddStaff(int id, string fullName)
{
	Staff* newStaff = new Staff(id, fullName);
	this->staff[Staff::GetCount() - 1] = newStaff;
	cout << "Staff (" << newStaff->GetID() << ") " << newStaff->GetFullName() << " was successfully added." << endl;
	return newStaff;
}

Staff* VehicleDealership::AddStaff(int id, string fullName, double salary)
{
	Staff* newStaff = new Staff(id, fullName, salary);
	this->staff[Staff::GetCount() - 1] = newStaff;
	cout << "Staff (" << newStaff->GetID() << ") " << newStaff->GetFullName() << " with salary " << newStaff->GetSalary() << "$ was successfully added." << endl;
	return newStaff;
}

bool VehicleDealership::RemoveStaff(int id)
{
	for (int i = 0; i < Staff::GetCount(); i++)
	{
		if (this->staff[i] != nullptr && this->staff[i]->GetID() == id)
		{
			Staff* r_staff = this->staff[i];
			this->staff[i] = this->staff[Staff::GetCount() - 1];
			this->staff[Staff::GetCount() - 1] = nullptr;
			cout << "Staff (" << r_staff->GetID() << ") " << r_staff->GetFullName() << " was successfully removed." << endl;
			delete r_staff;
			return true;
		}
	}

	cout << "Failed to remove staff. Staff with ID (" << id << ") does not exist." << endl;
	return false;
}

Staff* VehicleDealership::SearchStaff(int id)
{
	for (int i = 0; i < Staff::GetCount(); i++)
	{
		if (this->staff[i] != nullptr && this->staff[i]->GetID() == id)
		{
			return this->staff[i];
		}
	}

	cout << "Failed to search staff. Staff with ID (" << id << ") does not exist." << endl;
	return nullptr;
}

void VehicleDealership::Payment()
{
	cout << "\t\tPayment report:" << endl;
	double totalSalary = 0;
	for (int i = 0; i < Staff::GetCount(); i++)
	{
		if (this->staff[i] != nullptr)
		{
			this->staff[i]->Payment();
			totalSalary += this->staff[i]->GetSalary();
		}
	}
	cout << "Sold this month amounted to: \t\t" << this->sold << "$" << endl;
	cout << "Total salary payment: \t\t\t" << totalSalary << "$" << endl;
	this->balance -= totalSalary;
	cout << "Net income: \t\t\t\t" << (this->balance - this->prevBalance) << "$" << endl;
	this->sold = 0;
	cout << "Total balance: \t\t\t\t" << this->balance << "$" << endl;
	this->prevBalance = this->balance;
}

void VehicleDealership::Info()
{
	cout << "Balance: " << this->balance << "$, vehicle count: " << Vehicle::GetCount() << ", staff count: " << Staff::GetCount() << endl;
}