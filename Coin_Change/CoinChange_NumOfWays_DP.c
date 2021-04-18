#include<stdio.h>

int WaysToMakeChange(int coins[],int size,int sum){
	int i,j;
	int table[size-1][sum];
	
	for (i=0 ; i<size ; i++){
		for(j=0 ; j<=sum ; j++){
			if(j==0)
				table[i][j]=1;
			else if(coins[i]>j)
				table[i][j]=table[i-1][j];
			else
				table[i][j]=table[i-1][j]+table[i][j-coins[i]];
		}
	}
	return table[size][sum];
}

int main(){
	int arr[] = {1,2,3};
	int arrLen = sizeof(arr)/sizeof(arr[0]);
	printf("%d ", WaysToMakeChange(arr, arrLen, 4));
	return 0;
}
