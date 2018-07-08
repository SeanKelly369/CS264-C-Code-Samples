#include <iostream>
using namespace std;

class A
{
public:
	A(string id) : id_(id)
	{
		cout << "A(ctor): " << id_ << endl;
	}
	
	virtual ~A()
	{
		cout << "A(dtor): " << id_ << endl;
	}
	
protected:
	string id_;			
};

class B
{
public:
	B(): a_("B")
	{
		cout << "B(ctor)" << endl;
	}
	
	virtual ~B()
	{
		cout << "B(dtor)" << endl;
	}
	
protected:
	A a_;	
};

class C: public B
{
public:
	C(): a_("C")
	{
		cout << "C(ctor)" << endl;
	}
	
	virtual ~C()
	{
		cout << "C(dtor)" << endl;
	}
	
protected:
	A a_;	
};


int main(int argc, char** argv)
{
	C myC;
}




