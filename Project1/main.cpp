//Erick Castro
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Array.h"
#include "arrayMenu.h"

using namespace std;

Array<int> arrayObj;			//Object for array class
arrayMenu<int> arrayMenuObj;	//Object for array menu class

//Main is only used to call the algorithm menu from the array menu class.
int main()
{
	//arrayMenuObj.arrayOperation(1, 1, 1); // Used to bypass menu and run specific operations.

	arrayMenuObj.algMenu(); // Calls the algorithm menu.

	system("pause");
    return 0;
}



