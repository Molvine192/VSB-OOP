#include <iostream>
using namespace std;

class Auto
{
private:
	int id;
	string brand;
	string drive;
	float enginePower;
	float velocity;
	bool overrideLightsState;
	//dalsi polozky

public:
	Auto(int id, string b, string d, float ep, float v, bool ols) : id(id), brand(b), drive(d), enginePower(ep), velocity(v), overrideLightsState(ols) {}

	int GetID() { return id; }
	string GetBrand() { return brand; }
	string GetDrive() { return drive; }
	float GetEnginePower() { return enginePower; }
	float GetVelocity() { return velocity; }
	bool GetOverrideLightsState() { return overrideLightsState; }
};

class Cabriolet : public Auto
{
private:
	bool isRoofOpen;
public:
	Cabriolet(int id, string b, string d, float ep, float v, bool ols, bool iro) : Auto(id, b, d, ep, v, ols), isRoofOpen(iro) {}

	bool IsRoofOpen() { return isRoofOpen; }
};

class Truck : public Auto
{
private:
	bool isTrailerAttached;
	string cargoType;
	float cargoWeight;
public:
	Truck(int id, string b, string d, float ep, float v, bool ols, bool ita, string ct, float cw) : Auto(id, b, d, ep, v, ols), isTrailerAttached(ita), cargoType(ct), cargoWeight(cw) {}
	
	bool IsTrailerAttached() { return isTrailerAttached; }
	string GetCargoType() { return cargoType; }
	float GetCargoWeight() { return cargoWeight; }
};

int main()
{
	Auto* skoda = new Auto(0, "Skoda", "awd", 265, 2.0, false);
	Cabriolet* porsche = new Cabriolet(1, "Porsche", "rwd", 611, 5.7, true, true);
	Truck* volvo = new Truck(2, "Volvo", "awd", 780, 17.3, true, true, "Clothes", 12000);

	cout << skoda->GetBrand() << "\t - " << skoda->GetDrive() << "\t - " << skoda->GetEnginePower() << "hp\t - " << skoda->GetEnginePower() << endl;
	cout << porsche->GetBrand() << "\t - " << porsche->GetDrive() << "\t - " << porsche->GetEnginePower() << "hp\t - " << porsche->GetEnginePower() << "\t - is roof open: " << porsche->IsRoofOpen() << endl;
	cout << volvo->GetBrand() << "\t - " << volvo->GetDrive() << "\t - " << volvo->GetEnginePower() << "hp\t - " << volvo->GetEnginePower() << "\t - is trailer attached: " << volvo->IsTrailerAttached() << "\t - cargo type: " << volvo->GetCargoType() << "\t - cargo weight: "<< volvo->GetCargoWeight() << endl;
	return 0;
}