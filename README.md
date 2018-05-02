# Sorting Algorithm Benchmark
 - All work done by Erick Castro

Program was made using Visual Studio 2017. If using any other IDE/Compiler, support for C++11 might be needed.

Program is menu-driven, meaning you select what options you want for the sorting algorithms. There are lines commented out that are used for testing/debugging purposes (e.g. Displaying arrays, writing to file, and displaying individual interation duration).

Data is saved to a csv file named "results.csv". Times are saved in 100 cell rows

When compiling and running, program will display the following menus:

    Sorting Algorithm:
     1 - Insertion Sort
     2 - Selection Sort
     3 - Bubble Sort
     4 - Quick Sort
     5 - Merge Sort

    Array Size: 
     1 - 10
     2 - 1,000
     3 - 10,000
     4 - 100,000
     5 - 1,000,000

    Array Type:
    1 - Array already sorted (in-order)
    2 - Array sorted but shuffled at 10%
    3 - Array complete shuffled (random numbers)
    4 - Array in reverse order.
				
You select each option by it's left-hand value:

	Algorithm List:
	1 - Insertion Sort 
	2 - Selection Sort
	3 - Bubble Sort 
	...
	...
	Select Algorithm: //Here you enter 1, 2, 3, etc.

Program can be run without menus:
 - Line 16 in main.cpp will run a specific operation with operations selected.
    - Options can be seen above in the menus.
