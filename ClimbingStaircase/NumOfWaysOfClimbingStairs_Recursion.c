/*
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair 
or 2 stairs at a time. Count the number of ways, the person can reach the top.
*/

#include<stdio.h>

//ways(n) = ways(n-1) + ways(n-2) = FIBONACCI!!!!!!!!

int NumOfWays(int stairs){
	if(stairs<=1)
		return stairs;
	return ( NumOfWays(stairs-1) + NumOfWays(stairs-2) );
}

int main(){
	int numOfStairs;
	printf("Enter number of stairs :- ");
	scanf(" %d",&numOfStairs);
    printf("Number of ways = %d", NumOfWays(numOfStairs+1));
	return 0;
}
