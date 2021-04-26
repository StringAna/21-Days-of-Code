#include<stdio.h>

int FindMax(int a,int b){
	return (a>b ? a:b);
}

int eggDrop(int n, int k)
{
    int table[n + 1][k + 1];
    int res;
    int i, j, x;
 
    for (i = 1; i <= n; i++) {
        table[i][1] = 1;
        table[i][0] = 0;
    }
 
    for (j = 1; j <= k; j++)
        table[1][j] = j;
 
    for (i = 2; i <= n; i++) {
        for (j = 2; j <= k; j++) {
            table[i][j] = 999;
            for (x = 1; x <= j; x++) {
                res = 1 + FindMax(
                              table[i - 1][x - 1],
                              table[i][j - x]);
                if (res < table[i][j])
                    table[i][j] = res;
            }
        }
    }
    return table[n][k];
}
int main()
{
    int eggs = 2, floors = 10;
    int final = eggDrop(eggs,floors);
    printf("Minimum number of trials in worst case with %d eggs and %d floors is %d",eggs,floors,final);
    return 0;
}
