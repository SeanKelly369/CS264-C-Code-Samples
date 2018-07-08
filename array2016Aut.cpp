/* cs264 Q1 (a) Autumn 2016 */

#include <iostream>

using namespace std;


int * copy_and_reverse(int * array, int length); // function prototype, implementation can be below main. 
void printList(int * list, int size);

int main(){

	int list[4] = {1,2,3,4}; // remember list is also a pointer to the first integer memory box in the array.
    int size = 4;

    cout << endl << endl << " **** Printing out the original array *******" << endl << endl;

	printList(list, size);   // print out the contents of the list.

	cout << endl << endl << "*** now we are going to use the copy_and_reverse function and verify it works ****" << endl << endl;

    // the copy_and_reverse function returns a pointer to a newly created array.
	// therefore we must have a variable capable of receiving this new array (pointer).

    int * temp = copy_and_reverse(list, size);

    printList(temp,size*2);	// verify the contents of the new array.

}

// Takes a pointer to an array of integers and the length of this array
// return a pointer toa newly created array that is twice the length of 
// the input array. The first half of the new array contains a copy of the 
// input array and the second half contains a reversed copy of the array. 
// E.g. original array; {1,2,3,4} new array : {1,2,3,4,4,3,2,1}

int * copy_and_reverse(int * array, int length){

	int twiceLength = 2 * length; // the new size of the array.

	int * twiceArray = new int[twiceLength];

	for (int i=0;i<length;i++){
		
		twiceArray[i] = array[i];

	} // end for i loop to fill the first half

    int x = length-1; // index of the last element of the first array
   
    // continue to fill the second half of the new array

	for (int j=length;j<twiceLength;j++){

		twiceArray[j] = array[x];
		x--; // go backwards through the orignal array.

	} // end for j loop to fill the second half

    return twiceArray; // return the newly created array.

} // end copy_and_reverse function.

void printList(int * list, int size){

	for (int i=0;i<size; i++){
		cout << list[i] << " element " << i << endl;

	}
}

