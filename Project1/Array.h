//Erick Castro
#include <iostream>
#include <stdlib.h>
#ifndef ARRAY_H
#define ARRAY_H

// Array class that holds all functions regarding the array operations
template<class T>
class Array
{
    public:
        Array();
        Array(T);
        ~Array();

        T *arrayData;
        int sizeOfArray;

        void Display();		 //Displays elements in the array
        bool verifySort();	 //Used to verify arrays are correctly sorted
		void exch(int, int); //Used to swap values in array
		void reverseArray(); //Reverses contents of array

        void fillReverse(); //Fills arrays in order and reverses entire array
        void addElements(); //Fills arrays in order
        void addRandomElements(); //Fills arrays with random values (1-100)
        void shuffleSorted(); //Fills array in order and shuffles 10% of the elements

        void insertionSort();
		void selectionSort();
		void bubbleSort();

		void mergeSort(int, int);
		void mergePart(int, int, int, int);

		void quickSort(int, int); 

    protected:
    private:
};

#endif // ARRAY_H

