/*
Multiple inheritance

A class may inherit from more than one class by simply specifying more base classes,
separated by commas, in the list of a class's base classes (i.e., after the colon).
For example, if the program had a specific class to print on screen called Output,
and we wanted our classes Rectangle and Triangle to also inherit its members in
addition to those of Polygon we could write the following example below.

From www.cplusplus.com
 */

#include <iostream>
using namespace std;

// base or parent class #1
class Polygon {
  protected:
    int width, height;
  public:
    Polygon(int a, int b) : width(a), height(b) {}
};

// base or parent class #2
class Output {
  public:
    static void print (int i);
};

void Output::print (int i) {
  cout << i << '\n';
}

//  Rectangle Class (a child,subclass or derived Class), which inherits from Class Polygon
// and Class Output.
class Rectangle: public Polygon, public Output {
  public:
    Rectangle (int a, int b) : Polygon(a,b) {}
    int area ()
      { return width*height; }
};

// Triangle Class (a child,subclass or derived Class), which inherits from Class Polygon
// and Class Output.
class Triangle: public Polygon, public Output {
  public:
    Triangle (int a, int b) : Polygon(a,b) {}
    int area ()
      { return width*height/2; }
};

int main () {
  Rectangle rect (4,5); // create a Rectangle object on the stack
  Triangle trgl (4,5);  // create a Triangle object on the stack

  int area1 = rect.area();
  rect.print (area1);

  int area2 = trgl.area();
  Triangle::print (area2); // calling a static method by using the class scope and the method name.

  return 0;
}
