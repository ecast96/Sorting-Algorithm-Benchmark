//Erick Castro
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include "Array.h"
#include <time.h>
using namespace std;

template <typename T>
Array<T>::Array(){}

/* Creates and fills array with 0's of size passed in from user.*/
template <typename T>
Array<T>::Array(T value)
{
    sizeOfArray = value;
    arrayData = new T[sizeOfArray];
    for(int i = 0; i < value; i++){
        arrayData[i] = 0;
    }
}

template <typename T>
Array<T>::~Array() {}

/* Swap function to switch the places of two values in the array
	- Parameters: index of elements
*/
template <typename T>
void Array<T>::exch(int i, int j)
{
	T temp = arrayData[i];
	arrayData[i] = arrayData[j];
	arrayData[j] = temp;
}

/* When called:
	1. Fills array in order.
	2. Reverses the elements in the array.
*/
template <typename T>
void Array<T>::fillReverse()
{
	addElements();	//Fills array in order

    for(int i = 0; i < sizeOfArray / 2; i++){   //Reverses array elements
		exch(sizeOfArray - i - 1, i);
    }
    return;
}

/* Displays elements of array.*/
template <typename T>
void Array<T>::Display()
{
    cout << "[";
    for(int i = 0; i < sizeOfArray; i ++){
        if(i == sizeOfArray - 1)
            cout << arrayData[i];
        else
            cout << arrayData[i] << ", ";
    }
    cout << "]\n";
}

/* Fills the array in order */
template <typename T>
void Array<T>::addElements()
{
    for(int i = 0; i < sizeOfArray; i++){
        arrayData[i] = i;
    }
}

/* Fills the array with random values (Shuffled)*/
template <typename T>
void Array<T>::addRandomElements()
{
    for(int i = 0; i < sizeOfArray; i++){
        arrayData[i] = (rand() % 100) + 1;
    }
}

/* When called:
	1. Fills array in order
	2. Reverses the elements
*/
template <typename T>
void Array<T>::shuffleSorted()
{
	addElements();

    for(int i = 0; i < sizeOfArray * 0.10; i++){
        arrayData[i] = rand() % sizeOfArray - 1;
    }
}
/* Reverses elements in the array */
template <typename T>
void Array<T>::reverseArray()
{
    for(int i = 0; i < sizeOfArray / 2; i++){
		exch(sizeOfArray - i - 1, i);
    }
    return;
}

/* Helper function 
	- Used to verify that arrays are correctly sorted
*/
template <typename T>
bool Array<T>::verifySort()
{
    for(int i = 0; i < sizeOfArray - 1; i++){
        if(arrayData[i] > arrayData[i+1]){
			return 0;
        }
    }
	return 1;
}

/* Implementation of Insertion Sort*/
template <typename T>
void Array<T>::insertionSort()
{
   int i, key, j;
   for (i = 1; i < sizeOfArray; i++)
   {
       key = arrayData[i];
       j = i-1;

       while (j >= 0 && arrayData[j] > key)
       {
           arrayData[j+1] = arrayData[j];
           j = j-1;
       }
       arrayData[j+1] = key;
   }
}

/* Implementation of Selection Sort*/
template <typename T>
void Array<T>::selectionSort()
{
    int min, temp = 0;
    for(int i = 0; i < sizeOfArray - 1; i++)
    {
        min = i;
        for(int j = i+1; j < sizeOfArray; j++) //Finds min in array
        {
            if(arrayData[j] < arrayData[min])  //Sets new min value
                min = j;
        }

		if (min == i)
			continue;
		else
			exch(i, min);	//Swaps min found and index of iteration
    }
}

/* Implementation of Bubble Sort */
template <typename T>
void Array<T>::bubbleSort()
{
    int temp = 0;
    for(int i = 0; i < sizeOfArray; i++){
        for(int j = 0; j < sizeOfArray-i-1; j++)
            if(arrayData[j] > arrayData[j+1]){
				exch(j, j + 1);
            }
    }
}
/* Implementation of Quick Sort with no extra partition function */
template <typename T>
void Array<T>::quickSort(int lo, int hi)
{
	int i, j, pivot, temp;

	if (lo == hi) return;
	i = lo;
	j = hi;
	pivot = arrayData[(lo + hi) / 2]; // Pivot selected at the center/middle

	do {
		while (arrayData[i] < pivot) i++; // Moves up while smaller than pivot
		while (arrayData[j] > pivot) j--; // Moves down while bigger than pivot
		if (i <= j) {
			exch(i, j); // Swaps values when i and j stop traversing
			i++;
			j--;
		}
	} while (i <= j);

	if (lo < j) quickSort(lo, j); //Recursive call for left side
	if (i < hi) quickSort(i, hi); //Recursive call for right side
}

/* Partition function used for Merge Sort */
template <typename T>
void Array<T>::mergePart(int leftBottom, int leftTop, int rightBottom, int rightTop)
{
    int length = rightTop - leftBottom+1;
    T* temp = new T[length];  
    int left = leftBottom;
    int right = rightBottom;
    for (int i = 0; i < length; ++i) {
        if (left > leftTop)
            temp[i] = arrayData[right++];
        else if (right > rightTop)
            temp[i] = arrayData[left++];
        else if (arrayData[left] <= arrayData[right])
            temp[i] = arrayData[left++];
        else
            temp[i] = arrayData[right++];
        }
    for (int i=0; i< length; ++i)
        arrayData[leftBottom++] = temp[i];

    delete [] temp;
}

/* main function for Merge Sort
	- Calls the partition function to split array into smaller sub-arrays
*/
template <typename T>
void Array<T>::mergeSort(int left, int right)
{
    if(left >= right)
        return;
    else {
        int mid = (left + right)/2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        mergePart(left, mid, mid+1, right);
    }
}

template class Array<int>;
template class Array<char>;

