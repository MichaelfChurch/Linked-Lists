#include <iostream>
#include "ListOfNumbers.h"
ListOfNumbers::ListOfNumbers()
{
	number = 0;
	next = NULL;
}
ListOfNumbers::ListOfNumbers(int v)
{
	number = v;
	next = NULL;
}
void ListOfNumbers::SetValue(int v)
{
	number = v;
}
void ListOfNumbers::SetNext(ListOfNumbers* n)
{
	next = n;
}
//Implement in add function and remove

/*void ListOfNumbers::SetPrevious(ListOfNumbers* n) {
	previous = n;
}
*/

// Prints a single item’s number
void ListOfNumbers::PrintItem()
{
	std::cout << "Number = " << number << "      [" << this << " ; " << next << "]" << std::endl;
}
// Prints the whole list
void ListOfNumbers::PrintList()
{
	ListOfNumbers* current = this;
	while (current != NULL)
	{
		std::cout << current->number << "      [" << current << "]" << std::endl;
		current = current->next;
	}
}

std::ostream& operator<<(std::ostream& out, const ListOfNumbers& a)
{
	out << "List of Numbers value = " << a.number;
	return out;
}
//Adding a number
void ListOfNumbers::Add(ListOfNumbers* n)
{
	ListOfNumbers* current = this;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = n;
}
void ListOfNumbers::Add(int v)
{
	ListOfNumbers* temp = new ListOfNumbers(v);
	Add(temp);
}

//Adding a number recursively
void ListOfNumbers::AddR(ListOfNumbers* n)
{
	if (next == NULL)
		next = n;
	else
		next->AddR(n);
}
void ListOfNumbers::AddR(int v)
{
	ListOfNumbers* temp = new ListOfNumbers(v);
	AddR(temp);
}

void ListOfNumbers::Remove(ListOfNumbers* n) {
	ListOfNumbers* TempRemove = this;
	while (TempRemove->next != n){
		TempRemove = TempRemove->next;
	}
	TempRemove->next = n->next;
}

ListOfNumbers* ListOfNumbers::find(int v) {
	ListOfNumbers* current = this;
	if (v == number) {
		std::cout << "(Non-Recursive) A value was found" << "\n";
		return current;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
			if (v == current->number) {
				std::cout << "(Non-Recursive) A value was found" << "\n";
				return current;
			}
		}
		std::cout << "(Non-Recursive) No value was found" << "\n";
		return NULL;
	}
};

ListOfNumbers* ListOfNumbers::findR(int v) {

		if (next != NULL && v == number) {
			std::cout << "(Recursive) A value was found" << "\n";
			return next->findR(v);
		}
		else {
			std::cout << "(Recursive) No value was found" << "\n";
			return NULL;
		}
}


//Destructor
ListOfNumbers::~ListOfNumbers()
{
	while (next != NULL) {
		delete next;
	}
}


void ListOfNumbers::swap(ListOfNumbers* point1, ListOfNumbers* point2) {
	ListOfNumbers* temp = point2->next;
	point2->next = point1;
	point1->next = temp;
}
