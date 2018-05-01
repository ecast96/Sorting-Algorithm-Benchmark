//Erick Castro
#include "stdafx.h"
#include "Array.h"
#include "arrayMenu.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace chrono;

template <typename T>
arrayMenu<T>::arrayMenu()
{
}

template <typename T>
arrayMenu<T>::~arrayMenu()
{
}

// Function that contains the menus
//	- Gets input from user for:
//		1. Type of algorithm
//		2. Size of array
//		3. Type of array
//	- Passes choices selected to arrayOperation function that runs the tests
template <typename T>
void arrayMenu<T>::algMenu()
{
	//Menu for input from user for type of sorting algorithm.
	cout << "--- Algorithm Benchmark Main Menu ---\n";
	cout << "Algorithm List :\n" << "1 - Insertion Sort\n" << "2 - Selection Sort\n" << "3 - Bubble Sort\n"
		<< "4 - Quick Sort\n" << "5 - Merge Sort\n" << "0 - Exit Program\n";
	cout << "Select Algorithm: ";
	int sortChoice = 99;
	cin >> sortChoice;

	if (sortChoice == 0) // Exits program quickly if '0' is selected.
		return;

	//Menu for input from user for size of array.
	cout << "\n--- Size Menu ---\n";
	cout << "1 - 10\n";
	cout << "2 - 1,000\n";
	cout << "3 - 10,000\n";
	cout << "4 - 100,000\n";
	cout << "5 - 1,000,000\n";
	cout << "Enter desired array size: ";
	int sizeChoice = 0;
	cin >> sizeChoice;

	//Menu for input from user for type of array
	cout << "\n--- Type Menu ---\n";
	cout << "1 - Sorted\n" << "2 - Sorted and Shuffled at 10%\n"
		<< "3 - Completely Shuffled (Random Values)\n" << "4 - Sorted in Reverse Order\n" << "5 - Run on all types\n";
	cout << "Select Array Type: ";
	int typeChoice = 0;
	cin >> typeChoice;

	//Runs options selected on all types of arrays.
	if (typeChoice == 5)
		for (int i = 1; i < 5; i++)
			arrayOperation(sizeChoice, i, sortChoice);
	else
		arrayOperation(sizeChoice, typeChoice, sortChoice);

	//Asks if user wants to run another test.
	bool redoMenu = 0;
	cout << "\nDo you want to run another test?\nEnter 1(Yes) or 0(No): ";
	cin >> redoMenu;
	if (redoMenu == 1)
		algMenu();

	return;
}

/*
 Array Opration Function
  - Houses the main operations for the program.
  - Creates file to save values and array to run the algorithms with.
  - Main For-Loop contains:
		- Function to fill array
		- Function to sort array
		- Timing variables
*/
template <typename T>
void arrayMenu<T>::arrayOperation(int sizeChoice, int typeChoice, int sortChoice)
{
	Array<int>* A = new Array<int>(arraySizeOption(sizeChoice)); // Array created to be used by the sorting algorithm.

	int correctCount = 0; // Used to check if arrays are correctly sorted.

	ofstream myfile;
	myfile.open("results.csv", fstream::app); // File where duration times are saved.

	for (int i = 0; i < 100; i++)
	{
		arrayTypeOption(A, typeChoice);	// Fills array with type of array selected.
		//A->Display(); //Remove comment "//" to show array for each iteration.

		auto start = steady_clock::now();
		arraySortOption(A, sortChoice);	// Runs the sorting algorithm with options selected.
		auto end = steady_clock::now();

		//myfile << duration_cast<nanoseconds>(end - start).count() << ","; // Saves iteration duration in nanoseconds to file.

		//A->Display(); //Remove comment to show array for each iteration.
		//cout << "Iteration duration: " << duration_cast<seconds>(end - start).count() << endl; // Remove comment "//" to show duration of iteration.

		if (A->verifySort()) { //Checks each iteration to make sure array is sorted correctly.
			correctCount++;
		}
	}

	myfile << "\n";
	myfile.close();

	cout << "Number of arrays correctly sorted: " << correctCount << endl;

	delete A;
	return;
}

/* Runs sorting algorithm based on option selected from menu.
	Parameters are passed in from arrayOperation:
		- A = array used for sorting
		- option = what sort to use (selected in menu).
*/
template <typename T>
void arrayMenu<T>::arraySortOption(Array<int> *A, int option)
{
	switch (option)
	{
	case 1:
		A->insertionSort();
		break;
	case 2:
		A->selectionSort();
		break;
	case 3:
		A->bubbleSort();
		break;
	case 4:
		A->quickSort(0, A->sizeOfArray - 1);
		break;
	case 5:
		A->mergeSort(0, A->sizeOfArray - 1);
		break;
	}
	return;
}

/* Returns size based on option selected in menu. */
template<typename T>
int arrayMenu<T>::arraySizeOption(int option)
{
	switch (option)
	{
	case 1:
		return 10;
	case 2:
		return 1000;
	case 3:
		return 10000;
	case 4:
		return 100000;
	case 5:
		return 1000000;
	}
}

/* Fills array based on option selected in menu. */
template <class T>
void arrayMenu<T>::arrayTypeOption(Array<int> *A, int option)
{
	switch (option)
	{
	case 1:
		A->addElements();
		break;
	case 2:
		A->shuffleSorted();
		break;
	case 3:
		A->addRandomElements();
		break;
	case 4:
		A->fillReverse();
		break;
	}
	return;
}

template class arrayMenu<int>;
template class arrayMenu<char>;