/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>


int path(int *maze, int *ref, int rows, int columns, int x1, int y1, int dest, int xtemp, int ytemp, int prev)
{


	
	if (xtemp + ytemp == dest && maze[xtemp + ytemp] == 1) return 1;



	if (maze[xtemp + 1 + ytemp] == 1 && ref[xtemp + 1 + ytemp] != -1 && prev != 3) 
        return path(maze, ref, rows, columns, x1, y1, dest, xtemp + 1, ytemp, 1);

	else if (xtemp + 1 + ytemp  < rows + columns)
	         ref[xtemp + 1 + ytemp] = -1; 



	if (maze[xtemp + ytemp + columns] == 1 && ref[xtemp + ytemp + columns] != -1 && prev != 4)
		return	path(maze, ref, rows, columns, x1, y1, dest, xtemp, ytemp + columns, 2);

	else if (xtemp + ytemp + columns < rows + columns)
	     ref[xtemp + ytemp + columns] = -1; 

	
	
	if (maze[xtemp + ytemp - 1] == 1 && ref[xtemp + ytemp - 1] != -1 && prev != 1)
    	return path(maze, ref, rows, columns, x1, y1, dest, xtemp - 1, ytemp, 3);

	else if (xtemp + ytemp - 1 >= 0)
	 ref[xtemp + ytemp - 1] = -1;




	if (maze[xtemp + ytemp - columns] == 1 && ref[xtemp + ytemp - columns] != -1 && prev != 2)
		return path(maze, ref, rows, columns, x1, y1, dest, xtemp, ytemp - columns, 4);

	else if (xtemp + ytemp - columns >= 0)
		ref[xtemp + ytemp - columns] = -1;
	




	if (x1 == xtemp && y1 == ytemp){
		return 0;
	}

	ref[xtemp + ytemp] = -1;
	return 0;

}





int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (x1 >= rows || y1 >= columns || x2 >= rows || y2 >= columns || rows<1 || columns <1)
		return 0;


	else{
		int *ref = (int *)calloc(rows*columns, sizeof(int));
		return path(maze, ref, rows, columns, x1, y1, x2*columns + y2, x1, y1, x1 + y1);
	}
}



