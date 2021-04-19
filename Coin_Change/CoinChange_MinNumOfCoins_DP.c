#include<Stdio.h>

const int INF = 100000;

int min(int a,int b){
    return (a<b)?a:b;
}

int MinNumOfCoins(int coins[], int coinsSize, int amount){
  int result[amount+1];
  result[0] = 0;

  int i, j,minimum;
  
    for(i=1 ; i<=amount ; i++){
        result[i]=INF;
    }
    
    for(i=0 ; i<=amount ; i++){
        for(j=0 ; j<coinsSize ; j++){
            if(coins[j]<=i){
                result[i]=min( result[i] , (1+result[i-coins[j]]) );
            }
        }
    }
    return ( result[amount]>amount )?-1:result[amount];
}

int main(){
	int arr[] = {1, 2, 5, 10};
	int arrLen = sizeof(arr)/sizeof(arr[0]);
	printf("%d ", MinNumOfCoins(arr, arrLen, 48));
	return 0;
}
