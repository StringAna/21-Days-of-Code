#include<stdio.h>

int FindMax(int a,int b){
	return (a>b ? a:b);
}

int EggDrop(int numOfEggs,int numOfFloors){
	int result,i,min=999;
	// if no floors,then no trials needed
	//if 1 floor, then only 1 try is needed.Thus,return num of floors
	if(numOfFloors==1 || numOfFloors==0)
		return numOfFloors;
		
	//if there is 1 egg, then we need to test all floors with that egg at worst case
	if(numOfEggs==1)
		return numOfFloors;
		
	for(i=1 ; i<=numOfFloors ; i++){
		result = FindMax( EggDrop(numOfEggs-1,i-1) , EggDrop(numOfEggs,numOfFloors-i) );
		if(result<min)
			min=result;
	}
	return min+1;
	
}

int main()
{
    int eggs = 2, floors = 10;
    int final = EggDrop(eggs,floors);
    printf("Minimum number of trials in worst case with %d eggs and %d floors is %d",eggs,floors,final);
    return 0;
}
