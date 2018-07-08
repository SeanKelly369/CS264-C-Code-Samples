/*
Joseph Duffin 20th November 2017
This example is designed to illustrate the concept of struct in C++ and also how you can 
link struct objects together by using pointers (address variables).
What you are really seeing here is a linked list, or a list of struct objects that are linked together 
by virture of them having an address variable (pointer) that stores the address of another object. 
In order to grasp this idea, you should draw out the memory box diagram for a single object, then draw
out the memory box diagrams for the three objects and show how they are linked together. 
Remember last week when we discussed address variables (pointers) and how they can be used to access other 
variables through storing the machine addressses of these other variabes?

*/
#include <iostream>
#include <string>

using namespace std;

struct client {

  string name;
  int age;
  client * next;

};

void display (client & box);  // This is a funtion prototype, placing it here allows us to provide its full definition below main.

int main() {

  client cl1, cl2, cl3;  // create three client struct objects.

  cl1.name = "Joe";
  cl1.age = 20;
  cl1.next = &cl2;  // the first client object links to the second client object.

  cl2.name = "Jimmy";
  cl2.age = 40;
  cl2.next = &cl3;  // the second client object links to the third client object.
  
  cl3.name = "Mary";
  cl3.age = 19; 
  cl3.next = NULL; // the third client object is linked to no other object and it is the end of the list objects.

  cout << "Client 1 has name " << cl1.name << "  and age  " << cl1.age << endl;
  cout << "Client 2 has name " << cl2.name << "  and age  " << cl2.age << endl;
  cout << "Client 3 has name " << cl3.name << "  and age  " << cl3.age << endl;

  // Let's see if we can access client 2 by using the pointer to client 2 that is stored in the next variable of client 1.
  cout << "*********** Fancy experimentation section *****************************" << endl;

  cout << "The client 1 name is " << cl1.name << endl; 
  cout << "The client 1 age is " << cl1.age << endl;
  cout << "The client 2 address is (by using the pointer stored in client 1)   " << cl1.next << endl; 

  // The code below represents two different ways (threee if you count the messing around with precedence rules
  // to access the contents of a struct object via a variable in another struct that contains the address to 
  // the struct that you interested in 

  cout << "The client 2 name is (by using the pointer stored in client 1)   " << (cl1.next)->name << endl; 
  cout << "The client 2 name is (by using the pointer stored in client 1)   " <<  cl1.next->name << endl; 
  cout << "The client 2 name is (by using the pointer stored in client 1)   " << (*cl1.next).name << endl; 

  cout << "*********** End of the experimentation section ************************" << endl;
  
  // Now, we could go through each client and play around like we did above, but here is an interesting thing to do, 
  // how would you go through the three struct objects (knowing that they are somehow linked, this is called a linked list by 
  // the way), how would you go through the three struct objects and print out their contents using a loop structure.
  // If you examine the three clients you will see that their is space to store the address of a struct object or another 
  // client. The last client struct object is not contected to any other struct object and that is why its next variable is giving
  // the value NULL (null pointer). This means that client 3 is the end of the list of the linked list of structs.

  // Lets do this 

  // What is the termination condition for this loop, hint: when we reach a client that is connected to none other 
  // via its next variable.

  client * temp = &cl1; // store the address of ther first struct in struct address variable (pointer) named temp.
  
  // We will use a while loop to allow us to traverse (go through the object (struct) clients print them out).
  while ( temp != NULL){  
     
       // The two lines below are duplicated to show two different ways of doing the same thing, i.e. using * and . ,  or ->
       cout << "This clients name is " << temp->name << " and age is " << temp->age << endl; 
       cout << "This clients name is " << (*temp).name << " and age is " << (*temp).age << endl; 
       
       // reassign temp to the address of the next client (the address stored in the next field of the current object).
  
       temp = temp->next; // temp now has a new address in it, or it points to a different location or object.

  }  // end of the list traversal

  
  // Lets do this all again by calling a method.
  cout << " ################  Using a method call to traverse the same list ################" << endl;

  display(cl1);


}  // End of the main method.

void display (client & box){  // This signature tells us that the box is passed by reference.

  client * temp = &box; // the local variable temps is an address variable that stores the address of the box.

  // We will use a while loop to allow us to traverse (go through the object (struct) clients print them out).
  while ( temp != NULL){  
     
       // The two lines below are duplicated to show two different ways of doing the same thing, i.e. using * and . ,  or ->
       cout << "This clients name is " << temp->name << " and age is " << temp->age << endl; 
       cout << "This clients name is " << (*temp).name << " and age is " << (*temp).age << endl; 
       
       // reassign temp to the address of the next client (the address stored in the next field of the current object).
  
       temp = temp->next; // temp now has a new address in it, or it points to a different location or object.

  }  // end of the list traversal


} // end of the display method.
