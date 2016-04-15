/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int index = 0;
int back = -1, up = 0;

void spiralArray(int rows, int columns, int **input_array, int *arr, int tRows, int tCols, int direction, int mIndex)
{
	if (index == mIndex + 1) return;

	arr[index++] = input_array[tRows][tCols];

	if (direction == 1 && tCols<columns - 1)
	{
		spiralArray(rows, columns, input_array, arr, tRows, tCols + 1, direction, mIndex);
	}
	else if (direction == 1)
	{
		columns--;
		spiralArray(rows, columns, input_array, arr, tRows + 1, tCols, 2, mIndex);

	}

	if (direction == 2 && tRows<rows - 1)
	{
		spiralArray(rows, columns, input_array, arr, tRows + 1, tCols, direction, mIndex);
	}
	else if (direction == 2)
	{
		rows--;
		spiralArray(rows, columns, input_array, arr, tRows, tCols - 1, 3, mIndex);
	}
	if (direction == 3 && back + 1<tCols)
	{
		spiralArray(rows, columns, input_array, arr, tRows, tCols - 1, direction, mIndex);
	}
	else if (direction == 3)
	{
		back++;
		spiralArray(rows, columns, input_array, arr, tRows - 1, tCols, 4, mIndex);
	}

	if (direction == 4 && up + 1<tRows)
	{
		spiralArray(rows, columns, input_array, arr, tRows - 1, tCols, direction, mIndex);
	}
	else if (direction == 4)
	{
		up++;
		spiralArray(rows, columns, input_array, arr, tRows, tCols + 1, 1, mIndex);
	}


}





int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows < 1 || columns < 1)
		return NULL;

	else
	{
		index = 0, back = -1, up = 0;
		int *arr = (int *)calloc(rows*columns, sizeof(int));
		spiralArray(rows, columns, input_array, arr, 0, 0, 1, (rows*columns) - 1);
		return arr;
	}


}

