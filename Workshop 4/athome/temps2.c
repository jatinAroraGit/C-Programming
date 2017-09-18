
//Name - Jatin Arora (136897162)
#include<stdio.h>

int main()
{
	int n, m, i, a;
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
	printf("Day  Hi  Low \n");
	for (int j = 0; j < n; j++)
	{
		printf("%d    %d    %d \n", j + 1, high[j], low[j]);
	}

	printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
	scanf("%d", &a);
	while (a>0)
	{
		s = 0.00;
		if (a <= n) {

			for (int t = 0; t < a; t++)
			{
				s = s + low[t] + high[t];

			}
			m = a * 2;
			mean = s / m;

			printf("\nAverage till day %d is : %.2lf \n\n", a, mean)
				;
		}
		else {
			printf("\nInvalid,");

			s = 0.00;
			mean = 0.00;
			m = 0;
		}
		printf("Enter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &a);
	}
	if (a < 0)
		printf("\n Goodbye! \n");
	return 0;
}

