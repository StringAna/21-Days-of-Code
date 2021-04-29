/*Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total
 value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values
  and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find 
  out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You 
  cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
  */
#include<stdio.h>
int max(int a, int b) { return (a > b) ? a : b; } 

void knapsack(int c, int w[], int v[], int size) 
{ 
	int i, j; 
	int t[size+1][c+1]; 

	// Build table t[][] in bottom up manner 
	for (i = 0; i <= size; i++) { 
		for (j= 0; j<= c; j++) { 
			if (i == 0 || j == 0) 
				t[i][j] = 0; 
			else if (w[i - 1] <= j) 
				t[i][j] = max(v[i - 1] + 
					t[i - 1][j - w[i - 1]], t[i - 1][j]); 
			else
				t[i][j] = t[i - 1][j]; 
		} 
	} 
	//print the solution matrix
	//weird error ugh again
	/*for(i=1 ; i<=size ; i++){
		printf("\n%d	",w[i]);
		for(j=1 ; j<=c ; j++){
			printf("%d  ",t[i][j]);
		}
	}*/

	// stores the result of Knapsack 
	int result = t[size][c];	 
	printf("%d\n", result); 
	
	j = c; 
	for (i = size; i > 0 && result > 0; i--) { 
		
		// either the result comes from the top 
		// (K[i-1][w]) or from (val[i-1] + K[i-1] 
		// [w-wt[i-1]]) as in Knapsack table. If 
		// it comes from the latter one/ it means 
		// the item is included. 
		if (result == t[i - 1][j]) 
			continue;		 
		else { 

			// This item is included. 
			printf("%d ", w[i - 1]); 
			
			// Since this weight is included its 
			// value is deducted 
			result = result - v[i - 1]; 
			j = j - w[i - 1]; 
		} 
	} 
} 

int main(){
	int n,cap,i;
	printf("\nEnter number of weights : ");
	scanf("%d",&n);
	int wt[n],val[n];
	printf("\nEnter weights :\n");
	for(i=1 ; i<=n ; i++){
		scanf("\n%d",&wt[i]);
	}
	printf("\nEnter values :\n");
	for(i=1 ; i<=n ; i++){
		scanf("\n%d",&val[i]);
	}
	printf("\nEnter the capacity of knapsack : ");
	scanf("%d",&cap);
	//printf("\nn is %d ",sizeof(val)/sizeof(val[0])); n=4
	knapsack(cap,wt,val,n);
	return 0;
}
