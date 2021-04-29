#include<stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int cap,int weight[],int val[],int n){
	/*base
	*/
	if(n==0||cap==0)
		return 0;
		
	/*if current weight is more than capacity of knapsack, then this item won't be included
	*/
	if(weight[n-1]>cap)
		return knapSack(cap,weight,val,n-1);
	
	/*select max from  1) nth item included
					   2) nth item not included	
					   */
	else
		return max( (val[n-1]+knapSack(cap-weight[n-1],weight,val,n-1)) , (knapSack(cap,weight,val,n-1)) );
}

int main(){
	int values[] = { 60, 100, 120 };
    int weights[] = { 10, 20, 30 };
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);
    printf("%d", knapSack(capacity,weights,values,n));
	return 0;
}
