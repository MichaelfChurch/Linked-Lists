#pragma once
#include <iostream>

class ListOfNumbers {
private:
	int number;
	ListOfNumbers* next;

public:
	ListOfNumbers();
	ListOfNumbers(int v);
	//Deconstructor
	~ListOfNumbers();


	void SetValue(int v);
	void SetNext(ListOfNumbers* n);

	// Prints a single item’s number
	void PrintItem();

	// Prints the whole list
	void PrintList();

	// Add a new item to the list
	void Add(ListOfNumbers* n);
	void Add(int v);
	// add a new item to the list recursive
	void AddR(ListOfNumbers* n);
	void AddR(int v);

	//remove a specific item
	void Remove(ListOfNumbers* n);
	//Finds a specific
	ListOfNumbers* find(int v);
	ListOfNumbers* findR(int v);
	void swap(ListOfNumbers* point1, ListOfNumbers* point2);

	void bubbleSort(ListOfNumbers* head, int count);
	// Overload the operator <<
	friend std::ostream& operator<<(std::ostream& out, const ListOfNumbers& a);
};
