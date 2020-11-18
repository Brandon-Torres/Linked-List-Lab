//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations
#include "ArrayList.h"
#include <fstream>

using namespace std;

void listTester(ListInterface<int>* listPtr,ListInterface<int> * arrayPtr)
{
	ifstream inFile;
	int counter2 = 0;
	int value;
	//open the text file
	inFile.open("Text.txt");
	std::cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << std::endl;
	//read in data from the file into both linked list and arraylist 
	while(!inFile.eof())
	{
		inFile >> value;
		//inserting values into linkedlist 
		if (listPtr->insert(counter2 + 1,value))
		{
			try
			{
				std::cout << "Inserted " << listPtr->getEntry(counter2 + 1) << " at position " << (counter2 + 1) << std::endl;
			}	
			catch (PrecondViolatedExcep except)
			{
				std::cout << "Exception thrown getting entry inserted at list end!" << std::endl;
				std::cout << except.what() << std::endl;
			}
		}
		else
			std::cout << "Cannot insert " << listPtr->getEntry(counter2) << " at position " << (counter2 + 1) << std::endl;

		//inserting values into arraylist
		if (arrayPtr->insert(counter2 + 1, value))
		{
			try
			{
				std::cout << "Inserted " << arrayPtr->getEntry(counter2 + 1) << " at position " << (counter2 + 1) << std::endl;
			}
			catch (PrecondViolatedExcep except)
			{
				std::cout << "Exception thrown getting entry inserted at list end!" << std::endl;
				std::cout << except.what() << std::endl;
			}
		}
		else
		std::cout << "Cannot insert " << arrayPtr->getEntry(counter2) << " at position " << (counter2 + 1) << std::endl;
		
		cout << endl;
		//increment counter
		counter2++;
	}  // end for

	//display unsorted linked list and unsorted arraylist
	listPtr->print();
	arrayPtr->print();

	std::cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << std::endl;
	std::cout << "getLength returns : " << listPtr->getLength() << "; should be 5" << std::endl;
	
	//variables to hold value and index changes in sorting for LinkedList below
	int linked_List_Temp;
	int linked_List_First;

	//generic sorting procedure for linkedlist 
	for (int i = 1; i <= listPtr->getLength() - 1; i++)
	{
		linked_List_First = i;
		for (int j = i + 1; j <= listPtr->getLength(); j++)
		{
			if (listPtr->getEntry(j) < listPtr->getEntry(linked_List_First))
			{
				linked_List_First = j;
			}
			//swap values from both indexes
			linked_List_Temp = listPtr->getEntry(linked_List_First);
			listPtr->replace(linked_List_First, listPtr->getEntry(i));
			listPtr->replace(i, linked_List_Temp);
		}
	}

	//variables to hold value and index changes in sorting for ArrayList below
	int array_List_Temp;
	int array_List_First;

	//generic sorting procedure for arraylist
	for (int i = 1; i <= arrayPtr->getLength() - 1; i++)
	{
		array_List_First = i;
		for (int j = i + 1; j <= arrayPtr->getLength(); j++)
		{
			if (arrayPtr->getEntry(j) < arrayPtr->getEntry(array_List_First))
			{
				array_List_First = j;
			}
			//swap values from both indexes
			array_List_Temp = arrayPtr->getEntry(array_List_First);
			arrayPtr->replace(array_List_First, arrayPtr->getEntry(i));
			arrayPtr->replace(i, array_List_Temp);
		}
	}
	cout << endl;
	//print out sorted linked list and sorted array list
	cout << "The linked list and array list sorted : " << endl;
	listPtr->print();
	arrayPtr->print();

	// sorted linked list with method
	listPtr->sorting();
	//print linked List after sort
	listPtr->print();
	
} // end listTester

int main()
{
	//linked list created 
	ListInterface<int>* listPtr = new LinkedList<int>();
	//arraylist created
	ListInterface<int> *arrayPtr = new ArrayList<int>();
	//pass both to listtester array to be processed
	listTester(listPtr,arrayPtr);
	system("PAUSE");
	return 0;
}  // end main



