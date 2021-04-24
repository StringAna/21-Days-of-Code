#include<stdio.h>

int FindMax(int a,int b){
	return (a>b ? a:b);
}

int OptimalRodCut(int cost[],int costLen){
	int i,j,max_val,dpTable[costLen+1]; 
   
   	dpTable[0] = 0;
   	for (i = 1; i<=costLen ; i++)
   	{
       	int max_val = -1;
       	for (j = 0; j < i; j++)
         	max_val = FindMax(max_val, cost[j] + dpTable[i-j-1]);
       	dpTable[i] = max_val;
   	}
 
   return dpTable[costLen];
}

int main(){
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Value by cutting the rod is %d", OptimalRodCut(arr, size));
	return 0;
}
