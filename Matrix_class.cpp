/*The organization of the class for a 4 x 5 matrix instance is shown
below. Here, data_ is a pointer to a one dimensional array of
pointers to integer arrays. The matrix data itself is stored in the
“vertical” arrays, where each array corresponds to a matrix
column.
(a) Provide a definition of the parameterized constructor and the
destructor of the Matrix class. What is the effect of the virtual
keyword, and why is it important to make sure that destructors
are virtual?
[8 marks]
CS264 Page 3 of 5 Autumn 2017
(b) An Upper Triangular Matrix is a square matrix where all of the
elements below the diagonal are zero. Below are some
examples of upper triangular matrices:
[
1 3
0 2
] [
3 2 4
0 -1 3
0 0 2
]
Provide a definition of an upper triangular matrix class called,
UTMatrix, which is derived from the Matrix class. The class
should have the following organization i.e. only the element on
and above the diagonal should be represented.
In the UTMatrix class, attempting to set an element below the
diagonal should result in a call to exit (as in line 10 of the original
Matrix definition). Calling get on an element below the diagonal
should return 0.
Provide a complete definition for the UTMatrix class. In your
answer you should decide which methods of class Matrix are
required to be over-ridden in order to provide the functionality as
described above. */

#include <iostream>

using namespace std;

class Matrix 
{
public:

    Matrix() 
	{
        r_ = 0;
        c_ = 0;
        data_ = NULL;
    }
    
     Matrix(int r, int c)
	 {
        r_ = r;
        c_ = c;
        
        data_ = new int*[r];
        
        for(int i = 0; i<c; i++)
		{
            data_[i] = new int[c];
        }
    }
    
    virtual ~Matrix()
	{
    for (int i=0; i<c_; i++)
		{
	    delete [] data_[i];
	    }
    
    delete [] data_;
    }
    
    //the destructor is delcared as virtual so that inheriting classes
    //will remember to override this method and do their own cleanup - it prevent memory leaks.

    virtual void set(int r, int c, int d) 
	{
        if ((r < 0 || r >= r_) || (c < 0 || c >= c_)) exit(-1);
        data_[c][r] = d;
    }

    virtual int get(int r, int c) 
	{
        if ((r < 0 || r >= r_) || (c < 0 || c >= c_)) exit(-1);
        return data_[c][r];
    }

    virtual void print() 
	{
        for (int r = 0; r < r_; ++r) 
		{
            for (int c = 0; c < c_; ++c)
                cout << get(r, c) << " ";
            cout << "\n";
        }
    }
    
protected:
    int r_, c_;
    int** data_;
};

class UTMatrix:public Matrix
{
public:
    UTMatrix(int x):Matrix(x,x){}
    
    virtual void set(int r, int c, int d) 
	{
        if ((r < 0 || r >= r_) || (c < 0 || c >= c_) || (r > c)) exit(-1);
        data_[c][r] = d;
    }
};

int main()
{
    Matrix m1(2,2);
    m1.print();
    Matrix m2(5,5);
    m2.print();
    
    UTMatrix u1(5);
    u1.print();
    u1.set(2,2,4);
    u1.print();
    UTMatrix u2(3);
    u2.print();
    Matrix m3(10,9);
    m3.print();
    Matrix m4(5,5);
    m4.print();
    UTMatrix u3(4);
    u3.print();
}
