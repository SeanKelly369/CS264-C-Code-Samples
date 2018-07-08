#include <iostream>
using namespace std;

//Base class
class Polygon
{
	protected:
		float width, height;
				
	public:		
		Polygon(float a, float b): width(a), height(b)
		{
			
		}
		
		//Memory is allocated for further use
		virtual float area(void)= 0;
		
		//print out result from derived classes
		void print_area()
		{
			cout << this -> area() << endl;
		}
};

//Derived class
class Rectangle: public Polygon
{
	public:
		Rectangle(float a, float b): Polygon(a,b)
		{
			//Poor practice, but added for explanation purposes
			cout << "This is a rectangle class" << endl;
		}
		
		float area()
		{
			return width * height;
		}

};

class Triangle: public Polygon
{
	public:
		Triangle(float a, float b): Polygon(a,b)
		{
			cout << "This is a triangle class" << endl;
		}
		
		float area()
		{
			return width * height/2;
		}
};

class Circle: public Polygon
{
	public:
		Circle(float a, float b): Polygon(a,b)
		{
			cout << "This is a circle class" << endl;
		}
		
		float area()
		{
			return 3.14 * (height / 2);
		}
};

int main(int argc, char** argv)
{
	//Declaration of objects on the heap
	Polygon *ppoly1 = new Rectangle(4,5);
	Polygon *ppoly2 = new Triangle(4,5);
	Polygon *ppoly3 = new Circle(0, 5);
	
	//Call print_area
	ppoly1 -> print_area();
	ppoly2 -> print_area();
	ppoly3 -> print_area();
	
	//De-allocate memory when no longer required
	delete ppoly1;
	delete ppoly2;
	delete ppoly3;
	
	return 0;
}
