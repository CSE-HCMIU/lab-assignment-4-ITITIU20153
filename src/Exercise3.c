/*
3.	Input an array of n x n (n is even). Sort the first diagonal in
increasing order and the second diagonal in decreasing order.
First diagonal starts with element [0,0], second diagonal starts with elements [n-1,0]
Ex:
_________________________________________________________________
| Input: 4(edge) 10 21 12 53 64 53 86 72 68 99 10 11 12 13 14 15 |
| The converted 2D array will be like this:                      |
| 10 21 12 53                                                    |
| 64 53 86 72                                                    |
| 68 99 10 11                                                    |
| 12 13 14 15                                                    |
| Output:                                                        |
| 10 21 12 12                                                    |
| 64 10 53 72                                                    |
| 68 86 15 11                                                    |
| 99 13 14 53                                                    |
|________________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void Array2Dconverter(int arr[], int a[SIZE][SIZE], int m, int n)
{
	int row, column;
	int counter = 0;
	//Convert 1D array to 2D array
	for (row = 0; row <= (m - 1); row ++){
		for (column = 0; column <= (n - 1); column ++){
			a[row][column] = arr[counter];
			counter++;
		}
	}
}

void printArray(int a[SIZE][SIZE], int m, int n)
{
	int row, column;

	for (row = 0; row <= (m - 1); row ++){
		for (column = 0; column <= (n - 1); column ++){
			printf("%d ", a[row][column]);
		}
		printf("\n");
	}
}

void Ex3(int in_arr[], int n){
	int a[SIZE][SIZE];
	Array2Dconverter(in_arr,a,n,n);
	//Your codes here
	int count,count1,m=n-1;
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
	{
		if (a[i][i]>a[j][j]) 
		{
			count=a[i][i];
			a[i][i]=a[j][j];
			a[j][j]=count;
		}
	}
	}
	for (int i1=0;i1<n;i1++){
		for (int i2=i1+1;i2<n;i2++){
			if (a[i1][m-i1]>a[i2][m-i2])
			{
				count1=a[i1][m-i1];
				a[i1][m-i1]=a[i2][m-i2];
				a[i2][m-i2]=count1;
			}
		}
	}
	printArray(a,n,n);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	int edge = atoi(argv[1]);
	argc-=2;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+2]);
	}

	Ex3(testcase, edge);
	
	return 0;
}
