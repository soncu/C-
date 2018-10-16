#include <iostream>
#include <cassert>
using namespace std;


class Parent
{
public:
	Parent();
	virtual ~Parent();
	virtual void SetData(int);
	virtual int GetData();
protected:
	int data;
};

Parent::Parent()
	: data(-1)
{
	cout << "Parent Ctor" << endl;
}

Parent::~Parent()
{
	cout << "Parent Dtor" << endl;
	this->data = -1;
}

void Parent::SetData(int d)
{
	cout << "Parent Setdata" << endl;
	this->data = d * 1;
}

int Parent::GetData(void)
{
	cout << "Parent GetData" << endl;
	return this->data;
}

//------------------------------------------

class Child : public Parent
{
public:
	Child();
	virtual ~Child();
	virtual void SetData(int);
	virtual int GetData();
};

Child::Child()
{
	cout << "Child Ctor" << endl;
}

Child::~Child()
{
	cout << "Child Dtor" << endl;
}

void Child::SetData(int d)
{
	cout << "Child Setdata" << endl;
	this->data = d * 2;
}

int Child::GetData(void)
{
	cout << "Child Setdata" << endl;
	return this->data;
}

//------------------------------------------

class GrandC : public Child
{
public:
	GrandC();
	virtual ~GrandC();
	virtual void SetData(int);
	virtual int GetData();
};

GrandC::GrandC()
{
	cout << "GrandC Ctor" << endl;
}

GrandC::~GrandC()
{
	cout << "GrandC Dtor" << endl;
}

void GrandC::SetData(int d)
{
	cout << "GrandC Setdata" << endl;
	this->data = d * 3;
}

int GrandC::GetData(void)
{
	cout << "GrandC GetData" << endl;
	return this->data;
}

//***********************************************

void PlayWithPtr(Parent* ptr)
{
	assert(ptr != NULL);
	
	cout << "-------------------- PLAYING WITH PTR ---------------------" << endl;
	cout << "ptr->GetData():" << ptr->GetData() << endl;
	cout << "ptr->SetData(20)" << endl;
	ptr->SetData(20);
	cout << "ptr->GetData():" << ptr->GetData() << endl;
}

int main() {
	
	cout << "Main Begins:" << endl;
	
	cout << "--------------------------------" << endl;
	
	Parent p;
	cout << "p.GetData():" << p.GetData() << endl;
	cout << "p.SetData(3):" << endl;
	p.SetData(3);
	cout << "p.GetData():" << p.GetData() << endl;
	
	cout << "--------------------------------" << endl;
	
	Child c;
	cout << "c.GetData():" << c.GetData() << endl;
	cout << "c.SetData(5):" << endl;
	c.SetData(5);
	cout << "c.GetData():" << c.GetData() << endl;
	
	cout << "--------------------------------" << endl;
	
	GrandC g;
	cout << "g.GetData():" << g.GetData() << endl;
	cout << "g.SetData(7):" << endl;
	g.SetData(7);
	cout << "g.GetData():" << g.GetData() << endl;
	
	cout << "--------------------------------" << endl;
	
	{
		cout << "+++++++++++++++++++++++++++++++++" << endl;
		
		Parent* ptr;
	
		//ptr = new Parent();
		//ptr = new Child();
		ptr = new GrandC();
		PlayWithPtr(ptr);
		delete ptr;
		
		cout << "+++++++++++++++++++++++++++++++++" << endl;
	}
	
	
	return 0;
}
