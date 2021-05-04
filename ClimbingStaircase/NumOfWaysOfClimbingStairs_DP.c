/*
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair 
or 2 stairs at a time. Count the number of ways, the person can reach the top.
*/

#include<stdio.h>

int NumOfWays(int nStairs,int nSteps){
	int i,j,ways[nStairs];
	ways[0]=1;
	ways[1]=1;
	
	for(i=2 ; i<nStairs ; i++){
		ways[i]=0;
		for(j=1 ; j<=nStairs && j<=nSteps ; j++)
			ways[i]+=ways[i-j];
	}
	return ways[nStairs-1];
}

int main(){
	int numOfStairs,steps=2;
	printf("Enter number of stairs :- ");
	scanf(" %d",&numOfStairs);
    printf("Number of ways = %d", NumOfWays(numOfStairs+1,steps));
	return 0;
}
