/*
The C++ code below defines a Matrix class for storing a 2D
matrix of numbers for use in a linear algebra library. The class
provides a constructor that takes the number of rows and
columns of the matrix as input, and initialises a matrix of zeros of
that size. The matrix data is stored row-by-row in a 1D linear
block of memory whose address is stored in the data member
variable. For example the matrix:
[
1 2
3 4
]
would be stored as:
class Matrix
{
public:
	Matrix(int row, int col):
	r_(row),c_(col),data(new int[r_*c_])
	{
		// initialise the matrix elements to zero
		memset(data, 0, r*c*sizeof(int));
	};
	virtual ~Matrix()
	{
	 	delete[] data; 
	};
	 
virtual void set(int row, int col, int value;
void print();
 
protected:
	int r_, c_; // number of rows and columns
	int *data; // pointer to matrix data
 
};

Complete the above class by providing definitions for the set and
print methods. The set method should take as input a row
and column index and a value which it should store at that
location in the matrix. The print method should print out the
content*/

#include <iostream>
#include <string.h>

using namespace std;

class Matrix {
public:

    Matrix(int row, int col) : r(row), c(col), data(new int[r*c]) 
	{
        memset(data, 0, r * c * sizeof (int));
    };

    virtual ~Matrix() {
        delete[] data;
    };
    
    virtual void set(int row, int col, int value);
            void print();
            
        protected:
            int r, c; // number of rows and columns
            int *data; // pointer to matrix data
};
//---------------Question (c)--------------------//
class SymMatrix:public Matrix
{
public:
    SymMatrix(int r):Matrix(r,r)
	{
	}
};

//----------------Question (b)-------------------//
void Matrix::set(int row, int col, int value)
{
    int index = (c*row) + col;
    data[index] = value;
}

void Matrix::print()
{
    for(int i = 0; i < (r*c); i++)
    {
        cout << data[i] << " ";
        if( (i + 1) % c == 0)
		{
            cout << endl;
        }
    }
}
//---------------------------------------------//

int main()
{
    Matrix m(5,3);
    m.set(3,2,5);
    m.print();
	
	SymMatrix sym(3);
    sym.set(2,2,1);
    sym.set(0,0,3);
    sym.print();
	
}
