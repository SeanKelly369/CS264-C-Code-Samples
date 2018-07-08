/*
Joseph Duffin 4th December 2017

This examples is different from the strucExample.cpp file in that it uses heap memory, dynamically allocated 
from the heap using new, and returned to the heap (when required to do so) using delete. 

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
  client * next;  // address variable or pointer to another struct object
};  // don't forget the ; character at the end of the structure (which is the same for a class).

void display (client *);  // This is a funtion prototype, placing it here allows us to provide its full definition below main.
void addToBack(client * head, client * node); // You can include or leave out the an identifier name, make sure that if you change the prototype 
// you also must change the implementation.

int main() {
  //**************** Dynamic memory allocation for structs from the heap  ************************
  client * clx = new client; 
  client * cly = new client;
  client * clz = new client;
  
  ///**************** Initialising the struct objects *************************************
  clx->name = "Ann";
  clx->age = 41;
  cly->name = "Bob";
  cly->age = 51;
  (*clz).name = "Pam";  // using a different way of accesing the struct fields dereferencing the struct pointer using *
  (*clz).age = 61;	 // using a different way of accesing the struct fields dereferencing the struct pointer using *
  
  cout <<endl << endl << "**** START ****" <<endl << endl;
  cout << "(First client) The dynamic client " << clx->name << " is " << clx->age << "  years old " << endl; 
  cout << "(Second client) The dynamic client " << cly->name << " is " << cly->age << "  years old " << endl; 
  cout << "(Third client) The dynamic client " << clz->name << " is " << clz->age << "  years old " << endl; 

  //************ Linking the dynmically allocated struct objects together ***********************

  clx->next = cly;  // remember cly ia a pointer to a struct so it can be assigned directly to the next field.
  cly->next = clz;  // remember clz is a pointer to a struct so it can be assigned directly to the next field.
  clz->next = NULL; // The last client in the list is connected to no other object

  // ********** end of the struct object linking section ****************************************

  // Now, we could go through each client and play around like we did above, but here is an interesting thing to do, 
  // how would you go through the three struct objects (knowing that they are somehow linked, this is called a linked list by 
  // the way), how would you go through the three struct objects and print out their contents using a loop structure.
  // If you examine the three clients you will see that their is space to store the address of a struct object or another 
  // client. Note that, the last client struct object is not contected to any other struct object and that is why its 
  // next variable has been given the value NULL (null pointer). 
  // This means that third client is the end of the list of the linked list of structs.

  // Let's do this 
  // What is the termination condition for this loop, hint: when we reach a client that is connected to none other 
  // via its next variable.


  cout << endl << endl << "******* Using a loop to print the list ************* " << endl << endl;

  client * temp1 = clx; // store the address of ther first struct in struct address variable (pointer) named temp.
  
  // We will use a while loop to allow us to traverse (go through the object (struct) clients and print them out).
  while ( temp1 != NULL){  
    
      // The two lines below are duplicated to show two different ways of doing the same thing, i.e. using * and . ,  or ->
      cout << "This client's name is " << temp1->name << " and age is " << temp1->age << endl; 
      //cout << "This client's name is " << (*temp1).name << " and age is " << (*temp1).age << endl; 
      
      // reassign temp to the address of the next client (the address stored in the next field of the current object).

      temp1 = temp1->next; // temp now has a new address in it, or it points to a different location or object.



  }  // end of the list traversal


  // End of the loop for traversing the linked list.
  
  
  // Lets do this all again by calling a method.

  cout << endl << endl << " ################  Using a function call to traverse the same list ################" << endl<<endl<<endl;

  display(clx);

  cout << endl << "*** prepare a new node for additon ****" << endl;
  // create additional extra struct noded, which we will add to the link list one-by-one.
  client * cl_n = new client;  
  client * cl_u = new client; 

  // initialise the node fields, name, age and next pointer.
  cl_n->name = "Peter piper";
  cl_n->age = 101;
  cl_n->next = NULL;

  cl_u->name = "Rufus";
  cl_u->age = 99;
  cl_u->next = NULL;
  
  cout << " *** call the function addToBack to add to the end of the list " << endl;
  // use the function addToBack, which adds the additional node to the end of the list.
  addToBack(clx,cl_n);
  cout << endl << endl << "Call to the display function  " << endl << endl;
  // display the list, which should now contain an extra node added at the end.
  display(clx);
  
  cout << endl << endl << " *** call the function addToBack to add to the end of the list " << endl;
  // Add a second node to the end of the list
  addToBack(clx,cl_u);
  
  cout << endl << endl << "Call to the display function " << endl << endl; 
  // Display the node.
  display(clx);

}  // End of the main method.

void display (client * head){  // This signature tells us that the box is passed by reference.

  client * temp = head; // the local variable temps is an address variable that stores the address of the box.

  cout << "%%%%%% head of the list :" << temp->name << "  " << temp->age <<endl;

  // We will use a while loop to allow us to traverse (go through the object (struct) clients print them out).
  while ( temp != NULL){  
    
      // The two lines below are duplicated to show two different ways of doing the same thing, i.e. using * and . ,  or ->
      cout << "This client's name is " << temp->name << " and age is " << temp->age << endl; 
      //cout << "This client's name is " << (*temp).name << " and age is " << (*temp).age << endl; 
      
      // reassign temp to the address of the next client (the address stored in the next field of the current object).

      temp = temp->next; // temp now has a new address in it, or it points to a different location or object.

  }  // end of the list traversal

} // end of display method

// This function will add a new node to the end of the list
// Precondition: the function receives a pointer to the top of the list and a pointer to the new node.
// Postcondition: the list will have an additional node added to it. 
void addToBack(client * head, client * addedBox) {

   	client * temp = head; // local varialbe temp is to store the address of the first struct in the list.
    client * currentLast = head; // local variable last stores the address of the last node.

  	// Traverse the list to find the last node, and then add the new node on to the list. 
	// This loop also keeps track of the current node so that we can revert to it and attach a new 
    // node on to it when you realise that you have reached the end of the list. 
    // This is stored in the variable "currentLast".
    while (temp != NULL) {
              
        currentLast = temp; // holds the current last node of list which may turn out to be the last.
		temp = temp->next; // move temp on to the next node pointer, if this turns out to be NULL we leave the loop.

    } // end while

    currentLast->next = addedBox;  // we add the new node to the last node in the list whose next pointer had a NULL value.

}  // end of the addToBack function.



