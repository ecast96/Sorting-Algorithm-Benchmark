#pragma once
#include "Array.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

template <class T>
class arrayMenu
{
public:
	arrayMenu();
	~arrayMenu();

	void algMenu();

	void arrayTypeOption(Array<int>*, int);	//Fills array with array type seleceted
	void arraySortOption(Array<int>*, int); //Runs operation with sort selection
	int arraySizeOption(int); //Returns size selected 

	void arrayOperation(int, int, int); // Takes in all choices to run program

};
