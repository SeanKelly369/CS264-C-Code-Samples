#include <iostream>
using namespace std;
class Something{
public:
	Something() 
	{ cout << "Something constructed\n"; }
	
	virtual ~Something() 
	{ cout << "Something destructor\n"; }
};

class Parent{
public:
	Parent() 
	{ cout << "Parent constructor\n"; }
	
	virtual ~Parent() 
	{ cout << "Parent destructor\n"; }
};

class Child : public Parent{
public:
	Child()
	 { cout << "Child A construct\n"; }	 
	Child(const Child &P) 
	{ cout << "Child reference construct\n"; }
	
	Child & operator=(const Child & rhs) 
	{ cout << "Child operator = constructor\n"; }
	
	virtual ~Child() 
	{ cout << "Child destructor\n"; }
protected:
	Something S_;
};

int main(int argc, char** argv){
	Child ChildA;
	Child ChildB = ChildA;
	ChildA = ChildB;
}




