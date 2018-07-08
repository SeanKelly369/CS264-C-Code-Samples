#include <iostream>
#include <cstring>

using namespace std;

class MyComplex{
    public:
    MyComplex(){
        real = 0;
        image = 0;
    }
    MyComplex(double A){
        real = A;
        image = 0;
    }
    MyComplex(double A, double B){
        real = A;
        image = B;
    }
    void copy(const MyComplex &m)
    {
        real = m.real;
        image = m.image;
    }
    friend const MyComplex operator+(double A, const MyComplex &m);
    friend const MyComplex operator+(const MyComplex&c, const MyComplex &m);
    friend const MyComplex operator+(const MyComplex &m, double A);
    
    double real, image;
};
const MyComplex operator+(double A, const MyComplex &m)
    {
        MyComplex complex;
        complex.real = A + m.real;
        complex.image = m.image;
        return complex;
    }
   const MyComplex operator+(const MyComplex &c, const MyComplex &m)
    {
        MyComplex complex;
        complex.real = c.real + m.real;
        complex.image = c.image + m.image;
        return complex;
    }
    const MyComplex operator+(const MyComplex& m, double A)
    {
        MyComplex complex;
        complex.real = A + m.real;
        complex.image = m.image;
        return complex;
    }


int main()
{
    MyComplex comp;
    MyComplex comp2(1);
    MyComplex comp3(1,2);
    comp.copy(comp2);
    cout << comp2.real << endl;
    
   MyComplex c1 = 5.0+comp;
   cout << c1.real << " " << c1.image << endl;
   
   MyComplex c2 = c1+c1;
   cout << c2.real << " " << c2.image << endl;
   
   MyComplex c3 = c2+5;
   cout << c3.real << " " << c3.image << endl;
}
