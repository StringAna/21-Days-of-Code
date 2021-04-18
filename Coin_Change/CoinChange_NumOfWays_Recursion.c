#include<stdio.h>

// Returns the number of ways we can sum arr[0...len-1] coins to get sum of "sum"
int WaysToMakeChange( int arr[], int len, int sum )
{
	// if sizeOfCoins is 0, it means there are no coins in the Coins array
	// So, there is 1 solution, which is :-  we don't include any coin
	if (sum == 0)
		return 1;
	
	// If n is less than 0 then no solution is there,so 0
	if (sum < 0)
		return 0;

	// if no coins exist and sum is >1
	if (len <=0 && sum >= 1)
		return 0;

	// sum of solutions by
	//					1) including the coin at coins[sizeOfCoins-1]
	//					2) excluding the coin at coins[sizeOfCoins-1]
	
	return WaysToMakeChange( arr, len - 1, sum ) + WaysToMakeChange( arr, len, sum-arr[len-1] );
}

int main()
{
	int i, j;
	int arr[] = {1, 2, 3};
	int arrLen = sizeof(arr)/sizeof(arr[0]);
	printf("%d ", WaysToMakeChange(arr, arrLen, 4));
	return 0;
}

