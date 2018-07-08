#include <iostream>

using namespace std;




int* myfunction (int* arr , int length){

	int new_len = length*2;

	int array[new_len];

	for (int i = 0; i<length; i++)
	{

		array[i] = *(arr +i);

		//cout<<array[i]<<endl;
	}

	int j = length;

	for (int i = length; i<new_len; i++)
	{
		array[i] = *(arr+j);

		//cout<<array[i]<<endl;

		j--;
	}

	int* final_arr;

	final_arr = array;

	for (int i = 0; i<10; i++)
	{ cout<<" *" <<endl;
		//cout<<*(final_arr + i)<<endl;
	}

	return final_arr;



} 


int main () {
	


 int arr1 [5];

 for (int i = 0; i<5; i++)
 {
 	arr1[i] = i;
 	//cout<<arr1[i]<<endl;
 }

 int* p_arr;
 p_arr = arr1;

 	int* return_arr = myfunction(p_arr, 5);

 	for (int i = 0; i<10; i++)
 	{
 		cout<<*(return_arr+i)<<endl;
 	}





	return 0;
}