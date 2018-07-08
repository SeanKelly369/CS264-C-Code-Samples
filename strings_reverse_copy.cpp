/**
Write a function in C++ that takes as a char * style zero terminated string
and returns a char * string twice the length of the input.  The first half
of the returned string should contain a copy of the contents of the original
array.  The second half of the string should contain the contents of the
original of the original string in reverse order. **/

#include <string>
#include <iostream>
#include <cstring>

using namespace std;

//Prototype function
char *copy_and_reverse(char *a);

int main(int argc, char** argv)
{
	//Original char array
	char hello[6] = {'h', 'e', 'l', 'l', 'o'};

	char *final_array = copy_and_reverse(hello);

	char final [11];

	for(int i = 0; i < 11; i++)
	{
		cout << "The combined length is :" << final[final_array] << endl;
	}

	delete[] final_array;

	return 0;
}

char *copy_and_reverse(char *a)
{
	//Original char array's length
	int char_length = 5;

	//Final char array length
	int char_length_b = (char_length * 2);

	//Use dynamic memory to create a new character pointer
	char *b = new char[char_length_b];

	//Pass in the char
	for(int i = 0; i < char_length; i++)
	{
		a[i] = b[i];
	}

	//Store the length of the original array to being second half of final away swap in reverse.
	//Use -1 because arrays begin at 0
	int j = char_length -1;

	//Populate the second half of the double sized array with the reverse values
	for(int k = char_length; k < char_length_b; k++)
	{
		b[k] = a[j];
		j--;
	}
	return b;
}

