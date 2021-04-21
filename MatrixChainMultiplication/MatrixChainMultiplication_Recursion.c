#include<stdio.h>

int FindMin(int a,int b){
	return (a<b ? a:b);
}

int MatrixChainMultiplication(int dimensions[],int left,int right){
	if(left>=right)		//Bounds check
		return 0;
		
	int res,temp,k;
	
	res=999;
	
	for(k=left ; k<right ; k++){
		temp= MatrixChainMultiplication(dimensions,left,k)					//left
			+ MatrixChainMultiplication(dimensions,k+1,right)				//right
			+ (dimensions[left-1] * dimensions[k] * dimensions[right]);		//Cost
		
		res=FindMin(res,temp);
	}
	return res;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("Minimum number of multiplications is  %d\n",MatrixChainMultiplication(arr, 1, n-1));
    
    return 0;
}
