#include <iostream>
using namespace std;

class User
{
    private:
        string username;
        string password;
    public:
        User(string username, string password);
        string getUsername();
        string getPassword();
};

User::User(string username, string password)
{
    this->username = username;
    this->password = password;
}

string User::getUsername()
{
    return this->username;
}

string User::getPassword()
{
    return this->password;
}

class Email
{
    private:
        string email;
        string owner;
    public:
        Email(string email, string owner);
        string getEmail();
        string getOwner();
};

Email::Email(string email, string owner)
{
    this->email = email;
    this->owner = owner;
}

string Email::getEmail()
{
    return this->email;
}

string Email::getOwner()
{
    return this->owner;
}

class Document
{
    private:
        string name;
        int size;
    public:
        Document(string name, int size);
        string getName();
        int getSize();
};

Document::Document(string name, int size)
{
    this->name = name;
    this->size = size;
}

string Document::getName()
{
    return this->name;
}

int Document::getSize()
{
    return this->size;
}

int main()
{
    User user = User("pasha", "bog14");
    Email email = Email("pasha.android@gmail.com", "zadohlik");
    cout << user.getUsername() << endl;
    cout << email.getEmail() << endl;
    Document* document = new Document("doc_name", 2048);
    cout << document->getName() << endl;
    delete document;
}