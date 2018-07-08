#include <iostream>
using namespace std;

//Prototype method
double *copy_and_reverse(double *a, int alength);

int main(int argc, char** argv)
{
	//Declare an array of doubles and give it a length
	double a[5] = {4.5, 3.3, 2.1, 1.3, 6.7};
	int alength = 5;
	
	//Call in the function that will combine the two arrays, the original and reverse into a new array double the original length
	double *finalarray = copy_and_reverse(a, alength);
	
	cout << "The combined array values are: " << endl;
	
	//Print out the values
	for(int i = 0; i < (alength * 2); i++)
	{
		cout << finalarray[i] << ", ";
	}

	//De-allocate memory
	delete[] finalarray;
	
	return 0;

}//end main


double *copy_and_reverse(double *a, int alength)
{
	//Make new array length double the size of the original
	int blength = (alength * 2);
	
	//Use dynamic memory	
	double *b = new double[blength];

	//Populate the first half of the double sized array with the original values
	for(int i = 0; i < alength; i++)
	{
		b[i] = a[i];
	}
	
	//Use minus one because arrays start at 0
	int j = alength - 1;
	
	//Populate the second half of the double sized array with the reversed values
	for(int k = alength; k < blength; k++)
	{
		b[k] = a[j];
		j--;
	}
	
	return b;
	
} //End *copy_and_reverse
