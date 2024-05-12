#include <iostream>
using namespace std;

// 1 zadani
class KeyValue
{
private:
	int key;
	double value;
	KeyValue* next;

public:
	KeyValue(int k, double v);
	~KeyValue();
	int GetKey();
	double GetValue();
	KeyValue* GetNext();
	KeyValue* CreateNext(int k, double v);
};

KeyValue::KeyValue(int k, double v)
{
	this->key = k;
	this->value = v;
	this->next = nullptr;
}

KeyValue::~KeyValue()
{
	if (this->next != nullptr)
	{
		delete this->next;
		this->next = nullptr;
	}
}

KeyValue* KeyValue::GetNext()
{
	return this->next;
}

KeyValue* KeyValue::CreateNext(int k, double v)
{
	this->next = new KeyValue(k, v);
	return this->next;
}

int KeyValue::GetKey()
{
	return this->key;
}

double KeyValue::GetValue()
{
	return this->value;
}

// 2 zadani
class BinaryTree
{
private:
	string key;
	string value;
	BinaryTree* left;
	BinaryTree* right;
public:
	BinaryTree(string k, string v);
	string GetKey();
	string GetValue();
	BinaryTree* CreateLeft(string k, string v);
	BinaryTree* CreateRight(string k, string v);
};

BinaryTree::BinaryTree(string k, string v)
{
	this->key = k;
	this->value = v;
	this->left = nullptr;
	this->right = nullptr;
}

BinaryTree* BinaryTree::CreateLeft(string k, string v)
{
	this->left = new BinaryTree(k, v);
	return this->left;
}

BinaryTree* BinaryTree::CreateRight(string k, string v)
{
	this->right = new BinaryTree(k, v);
	return this->right;
}

string BinaryTree::GetKey()
{
	return this->key;
}

string BinaryTree::GetValue()
{
	return this->value;
}

// 3 zadani
class DecisionTree
{
private:
	int key;
	string value;
	DecisionTree* left;
	DecisionTree* right;
public:
	DecisionTree(int k, string v);
	int GetKey();
	string GetValue();
	DecisionTree* CreateLeft(int k, string v);
	DecisionTree* CreateRight(int k, string v);
};

DecisionTree::DecisionTree(int k, string v)
{
	this->key = k;
	this->value = v;
	this->left = nullptr;
	this->right = nullptr;
}

DecisionTree* DecisionTree::CreateLeft(int k, string v)
{
	this->left = new DecisionTree(k, v);
	return this->left;
}

DecisionTree* DecisionTree::CreateRight(int k, string v)
{
	this->right = new DecisionTree(k, v);
	return this->right;
}

int DecisionTree::GetKey()
{
	return this->key;
}

string DecisionTree::GetValue()
{
	return this->value;
}

int main()
{
	// 1 zadani
	KeyValue* current = new KeyValue(1, 2);
	cout << "Key: " << current->GetKey() << " | Value: " << current->GetValue() << endl;

	int count = 20;
	for (int i = 2; i <= count; i++)
	{
		current = current->CreateNext(i, i * 2);
		cout << "Key: " << current->GetKey() << " | Value: " << current->GetValue() << endl;
	}

	// 2 zadani
	cout << endl;
	BinaryTree* node = new BinaryTree("1", "root");
	BinaryTree* left = node->CreateLeft("2", "left child");
	BinaryTree* right = node->CreateRight("3", "right child");
	BinaryTree* leftChildLeft = left->CreateLeft("4", "left child left");
	BinaryTree* leftChildRight = left->CreateRight("5", "left child right");
	cout << "Key: " << node->GetKey() << " | Value: " << node->GetValue() << endl;
	cout << "Key: " << left->GetKey() << " | Value: " << left->GetValue() << endl;
	cout << "Key: " << right->GetKey() << " | Value: " << right->GetValue() << endl;
	cout << "Key: " << leftChildLeft->GetKey() << " | Value: " << leftChildLeft->GetValue() << endl;
	cout << "Key: " << leftChildRight->GetKey() << " | Value: " << leftChildRight->GetValue() << endl;

	// 3 zadani
	cout << endl;
	DecisionTree* animal = new DecisionTree(1, "Animal?");
	DecisionTree* flies = animal->CreateLeft(2, "Flies?");
	DecisionTree* flower = animal->CreateRight(3, "Flower?");
	DecisionTree* bird = flies->CreateLeft(4, "Bird?");
	DecisionTree* feline = flies->CreateRight(5, "Feline?");
	DecisionTree* rose = flower->CreateLeft(6, "Rose?");
	DecisionTree* cactus = flower->CreateRight(7, "Cactus?");
	DecisionTree* eagle = bird->CreateLeft(8, "Eagle?");
	DecisionTree* bat = bird->CreateRight(9, "Bat?");
	DecisionTree* lion = feline->CreateLeft(10, "Lion?");
	DecisionTree* dog = feline->CreateRight(11, "Dog?");
	cout << "\t\t\t\t\t   |" << endl;
	cout << "\t\t\t\t\t" << animal->GetValue() << endl;
	cout << "\t\t  |\t\t\t\t\t\t   |" << endl;
	cout << "\t\t" << flies->GetValue() << "\t\t\t\t\t\t" << flower->GetValue() << endl;
	cout << "\t  |\t\t   |\t\t\t\t  |\t\t   |" << endl;
	cout << "\t" << bird->GetValue() << "\t\t" << feline->GetValue() << "\t\t\t\t" << rose->GetValue() << "\t\t" << cactus->GetValue() << endl;
	cout << "      |      |\t       |      |" << endl;
	cout << "    " << eagle->GetValue() << "  " << bat->GetValue() << "     " << lion->GetValue() << "   " << dog->GetValue() << endl;

	return 0;
}