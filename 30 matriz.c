#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main ()
{
	int n,i,j,k;
	srand(time(NULL));
	printf("ingrese la longitud de la matriz: ");
	scanf("%d", &n);
	
	int A[n][n], B[n][n], C[n][n];
	printf("Matriz A:\n");
	for(i=0; i<n; i++)
	{
		for (j=0; j<n ;j++)
		{
			A[i][j]= rand()%10;
			printf ("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("Matriz B:\n");
	for(i=0; i<n; i++)
	{
		for (j=0; j<n ;j++)
		{
			B[i][j]= rand()%10;
			printf ("%d ", B[i][j]);
		}
		printf("\n");
	}
	printf("Matriz C:\n");
	int temporal;
	for(i=0; i<n; i++)
	{
		for (j=0; j<n ;j++)
		{
			temporal=0;
			for (k=0; k<n ;k++)
			{
				temporal += A[i][k] * B[k][j];
			}
			C[i][j] = temporal;
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	return 0;
}
