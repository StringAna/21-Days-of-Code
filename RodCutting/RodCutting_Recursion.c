#include<stdio.h>

int FindMax(int a,int b){
	return (a>b ? a:b);
}

int OptimalRodCut(int cost[],int costLen){
	int i,max=-1;
	
	if(costLen<=0)
		return 0;
	
	
	for(i=0 ; i<costLen ; i++)
		max = FindMax(max , cost[i]+OptimalRodCut(cost,costLen-i-1));
	
	return max;
}

int main(){
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Value by cutting the rod is %d", OptimalRodCut(arr, size));
	return 0;
}
