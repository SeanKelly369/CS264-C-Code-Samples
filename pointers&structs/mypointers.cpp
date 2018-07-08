//pointer is just a refference variable that stores a block of memory
//& is an operator tha#
//& x gives me the adress of variable x

//---------------------------------------------------

//Example - pointers
#include <iostream>
using namespace std;
bool odd(int x)
	{
	bool retval = (x%2==1);
	return (retval);
	}
	main()
	{
	int x;
	cin >> x;
	bool decision = odd(x);
	if (decision)
		cout << x << "is odd" <<endl;
		else
		cout << x << "is even" <<endl;
	}
//---------------------------------------------------

//Exercise 1
#include <iostream>
using namespace std;
int main(void)
{
    int x=5;
    int y=7;
    int temp;
    int *px = &x;
    int *py = &y;
    int *pt = &temp;
    //int *p = &x; // the refference of variable p; stores the addess of the variable x
	// DELCARATION
	// IMPORTANT! - derrenferencing
	// will change the pointer to x
	//int *rabbit = &x;

	// DEREFFERENCING
	// will overwrite rabbit!!!!!! (willl dereffernce p)
	// wil put 22 into p and can be accessed by adress x!!
	//*rabbit = 22; // this overrites 7

	//derefferencing the point
	//*p = 6;
	//cout << "values of x is " << x << endl; //22
	//cout << "values of x is " << *p << endl; //22

    *pt = *px;
    *px = *py
    *py = *pt
		cout << "values of x is " << x << endl;
		cout << "values of y is " << y << endl;
// write a code to swap the values of x and y so that x is 7 and y is 5

//? TO DO
// write very fance code tha uses pointers swap variables around
// hint declare three reference variable pointers, one for each other varibles x, y, and temp. next use these reference varuables pointers to perform the swap if the contents of of x and y
}

//--------------------------------------------------

//!Exercise 
#include <iostream>
using namespace std;
int main(void)
{
int x=5;
int y=7;
int *apple = &y;
int *pear = &y;
	cout << "values of x is" << x << endl; //5
	cout << "values of x is" << *pear << endl; //5


// add code that uses the referebce variable pear to put the value placed in y into x
// after this code exexutes, x will have the value 7 in it
//x = *pear;
*pear = x;
	cout << "values of x is" << *pear << endl; //5
	//cout << "values of x is" << *pear << endl; //5
}

//--------------------------------------------------

Exercise 3
#include <iostream>
using namespace std;
void my_swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    cout << " new number 1 is " << *num1 << " new number 2 is " << *num2 << endl;
}
int main()
{
    int num1, num2;
    cout << " enter the first number " << endl;
    cin >> num1;
    cout << " enter the second number " << endl;
    cin >> num2;
    cout << " number 1 is " << num1 << " number 2 is " << num2 << endl;
    cout << "LETS SWAP! " << endl;
    my_swap(&num1, &num2); // keeping the adress in the main since its taking in an int
    return 0;
}

//--------------------------------------------------

Exercise 4
#include <iostream>
using namespace std;
int main()
{
	int num1, num2;
	cout << "Enter first number: ";
	cin >> *num1; //4
	cout << "Enter second number: ";
	cin >> *num2; //2
	cout << "Greatest common divisor is: " << gcd(num1, num2) << endl;
}
int gcd(int &a, int &b)
{
	int small = 0;
	if (a >= b) //4,2 = true
	{
		small = b; //!small=2
		if (a % b == 0) // if 4 can be devided by 2 than true
			return b; //return (2)
	}
	else //4,2 = false
	{
		small = a; //!small=4
		if (b % a == 0)
			return a; // return (4)
	}
	for (int i = small/2; i >= 1; i--) // 2/2 = 1
	{
		if(a % i == 0 && b % i == 0)
			return i;
	}
}
