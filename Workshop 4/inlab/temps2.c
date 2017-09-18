//Name - Jatin Arora(136897162)
#include<stdio.h>

int main()
{
	int n,i;
	double s = 0.00;
	double mean;

	n = 0;
	printf("---=== IPC Temperature Analyzer V2.0 ===--- \n");
	printf("Please enter the number of days between 3 and 10, inclusive: ");
	scanf("%d", &n);
	while (n < 3 || n>10)
	{
		n = 0;
		s = 0.00;
		mean = 0.00;
		printf("\n Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &n);
	}


	int high[11];
	int low[11];
	printf("\n");
	for (i = 0; i < n; i++)
	{

		printf("Day %d – High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d – Low: ", i + 1);
		scanf("%d", &low[i]);

	}
	printf("\nDay  Hi  Low \n");
	for (int j = 0; j < n; j++)
	{
		printf("%d    %d    %d \n", j + 1, high[j], low[j]);
	}
	
		
		return 0;
	}

