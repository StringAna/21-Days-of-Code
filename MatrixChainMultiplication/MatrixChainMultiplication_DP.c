#include<stdio.h>

int FindMin(int a,int b){
	return (a<b ? a:b);
}

int MatrixChainMultiplication(int a[],int arrSize){
	int left,chainLength,right,partition,i,totalCost=0;
	int M[arrSize][arrSize]; //for simplicity M[n][n].0th row and 0th column is not used
	
	for(i=1 ; i<arrSize ; i++)
		M[i][i]=0;
	
	//subproblem size is from 2 to n-1
	for(chainLength=2 ; chainLength<=(arrSize-1) ; chainLength++) //chain length means size of subproblem
	{
		for(left=1 ; left<=(arrSize-left) ; left++){
			right=left+chainLength-1;
			M[left][right]=999;
			for(partition=left ; partition<right ; partition++){
				totalCost = M[left][partition] + M[partition+1][right] + (a[left-1]*a[partition]*a[right]);
				M[left][right]=FindMin(M[left][right],totalCost);
			}
		}
	}
	
	return M[1][arrSize-1];
}

int main()
{
    int arr[] = { 4,2,3,1,3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("Minimum number of multiplications is  %d\n",MatrixChainMultiplication(arr,n));
    
    return 0;
}
