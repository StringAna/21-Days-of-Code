#include<stdio.h>
#include<stdlib.h>

int IsThereSubsetSum(int set[],int setSize,int sum){
	if(sum==0)
		return 1;
		
	if(setSize==0)
		return 0;
		
	return IsThereSubsetSum(set,setSize-1,sum-set[setSize-1]) || IsThereSubsetSum(set,setSize-1,sum);
}

int main(){
	int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (IsThereSubsetSum(set, n, sum) == 1)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
	return 0;
}
