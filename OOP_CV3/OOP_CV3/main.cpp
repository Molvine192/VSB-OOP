#include <iostream>
#include <iomanip>
using namespace std;

// zadani 1
class KeyValue
{
private:
	int key;
	double value;

public:
	KeyValue(int k, double v);
	int GetKey();
	double GetValue();
};

KeyValue::KeyValue(int k, double v)
{
	this->key = k;
	this->value = v;
}

int KeyValue::GetKey()
{
	return this->key;
}

double KeyValue::GetValue()
{
	return this->value;
}

class KeyValues
{
private:
	KeyValue** keyValues;
	int count;

public:
	KeyValues(int n);
	~KeyValues();
	KeyValue* CreateObject(int k, double v);
	KeyValue* SearchObject(int k);
	KeyValue* RemoveObject(int k);
	int Count();
};

KeyValues::KeyValues(int n)
{
	this->keyValues = new KeyValue*[n];
	this->count = 0;
}

KeyValues::~KeyValues()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->keyValues[i];
	}

	delete[] this->keyValues;
}

int KeyValues::Count()
{
	return this->count;
}

KeyValue* KeyValues::CreateObject(int k, double v)
{
	KeyValue* newObject = new KeyValue(k, v);

	this->keyValues[this->count] = newObject;
	this->count += 1;

	return newObject;
}

KeyValue* KeyValues::SearchObject(int k)
{
	for (int i = 0; i < this->count; i++)
	{
		if (this->keyValues[i]->GetKey() == k)
		{
			return this->keyValues[i];
		}
	}

	return nullptr;
}

KeyValue* KeyValues::RemoveObject(int k)
{
	for (int i = 0; i < this->count; i++)
	{
		if (this->keyValues[i]->GetKey() == k)
		{
			KeyValue* object = keyValues[i];
			this->keyValues[i] = this->keyValues[this->count - 1];
			this->keyValues[this->count - 1] = nullptr;
			this->count -= 1;
			return object;
		}
	}

	return nullptr;
}

// zadani 2
class Osoba
{
private:
	string name;
	string adress;

public:
	Osoba(string name, string adress);
	string GetName();
	string GetAdress();
};

Osoba::Osoba(string n, string a)
{
	this->name = n;
	this->adress = a;
}

string Osoba::GetName()
{
	return this->name;
}

string Osoba::GetAdress()
{
	return this->adress;
}

class PolozkaFaktury
{
private:
	string name;
	double price;

public:
	PolozkaFaktury(string n, double p);
	string GetName();
	double GetPrice();
};

PolozkaFaktury::PolozkaFaktury(string n, double p)
{
	this->name = n;
	this->price = p;
}

string PolozkaFaktury::GetName()
{
	return this->name;
}

double PolozkaFaktury::GetPrice()
{
	return this->price;
}

class Faktura
{
private:
	int number;
	Osoba* osoba;
	PolozkaFaktury** polozkyFaktury;
	int count;

public:
	Faktura(int n, Osoba* o, int N);
	~Faktura();
	PolozkaFaktury* CreateObject(string n, double p);
	PolozkaFaktury* SearchObject(int k);
	int GetNumber();
	Osoba* GetOsoba();
	double FullPrice();
	int Count();
};

Faktura::Faktura(int n, Osoba* o, int N)
{
	this->number = n;
	this->osoba = o;
	this->polozkyFaktury = new PolozkaFaktury * [N];
	this->count = 0;
}

Faktura::~Faktura()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->polozkyFaktury[i];
	}

	delete[] this->polozkyFaktury;
}

PolozkaFaktury* Faktura::CreateObject(string n, double p)
{
	PolozkaFaktury* newObject = new PolozkaFaktury(n, p);

	this->polozkyFaktury[this->count] = newObject;
	this->count += 1;

	return newObject;
}

PolozkaFaktury* Faktura::SearchObject(int k)
{
	return this->polozkyFaktury[k];
}

int Faktura::GetNumber()
{
	return this->number;
}

Osoba* Faktura::GetOsoba()
{
	return this->osoba;
}

double Faktura::FullPrice()
{
	double fullPrice = 0;
	for (int i = 0; i < this->count; i++)
	{
		fullPrice += this->polozkyFaktury[i]->GetPrice();
	}
	return fullPrice;
}

int Faktura::Count()
{
	return this->count;
}

int main()
{
	int N = 5;

	// zadani 1
	cout << "\tZadani 1" << endl;
	KeyValues* myKeyValues = new KeyValues(N);

	for (int i = 0; i < N; i++)
	{
		myKeyValues->CreateObject(i, i + 0.5);
	}

	cout << "Count before: " << myKeyValues->Count() << endl;
	cout << myKeyValues->RemoveObject(2)->GetKey() << endl;
	cout << "Count after: " << myKeyValues->Count() << endl;

	delete myKeyValues;
	
	// zadani 2
	cout << endl << "\tZadani 2" << endl;
	Osoba* osoba = new Osoba("Dmytro", "Adressova 12");
	Faktura* faktura = new Faktura(1, osoba, N);
	for (int i = 0; i < N; i++)
	{
		faktura->CreateObject("Neco", 135.50 * (i + 1));
	}
	
	for (int i = 0; i < N; i++)
	{
		PolozkaFaktury* polozkaFaktury = faktura->SearchObject(i);
		cout << polozkaFaktury->GetName() << " " << (i + 1) << ": \t" << fixed << setprecision(2) << polozkaFaktury->GetPrice() << " kc" << endl;
	}
	cout << "Full price: \t" << faktura->FullPrice() << " kc" << endl;

	delete faktura;

	return 0;
}