#include <iostream>
#include <string>
using namespace std;
class Peel {
  int x;
  int y;
  string name;
public:
  Peel(int a, int b, string n) {
    x = a;
    y = b;
    name = n;
  }
  ~Peel() { cout << "Destroying the Peel class instance (object) " << endl; }
  int getX() { return x; } // inline class method.
  void setX(int a) { x = a; }
  string getName() { return name; } // inline class method
  void setName(string n) { name = n; }
  int getY();                 // method prototype
  void setY(int a) { y = a; } // inline class method
}; // end of the class, you wish!!
int Peel::getY() { return y; }
// No creating a method that will do something to the object passed to it.
void changeValues(Peel *temp) {
  temp->setY(22);
  temp->setX(66);
  temp->setName("Joseph");
  /*
  you could have also used
  *temp.setY(22);
  *temp.setX(66);
  *temp.setName("Joseph");
  */
}
int main() {
  Peel tot(7, 8, "Cutie Pie"); // create a Peel object and name it tot
  Peel *sot = new Peel(12, 0, "not so cute");
  cout << "Values in the object are " << tot.getX() << " and " << tot.getY()
       << " and name is " << tot.getName() << endl;
  changeValues(&tot);
  cout << "Values in the object are " << tot.getX() << " and " << tot.getY()
       << " and name is " << tot.getName() << endl;
  cout << "Values in the other object are " << (*sot).getX() << " and "
       << (*sot).getY() << " and name is " << (*sot).getName() << endl;
  delete sot; // deleting the sot object.
} // end of main method
