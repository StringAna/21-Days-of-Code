#include<stdio.h>

int IsThereSubsetSum(int set[],int setSize,int sum){
	int table[setSize+1][sum+1],i,j;
	
	//if sum=0, then subset exists,so true(i.e , 1)
	for(i=0 ; i<=setSize ; i++)
		table[i][0]=1;
	
	//if setSize=0, and sum is not 0, then no subset exists,enter false. i.e, 0
	for(j=1 ; j<=sum ; j++)
		table[0][j]=0;
		
	//bottom up filling of table
	for(i=1 ; i<=setSize ; i++){
		for(j=1 ; j<=sum ; j++){
			//if sum<prevSetElement, then enter the value in previous row but same column([prevSetElement][currSum])
			if(j<set[i-1])
				table[i][j]=table[i-1][j];
			//if sum>=prevSetElement
			if(j>=set[i-1])
				table[i][j]=table[i-1][j] || table[i-1][j-set[i-1]];
		}
	}
	return table[setSize][sum];
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
