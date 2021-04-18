#include<stdio.h>
#include<stdlib.h>
int LIS(int arr[],int arrLen){
	int lis[arrLen];
	lis[0]=1;
	
	int i,j,max=0;
	
	for(i=1 ; i<arrLen ; i++){
		lis[i]=1;
		for(j=0 ; j<i ; j++){
			if(arr[i]>arr[j] && lis[i]<=lis[j]){
				lis[i]=1+lis[j];
				if(max<lis[i]){
					max=lis[i];
				}
			}
		}
	}
	return max;
}

int main(){
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Length of longest increasing subsequence is %d\n", LIS( arr, n ) ); 
	return 0;
}
