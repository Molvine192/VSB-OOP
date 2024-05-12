#include <iostream>
using namespace std;

class DefaultInterestRate
{
private:
	static double defaultInterestRate;
public:
	static double GetDefaultInterestRate() { return defaultInterestRate; }
};

double DefaultInterestRate::defaultInterestRate = 0.05;

class Client
{
private:
	static int clientsCount;

	int code;
	string name; 

public:
	static int GetClientsCount() { return clientsCount; }

	Client(int c, string n) : code(c), name(n) { clientsCount++; };
	~Client() { clientsCount--; }; 

	int GetCode() { return code; };
	string GetName() { return name; };
};

int Client::clientsCount = 0;

class Account
{
private:
	static int accountsCount;

	int number;
	double balance;
	double interestRate;

	Client* owner;
	Client* partner;

public:
	static int GetAccountsCount() { return accountsCount; }

	Account(int n, Client* c) : number(n), owner(c), partner(nullptr), balance(0), interestRate(DefaultInterestRate::GetDefaultInterestRate()) { accountsCount++; }
	Account(int n, Client* c, double ir) : number(n), owner(c), partner(nullptr), balance(0), interestRate(ir) { accountsCount++; }
	Account(int n, Client* c, Client* p) : number(n), owner(c), partner(p), balance(0), interestRate(DefaultInterestRate::GetDefaultInterestRate()) { accountsCount++; }
	Account(int n, Client* c, Client* p, double ir) : number(n), owner(c), partner(p), balance(0), interestRate(ir) { accountsCount++; }
	~Account() { accountsCount--; }

	int GetNumber() { return number; }
	double GetBalance() { return balance; }
	double GetInterestRate() { return interestRate; }
	Client* GetOwner() { return owner; }
	Client* GetPartner() { return partner; }
	bool CanWithdraw(double a) { return this->balance >= a; }

	void Deposit(double a);
	void Withdraw(double a);
	void AddInterest();
};

void Account::Deposit(double a)
{
	this->balance += a;
}

void Account::Withdraw(double a)
{
	if (this->CanWithdraw(a))
	{
		this->balance -= a;
	}
}

void Account::AddInterest()
{
	this->balance += this->balance * this->interestRate;
}

int Account::accountsCount = 0;

class Bank
{
private:
	Client** clients;
	Account** accounts;

public:
	Bank(int c, int a);
	~Bank();

	Client* GetClient(int c);
	Account* GetAccount(int n);

	Client* CreateClient(int c, string n);
	Account* CreateAccount(int n, Client* c);
	Account* CreateAccount(int n, Client* c, double ir);
	Account* CreateAccount(int n, Client* c, Client* p);
	Account* CreateAccount(int n, Client* c, Client* p, double ir);

	void AddInterest();

	void PrintBankAccounts();
};

Bank::Bank(int c, int a)
{
	this->clients = new Client * [c];
	this->accounts = new Account * [a];
}

Bank::~Bank()
{
	for (int i = 0; i < Client::GetClientsCount(); i++)
	{
		delete this->clients[i];
	}
	delete[] this->clients;

	for (int i = 0; i < Account::GetAccountsCount(); i++)
	{
		delete this->accounts[i];
	}
	delete[] this->accounts;
}

Client* Bank::GetClient(int c)
{
	for (int i = 0; i < Client::GetClientsCount(); i++)
	{
		if (clients[i]->GetCode() == c)
		{
			return clients[i];
		}
	}
	return nullptr;
}

Account* Bank::GetAccount(int n)
{
	for (int i = 0; i < Account::GetAccountsCount(); i++)
	{
		if (accounts[i]->GetNumber() == n)
		{
			return accounts[i];
		}
	}
	return nullptr;
}

Client* Bank::CreateClient(int c, string n)
{
	Client* newClient = new Client(c, n);
	this->clients[Client::GetClientsCount()-1] = newClient;
	return newClient;
}

Account* Bank::CreateAccount(int n, Client* c)
{
	Account* newAccount = new Account(n, c);
	this->accounts[Account::GetAccountsCount()-1] = newAccount;
	return newAccount;
}

Account* Bank::CreateAccount(int n, Client* c, double ir)
{
	Account* newAccount = new Account(n, c, ir);
	this->accounts[Account::GetAccountsCount()-1] = newAccount;
	return newAccount;
}

Account* Bank::CreateAccount(int n, Client* c, Client* p)
{
	Account* newAccount = new Account(n, c, p);
	this->accounts[Account::GetAccountsCount()-1] = newAccount;
	return newAccount;
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir)
{
	Account* newAccount = new Account(n, c, p, ir);
	this->accounts[Account::GetAccountsCount()-1] = newAccount;
	return newAccount;
}

void Bank::AddInterest()
{
	for (int i = 0; i < Account::GetAccountsCount(); i++)
	{
		this->accounts[i]->AddInterest();
	}
}

void Bank::PrintBankAccounts()
{
	int i = 1;
	Account* account = this->GetAccount(i);
	while (account != nullptr)
	{
		cout << account->GetOwner()->GetName() << ", balance: " << account->GetBalance() << ", interest rate: " << account->GetInterestRate() << endl;
		i++;
		account = this->GetAccount(i);
	}
}

int main()
{
	// ukol 1
	cout << "ukol 1" << endl;
	Bank* bank = new Bank(10, 100);
	for (int i = 0; i < 5; i++)
	{
		Client* newClient = bank->CreateClient(i + 1, "Default client");
		Account* newAccount = bank->CreateAccount(i + 1, newClient);
		newAccount->Deposit((i + 1) * 1000);
	}
	Client* irClient = bank->CreateClient(6, "Better IR client");
	Account* irAccount = bank->CreateAccount(6, irClient, 0.12);
	irAccount->Deposit(25000);

	bank->PrintBankAccounts();

	cout << "\n\nAdd interest event.\n\n\n";
	bank->AddInterest();

	bank->PrintBankAccounts();

	Client* client = bank->CreateClient(7, "Client with partner");
	Client* partner = bank->CreateClient(8, "Partner");
	Account* accountWithPartner = bank->CreateAccount(7, client, partner);
	cout << "\n\nAccount with partner:" << endl;
	cout << client->GetName() << ", balance: " << accountWithPartner->GetBalance() << ", interest rate: " << accountWithPartner->GetInterestRate() << ", partner: " << partner->GetName() << endl;

	cout << "\n\nSome transactions.\n\n\n";
	bank->GetAccount(1)->Deposit(1642);
	bank->GetAccount(4)->Deposit(292);
	if (bank->GetAccount(2)->CanWithdraw(87))
		bank->GetAccount(2)->Withdraw(87);
	bank->GetAccount(6)->Deposit(56800);
	if (bank->GetAccount(2)->CanWithdraw(100000000))
		bank->GetAccount(2)->Withdraw(100000000);
	bank->GetAccount(3)->Deposit(100000);

	bank->PrintBankAccounts();

	cout << "\n\nAdd interest event.\n\n\n";
	bank->AddInterest();

	bank->PrintBankAccounts();

	return 0;
}