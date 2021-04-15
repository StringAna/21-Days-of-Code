#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b)
{
    return (a > b)? a : b;
}

int LCS( char *A, char *B, int lenA, int lenB )
{
   int table[lenA][lenB];
   int i, j;
   
   for (i=0; i<=lenA; i++)
   {
     for (j=0; j<=lenB; j++)
     {
       if (i == 0 || j == 0)
         table[i][j] = 0;
   
       else if (A[i] == B[j])
         table[i][j] = table[i-1][j-1] + 1;
   
       else
         table[i][j] = max(table[i-1][j], table[i][j-1]);
     }
   }
     
   return table[lenA][lenB];
}
 

int main()
{
  char A[] = "bd";
  char B[] = "abcd";
   
  int alen = strlen(A);
  int blen = strlen(B);
   
  printf("Length of LCS is %d", LCS( A, B, alen, blen ) );
  
  return 0;
}
