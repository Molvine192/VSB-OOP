#include <iostream>
using namespace std;

// ukol 1
class Client
{
private:
	int code;
	string name;
public:
	Client(int c, string n);

	int GetCode();
	string GetName();
};

Client::Client(int c, string n)
{
	this->code = c;
	this->name = n;
}

int Client::GetCode()
{
	return this->code;
}

string Client::GetName()
{
	return this->name;
}

class Account
{
private:
	int number;
	double balance;
	double interestRate;

	Client* owner;
	Client* partner;

public:
	Account(int n, Client* c);
	Account(int n, Client* c, double ir);
	Account(int n, Client* c, Client* p);
	Account(int n, Client* c, Client* p, double ir);

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	Client* GetPartner();
	bool CanWithdraw(double a);

	void Deposit(double a);
	void Withdraw(double a);
	void AddInterest();
};

Account::Account(int n, Client* c)
{
	this->number = n;
	this->balance = 0;
	this->interestRate = 0.05;
	this->owner = c;
	this->partner = nullptr;
}

Account::Account(int n, Client* c, double ir)
{
	this->number = n;
	this->balance = 0;
	this->interestRate = ir;
	this->owner = c;
	this->partner = nullptr;
}

Account::Account(int n, Client* c, Client* p)
{
	this->number = n;
	this->balance = 0;
	this->interestRate = 0.05;
	this->owner = c;
	this->partner = p;
}

Account::Account(int n, Client* c, Client* p, double ir)
{
	this->number = n;
	this->balance = 0;
	this->interestRate = ir;
	this->owner = c;
	this->partner = p;
}

int Account::GetNumber()
{
	return this->number;
}

double Account::GetBalance()
{
	return this->balance;
}

double Account::GetInterestRate()
{
	return this->interestRate;
}

Client* Account::GetOwner()
{
	return this->owner;
}

Client* Account::GetPartner()
{
	return this->partner;
}

bool Account::CanWithdraw(double a)
{
	return this->balance >= a;
}

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

class Bank
{
private:
	Client** clients;
	int clientsCount;

	Account** accounts;
	int accountsCount;

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
	this->clientsCount = 0;
	this->accounts = new Account * [a];
	this->accountsCount = 0;
}

Bank::~Bank()
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		delete this->clients[i];
	}
	delete[] this->clients;

	for (int i = 0; i < this->accountsCount; i++)
	{
		delete this->accounts[i];
	}
	delete[] this->accounts;
}

Client* Bank::GetClient(int c)
{
	for (int i = 0; i < this->clientsCount; i++)
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
	for (int i = 0; i < this->accountsCount; i++)
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
	this->clients[this->clientsCount] = newClient;
	this->clientsCount++;
	return newClient;
}

Account* Bank::CreateAccount(int n, Client* c)
{
	Account* newAccount = new Account(n, c);
	this->accounts[this->accountsCount] = newAccount;
	this->accountsCount++;
	return newAccount;
}

Account* Bank::CreateAccount(int n, Client* c, double ir)
{
	Account* newAccount = new Account(n, c, ir);
	this->accounts[this->accountsCount] = newAccount;
	this->accountsCount++;
	return newAccount;
}

Account* Bank::CreateAccount(int n, Client* c, Client* p)
{
	Account* newAccount = new Account(n, c, p);
	this->accounts[this->accountsCount] = newAccount;
	this->accountsCount++;
	return newAccount;
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir)
{
	Account* newAccount = new Account(n, c, p, ir);
	this->accounts[this->accountsCount] = newAccount;
	this->accountsCount++;
	return newAccount;
}

void Bank::AddInterest()
{
	for (int i = 0; i < this->accountsCount; i++)
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

//ukol 2
class Grade
{
private:
	string subject;
	int value;

public:
	Grade(string subject, int value);

	string GetSubject();
	int GetValue();
	void SetValue(int newValue);
};

Grade::Grade(string subject, int value)
{
	this->subject = subject;
	this->value = value;
}

string Grade::GetSubject()
{
	return this->subject;
}

int Grade::GetValue()
{
	return this->value;
}

void Grade::SetValue(int newValue)
{
	this->value = newValue;
}


class Student
{
private:
	int code;
	string name;
	Grade** grades;
	int gradesCount;

public:
	Student(int code, string name, int gradeArraySize);
	~Student();

	void AddGrade(Grade* grade);

	string GetName();
	int GetCode();

	void PrintGrades();
};

Student::Student(int code, string name, int gradeArraySize) 
{
	this->code = code;
	this->name = name;
	this->gradesCount = 0;
	this->grades = new Grade * [gradeArraySize];
}

Student::~Student()
{
	delete[] this->grades;
}

void Student::AddGrade(Grade* grade) 
{
	this->grades[gradesCount++] = grade;
}

string Student::GetName()
{
	return this->name; 
}

int Student::GetCode() 
{
	return this->code; 
}

void Student::PrintGrades() 
{
	for (int i = 0; i < this->gradesCount; i++) 
	{
		cout << this->grades[i]->GetSubject() << ": " << this->grades[i]->GetValue() << endl;
	}
}


class SchoolDiary 
{
private:
	Student** students;
	int studentsCount;
	int studentsCapacity;

public:
	SchoolDiary(int studentsCapacity);

	~SchoolDiary();

	Student* CreateStudent(int code, string name, int gradeArraySize);

	Student* GetStudent(int code);

	void PrintAllGrades();
};

SchoolDiary::SchoolDiary(int studentsCapacity)
{
	this->studentsCount = 0;
	this->studentsCapacity = studentsCapacity;
	this->students = new Student * [studentsCapacity];
}

SchoolDiary::~SchoolDiary() 
{
	for (int i = 0; i < this->studentsCount; i++) {
		delete this->students[i];
	}
	delete[] this->students;
}

Student* SchoolDiary::CreateStudent(int code, string name, int gradeArraySize) 
{
	if (this->studentsCount < this->studentsCapacity)
	{
		Student* student = new Student(code, name, gradeArraySize);
		this->students[studentsCount++] = student;
		return student;
	}
	return nullptr;
}

Student* SchoolDiary::GetStudent(int code) 
{
	for (int i = 0; i < this->studentsCount; i++) 
	{
		if (this->students[i]->GetCode() == code) 
		{
			return this->students[i];
		}
	}
	return nullptr;
}

void SchoolDiary::PrintAllGrades() 
{
	for (int i = 0; i < this->studentsCount; i++) 
	{
		cout << "Student: " << this->students[i]->GetName() << endl;
		this->students[i]->PrintGrades();
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



	// ukol 2
	cout << "\n\n\nukol 2" << endl;
	SchoolDiary* diary = new SchoolDiary(10);

	Student* dmytro = diary->CreateStudent(1, "Dmytro", 5);
	dmytro->AddGrade(new Grade("Matika", 1));
	dmytro->AddGrade(new Grade("Programovani", 2));

	Student* victor = diary->CreateStudent(2, "Victor", 5);
	victor->AddGrade(new Grade("Programovani", 3));

	diary->PrintAllGrades();


	return 0;
}