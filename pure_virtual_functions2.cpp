#include <iostream>  
using namespace std;  

class C
{ 
public:   
	C()
	{ cout << "C\n"; };

	virtual ~C() 
	{ cout << "~C\n"; };
};  

class D
{ 
public: 
	D()
	{ cout << "D\n"; }; 
		  
	virtual ~D() 
	{ cout << "~D\n"; }; 
};  

class A
{ 
	public: A()
	{ cout << "A\n"; }; 
	  
	virtual ~A() 
	{ cout << "~A\n"; };

	 protected:   
	 C c; 
}; 
  
class B: public A
{ 

public: B()
	{ cout << "B\n"; };

   virtual ~B()
   { cout << "~B\n"; };
   
    protected:
	D d; 
};  
	
int main()
{   
	B b; 
}  




