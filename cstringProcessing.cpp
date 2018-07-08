#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char * reverse(const char str[]);
// Take a zero temainated c-string as input and returns a reversed version 
// of that string as output. 

int main() {


  cout << "Hello Joe" << endl;
  
  char word[] ={'h','e','l','l','o','\0'};
  char word2[6] ={'h','e','l','l','o','\0'};
  char * temp = word;
  string word3 = temp;
  
  cout << word << endl;
  cout << word2 << endl;
  cout << temp << endl;
  cout << word3 << endl;
  
  cout << "The word in reverse is " << endl;
  cout << reverse(word) << endl;
  

}

char * reverse(const char str[])
{  
	// const means that if we try to change the str in our code the compile will generate an error.
	
	int len = strlen(str); // variable for storing the length of the array .
	
	// str[0] = "F"; // Breaking the const rule will generate a copiler error.
	
	char temp [len]; // create a new c-string to hold the reversed contents of the parameter.
	
	for (int i = len - 1, j = 0; i >= 0; i--; j++)
	{
		temp[j]=str[i]; // Assign the character values in str in to temp
	}
	
	temp[len] = '\0'; // add the null pointer to the end of the temp c-string.
	
	// print out the characters of the c-string
	for (int i = 0; i <= len - 1; i++)
	{  		
		cout << temp[i] << endl;	
	}
	
	char * value = new char[len]; // create a c-string from the heap 
	
	strcpy(value,temp);  // copy the temp string into the value string.
	
	return value; // return the pointer of the newly created c-string to the calling context.
	
}
