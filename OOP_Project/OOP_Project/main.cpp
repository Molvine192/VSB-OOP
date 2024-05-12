#include <iostream>
#include <iomanip>
#include "VehicleDealership.h"

using namespace std;

int main()
{
	cout << fixed << setprecision(2);

	VehicleDealership* dealership = new VehicleDealership(10000000, 100, 10);

	dealership->AddStaff(1, "Akzhol Kudarov");
	dealership->AddStaff(2, "Dmytro Irzhytskyi", 2200);

	for (int i = 0; i < 5; i++)
	{
		cout << "Month " << (i + 1) << endl;
		dealership->BuyVehicle("Sedan", 1, 5000, "Some sedan", 150, 8.0, "fwd");
		dealership->BuyVehicle("SportCar", 2, 21000, "Some sport car", 450, 5.6, "rwd");
		dealership->BuyVehicle("SuperCar", 3, 500000, "Some super car", 1250, 2.5, "awd");
		dealership->BuyVehicle("Motorcycle", 4, 13250, "Some motorcycle", 325, 4.0, "NULL");
		dealership->BuyVehicle("Boat", 5, 200000, "Some boat", NULL, NULL, "sailing-motor");
		dealership->BuyVehicle("Helicopter", 6, 600000, "Some heli", 4550, NULL, "NULL");
		dealership->BuyVehicle("Sedan", 7, 7700, "Some sedan", 170, 7.2, "rwd");

		dealership->SellVehicle(1, 1);
		dealership->SellVehicle(2, 1);
		dealership->SellVehicle(3, 2);
		dealership->SellVehicle(4, 2);
		dealership->SellVehicle(5, 1);
		dealership->SellVehicle(6, 2);
		dealership->SellVehicle(7, 2);

		dealership->SearchStaff(1)->Info();
		dealership->SearchStaff(2)->Info();

		dealership->Payment();

		cout << endl;
	}

	dealership->RemoveStaff(1);

	dealership->Info();

	delete dealership;

	return 0;
}