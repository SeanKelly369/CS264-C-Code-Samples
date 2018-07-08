#include <iostream>
#include <string>

using namespace std;

class Complex 
{	
	double real;	//real part of the complex number
	double imaginary; // imaginary part of the complex number
	
	public: 		
	Complex (double a, double b)
	{		
		real = a;
		imaginary = b;
	}
	
	Complex (double a)
	{
		real = a;
		imaginary = 0;		
	}
	
	// destructor
	~Complex()
	{
		cout << "Complex object is being destroyed" << endl;
	}
	
	// copy constructor
	Complex(const Complex &value)
	{
		real = value.real;
		imaginary = value.imaginary;
	}
	
	// overloading the + operator to add to complex numbers together and 
	// return a resulting complex number.
	Complex operator +(const Complex &num)
	{		
		Complex sumValue(0,0); // create a new Complex object that will store the other two added together.
		sumValue.real = real + num.real;
		sumValue.imaginary = imaginary + num.imaginary;
		
		return sumValue;		
	}
	
	Complex operator +(const double &num)
	{		
		Complex sumValue(0,0); // create a new Complex object that will store the other two added together.
		sumValue.real = real + num;
		sumValue.imaginary = imaginary;
		
		return sumValue;		
	}
	
	// "Friend" function for adding a double and a complex number
	friend Complex operator+(double num, const Complex &right);
	
	// getters and print methods.
	double getReal()
	{
		return real;
	}
	
	double getImaginary()
	{
		return imaginary;
	}
	
	void print()
	{
		cout << "Current object has x value: "<< real << " and imaginary value " << imaginary << endl;
	}
	
	
}; // end of Complex class definition

// Defining the friend function
Complex operator+(double num, const Complex &right)
{
    Complex temp(num + right.real, right.imaginary);
    return temp;
}


// In this main function we will create different version of the Complex object and we will 
// experiment with different types of constructors.
int main ()
{
	Complex number(4,7); // create a complex number
	number.print();		// print the complex number
	
	Complex value = number;
	
	value.print();
	
	Complex sum = number + value; // atempting to use the + operator to add to complex numbers.
	
	sum.print();
	
	cout << "**********************************************************************************" << endl;
	cout<< "*********** Now for Question 1 (parts b and c)CS264 January 2016 ******************" << endl;
	cout << "**********************************************************************************" << endl << endl;
	
	// Question 1 (parts b and c)
	Complex  C1(5.0, 4.5), C2(3.0,1.5);
	C1.print(); 
	C2.print();
	
	Complex C3 = C1 + C2;
	C3.print();
	
	Complex C4 = C1 + 4;
	C4.print();
	
	// Friday 1st December 2017 at 1.00 pm, The code below will not carry out the intended outcome. - Works now!
	Complex C5 = 5 + C1;
	C5.print();
	
	// An explanation on friend functions can be found in the rectangle file.
}
