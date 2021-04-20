#include<stdio.h>

int findMax(int a, int b){
	return (a>b ? a:b);
}

int findMin(int a, int b){
	return (a<b ? a:b);
}

int OSFG(int *arr,int size){
	int dp[size][size];
	
	//Solution lies at dp[0][size-1].
	//Table dp[][] is filled diagonally, as mentioned in https://www.youtube.com/watch?v=WRXCwgdni90
	//To follow the filling pattern, refer https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/
	
	int i,j,gap,x,y,z;
	
	for(gap=0 ; gap<size ; ++gap){
		for(i=0,j=gap ; j<size ; ++i,++j){
			/*
			The below code combines the following :- 
													1. Base cases
													2. Cases where i>j
													3. Calculates the value of those recursive thingies inside the main equation.
			*/
			x=((i+2) <= j) ? (dp[i+2][j]) : 0;
			y=((i+1) <= (j-1)) ? (dp[i+1][j-1]) : 0;
			z=(i <= (j-2)) ? (dp[i][j-2]) : 0;
			
			dp[i][j] = findMax( (arr[i] + findMin(x,y)) , (arr[j] + findMin(y,z)) );
		}
	}
	return dp[0][size-1];//solution
}

int main(){
	int n,i;
	
	printf("\nEnter the size of array :- ");
	scanf(" %d",&n);
	
	int a[n];
	
	printf("\nEnter elements in the array :- \n");
	for( i=0 ; i<n ; i++){
		scanf(" %d",&a[i]);	
	}
	
	printf("\nThe optimal value that can be obtained is %d\n",OSFG(a,n));
	
	return 0;
}
