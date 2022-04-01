#include <iostream>

#include "ListOfNumbers.h"

using namespace std;

int main()
{
	//Defining the list variables
	ListOfNumbers* a, * b, * c, *origin;

	//Adding numbers to the list
	origin = new ListOfNumbers(NULL);
	a = new ListOfNumbers(10);
	b = new ListOfNumbers(5);
	c = new ListOfNumbers(-24);

	//Print out value without address
	cout << *a << endl;
	cout << *b << endl;
	cout << *c << endl;


	//Link the entry to the next value
	origin->SetNext(a);
	a->SetNext(b);
	b->SetNext(c);

	// Adding non recursive.
	a->Add(23);

	// Adding recursive.
	a->AddR(43);

	//Print individual numbers a,b,c
	cout << "Values : " << endl << endl;
	a->PrintItem();
	b->PrintItem();
	c->PrintItem();

	//Print everything starting from a
	cout << endl << "Printing everything : " << endl << endl;
	a->PrintList();

	//Print everything starting from c
	cout << endl << "Printing everything after c : " << endl << endl;
	c->PrintList();

	//remove a perticular 
	a->Remove(b);
	cout << endl << "Removed 5 : " << endl << endl;
	a->PrintList();

	cout << endl << "Trying to find 10 : " << endl << endl;
	a->find(10);
	a->findR(10);

	cout << endl << "Trying to find 1000 (A value not in the list) : " << endl << endl;
	a->find(70);
	a->findR(70);
}