/*

Sample Question Solution:

CS264 January 2016 Question 1 (parts a, b and c)

Note: See question 1 CS264 Rectangle question for an explanation on the friend function.

*/
#include <iostream>
#include <string>

using namespace std;

class Complex {
	
	
	
	double x;	//real part of the complex number
	double yiota; // imaginary part of the complex number
	
	public: 	
	
	Complex (double a, double b){
		
		x = a;
		yiota = b;
	}
	
	Complex (double a){
		
		x = a;
		yiota = 0;
		
	}
	
	// destructor
	~Complex(){
		cout << "Complex object is being destroyed" << endl;
	}
	
	// copy constructor
	Complex(const Complex& value){
		x = value.x;
		yiota = value.yiota;
	}
	
	// overloading the + operator to add to complex numbers together and 
	// return a resulting complex number.
	Complex operator + (const Complex& num){
		
		Complex sumValue(0,0); // create a new Complex object that will store the other two added together.
		sumValue.x = x + num.x;
		sumValue.yiota = yiota + num.yiota;
		
		return sumValue;
		
	}
	
	Complex operator + (const double& num){
		
		Complex sumValue(0,0); // create a new Complex object that will store the other two added together.
		sumValue.x = x + num;
		sumValue.yiota = yiota;
		
		return sumValue;
		
	}
	
	// "Friend" function for adding a double and a complex number
	friend Complex operator+(double num, const Complex & right);
	
	// getters and print methods.
	double getx(){return x;}
	double getyiota(){return yiota;}
	void print(){cout << "Current object has x value: "<< x << " and imaginary value " << yiota << endl;}
	
	
}; // end of Complex class definition

// Defining the friend function
Complex operator+(double num, const Complex & right){
    Complex temp(num + right.x, right.yiota);
    return temp;
}


// In this main function we will create different version of the Complex object and we will 
// experiment with different types of constructors.
int main (){
	
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
	
	// All fine here!
	Complex C5 = 5 + C1;
	C5.print();
	
	// An explanation on friend functions can be found in the rectangle file,see Question 1 CS264 Autumn 2016
}