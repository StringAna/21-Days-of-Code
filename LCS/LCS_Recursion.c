#include <stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	return (a > b ? a : b);
}

int LCS(char *A, char *B, int indexOfA, int indexOfB)
{
	if (A[indexOfA] == '\0' || B[indexOfB] == '\0')
		return 0;

	else if (A[indexOfA] == B[indexOfB])
		return (1 + LCS(A, B, indexOfA + 1, indexOfB + 1));

	else
		return max(LCS(A, B, indexOfA + 1, indexOfB), LCS(A, B, indexOfA, indexOfB + 1));
}

int main()
{
	char A[]="bd";
	char B[]="abcd";

	printf("\nLength of Longest Common Subsequence is :- %d", LCS(A, B, 0, 0));

	return 0;
}
