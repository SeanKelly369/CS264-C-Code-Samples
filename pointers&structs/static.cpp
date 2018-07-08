
//malloc / realloc / free

// class
// class private by default 
// visibility of variables = public private or protected
// polymorphism 
// object 

//struct
// public by default 
// not object orianted but more for lists & variables
//struct = no virtual!!!
// operational 

// static stays loyal to the class 
// something non static makes a duplicate and is not loyal to the class 
// has issues with heritage

/*
Differences between a class and a struct in C++ are that structs have 
default public members and bases and classes have default private members 
and bases. Both classes and structs can have a mixture of public and 
private members, can use inheritance and can have member functions 
*/

/*
7.8] What's the difference between the keywords struct and class?
The members and base classes of a struct are public by default, while 
in class, they default to private. Note: you should make your base 
classes explicitly public, private, or protected, rather than relying 
on the defaults. Struct and class are otherwise functionally equivalent.
OK, enough of that squeaky clean techno talk. Emotionally, most developers 
make a strong distinction between a class and a struct. A struct simply feels 
like an open pile of bits with very little in the way of encapsulation or 
functionality. A class feels like a living and responsible member of society 
with intelligent services, a strong encapsulation barrier, and a well defined 
interface. Since that's the connotation most people already have, you should 
probably use the struct keyword if you have a class that has very few methods 
and has public data (such things do exist in well designed systems!), 
but otherwise you should probably use the class keyword.
*/

#include <iostream>
using namespace std;

class Voiture{
	public: 
		static const int swheel;
		int wheel;
		int getstaticwheel();
};

//declaired in car 
int Voiture::getstaticwheel(){
	return Voiture::swheel; 
}

static const int Voiture::swheel = 4; 

//invoque 
int main(){
	//cout << Voiture::swheel << endl; 
	Voiture a; 
	Voiture b; 
	a.wheel = 4;
	b.wheel = 2; 
	cout << a.wheel << " " << b.wheel << endl; 
	cout << a.getstaticwheel() << " " << b.getstaticwheel() << endl; 
	Voiture::swheel = 6; 
	cout << a.getstaticwheel() << " " << b.getstaticwheel() << endl; 
	return 0; 
}
