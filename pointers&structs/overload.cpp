// overloading operators example
/*
For example, cartesian vectors are sets of two coordinates: x and y. 
The addition operation of two cartesian vectors is defined as the addition of
both x coordinates together, and both y coordinates together. 
For example, adding the cartesian vectors (3,1) and (1,2) together would result in (3+1,1+2) = (4,3).
This could be implemented in C++ with the following code:
from www.cplusplus.com
*/
#include <iostream>
using namespace std;
class CVector {
  public:
    int x,y;
    CVector() {};
    CVector(int a,int b){ x = a; y = b;}
    CVector operator + (const CVector& p);  // overloaded operator function signature.
    // return_type <operator_key_word> <overloaded_operator> (function_parameter_list) {  }
    /*
    CVector --- return_type
    operator + ---- operator_key_word overloaded_operator
    (const CVector& p) ---- (function_parameter_list)
    */
};
// The overloaded operator function implementation
// const CVector& param means that param holds the address of the CVector object,
// which will not be altered in this function (hence the use of the key word const).
CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
  return temp;
}
int main () {
  CVector foo(3,1); // creating to CVector objects (foo and bar) from the stack.
  CVector bar(1,2);
  CVector result;    // create a CVector object (result) using the default construtor.
  result = foo + bar;
  // This could also be written as 
  // result = foo.operator+(bar);
  cout << result.x << ',' << result.y << '\n';
  return 0;
}
