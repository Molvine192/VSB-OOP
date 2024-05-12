#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

class Client
{
private:
	int code;
	string name;

public:
	Client(int c, string n) : code(c), name(n) {};
	~Client() {};

	int GetCode() { return code; };
	string GetName() { return name; };
};

class Account
{
private:
	int number;
	double interestRate;

	Client* owner;

protected:
	double balance;

public:
	Account(int n, Client* o) : number(n), owner(o), balance(0), interestRate(0.05) {};
	Account(int n, Client* o, double ir) : number(n), owner(o), balance(0), interestRate(ir) {};

	int GetNumber() { return number; }
	double GetBalance() { return balance; }
	double GetInterestRate() { return interestRate; }
	Client* GetOwner() { return owner; }
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();
};

bool Account::CanWithdraw(double a)
{
	return this->balance >= a;
}

void Account::Deposit(double a)
{
	this->balance += a;
}

bool Account::Withdraw(double a)
{
	if (this->CanWithdraw(a))
	{
		this->balance -= a;
		return true;
	}
	return false;
}

void Account::AddInterest()
{
	this->balance += this->balance * this->interestRate;
}

class CreditAccount : public Account
{
private:
	double credit;

public:
	CreditAccount(int n, Client* o, double c) : Account(n, o), credit(c) {};
	CreditAccount(int n, Client* o, double ir, double c) : Account(n, o, ir), credit(c) {};

	bool CanWithdraw(double a);
	bool Withdraw(double a);
};

bool CreditAccount::Withdraw(double a)
{
	if (this->CanWithdraw(a))
	{
		this->balance -= a;
		return true;
	}
	return false;
}

bool CreditAccount::CanWithdraw(double a)
{
	return (this->GetBalance() + this->credit >= a);
}

/////////////////////////////////////////////////////
class Utvar
{
public:
	double Obsah();
	double Obvod();
};

double Utvar::Obsah() { return 0; }
double Utvar::Obvod() { return 0; }

class Kruh
{
private:
	double polomer;

public:
	Kruh(double p) : polomer(p) {};
	double Obsah();
	double Obvod();
};

double Kruh::Obsah()
{
	return (M_PI * this->polomer * this->polomer);
}

double Kruh::Obvod()
{
	return (2 * M_PI * this->polomer);
}

class Ctverec
{
private:
	double strana;

public:
	Ctverec(double s) : strana(s) {};

	double Obsah();
	double Obvod();
};

double Ctverec::Obsah()
{
	return (this->strana * this->strana);
}

double Ctverec::Obvod()
{
	return (this->strana * 4);
}

int main()
{
	Utvar* utvar = new Utvar();
	cout << "Utvar: obsah " << utvar->Obsah() << ", obvod:" << utvar->Obvod() << endl;

	Kruh* kruh = new Kruh(5);
	cout << "Kruh: obsah " << kruh->Obsah() << ", obvod:" << kruh->Obvod() << endl;
	
	Ctverec* ctverec = new Ctverec(5);
	cout << "Ctverec: obsah " << ctverec->Obsah() << ", obvod:" << ctverec->Obvod() << endl;

	return 0;
}