#include <iostream>
using namespace std;
int main(void) {
  int x = 5;
  int y = 7;
  int *apple = &x; // the reference variable apple, stores the address of the variable x.
  int *pear = &y; // the reference variable pear, stores the address fo the variable y.
  // Add code that uses the referene variable pear to put the value in y into x.
  // after this code executes, x will have the value 7 in it.
  // ***** code is not here yet for the problem above ******
  cout << "The value of x is " << x << endl;
  cout << "The value of x is " << *apple << endl;
  cout << "The value of the address of x is " << &x << endl;
  cout << "The value of the address of x is " << apple << endl;
  // Write code to do the following:
  // declare another int reference variable (int pointer) called rabbit
  // Set rabbit to store the address of x
  // Then change the value in x by using the rabbit variable (pointer).
  return 0;
}
