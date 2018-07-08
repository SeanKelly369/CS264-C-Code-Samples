/* Q1 (b) CS264 Autumn 2016 */

// By Joe and Rob

#include <iostream>

using namespace std;

class Rectangle{

	double len;
	double width;

	public:

	Rectangle(double l, double w){
		len = l;
		width = w;
	}

	Rectangle(double l){
		len = l;
		width = l;
	}

    // this is like a function operator+ that takes a single parameter (to the right of the function name).--
	Rectangle operator+(const Rectangle & right){

		// create an Rectangle object using the values of this current object implicitly, len and width
		// as well as the value in the passed by reference Rectangle, using right.len and right.width	
	
        double a = this->len + right.len;
		double b = this->width + right.width;

		// create the object locally and return it.
		Rectangle temp(a,b);
		return temp;

	}
	
	// Defining a "friend function". The "friend" keyword allows a function or another class (in our case it's 
	// a function) to read the private members of the object. It is NOT a method, like "print()" or even
	// "operator+(const Rectange & right)". Methods have an implicit "this pointer" which is 
	// unavailable in the friend function. Try it yourself and see!
	// If we had defined a normal function "operator+" then an error would occur when we try to 
	// access "right.len" and "right.width" respectively. Friend functions can be definied
	// inside the class and out. This time we definied it inside, but we have a commented out
	// version below too, for illustrative purposes.
	friend Rectangle operator+(double len, const Rectangle & right){
		Rectangle temp(len + right.len, right.width);
		return temp;
	}

    void print(){

		cout << "length is " << len << " and width is " << width << endl;
	}


}; // end of class Rectangle

// Friend function being definied outside the class, note how we
// now drop the "friend" keyword. "friend" is only needed at the 
// site of declaration and not definition.
/*
Rectangle operator+(double len, const Rectangle & right){
	Rectangle temp(len + right.len, right.width);
	return temp;
}
*/

int main(){

	// Create two Rectangle objects, using the first constructor.
	Rectangle  mine(5,4); 
	Rectangle  yours(7,9); 

	// print the current state (member values) of the two Rectangle objects.
    mine.print();
    yours.print();
	
	// We create another Rectangle which contains the values of the added "mine" and
	// "yours" rectangles.
    Rectangle temp1 = mine + yours;
	
	// print out the results of the two rectangles added together due to the + being overloaded in the Rectangle class.
    temp1.print(); 

    
    // We use the "friend" function defined above. Below is the explanation for needing a "friend" function.
    Rectangle temp2 = 5.0 + Rectangle(6.0, 3.0);
	
	// print out the results of the number 5.0 with another rectangle.
    temp2.print();
	
	/*
	* The reasoning is two fold. Firstly the "friend" modifier is needed because the function is NOT a method and
	* hence has no access to the class members like "len" or "width". "friend" allows functions to read or write to
	* the members variables EVEN if they are private.
	* Secondly - why a function? Well, if we have a method we know that methods only belong to classes/structs.
	* Primitives like double and int don't have methods, you can't write "5.add(1)", we write "5 + 1" instead.
	* If we want to add a Rectangle to a double we can write "temp + 5.0", assuming temp is a Rectangle and the METHOD 
	* "operator+" is defined (as it is above). In reality this is calling  "temp.operator+(5.0)" - which is disgusting 
	* but it's how the sausage gets made. So how do we write "5.0 + temp"? We know this would break down into "5.0.operator+(temp)" 
	* but doubles (and all primitives) don't have methods, therefore we need a function! The function is standalone and 
	* turns "5.0 + temp" into "operator+(5.0, temp)". This can be kind of jarring as it turns an "infix" 
	* expression (operator in the middle, and the operands on either side) into a "prefix" expression 
	* (function followed by the function arguments). 
	*/
	

}
