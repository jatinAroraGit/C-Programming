/*NAME- Jatin Arora
Seneca ID- 136897162
*/
#include<stdio.h>
#define NUMS 4

int main()
{
	printf("---=== IPC Temperature Calculator ===---\n");
	int  low[4], high[4], Ht, Lt;
	double mean, s;
	int day, day2;
	s = 0.00;
	Ht = -41;
	Lt = 41;

	for (int i = 0; i < NUMS; i++)
	{

		printf("Enter The High Value for Day %d: ", i + 1);
		scanf(" %d", &high[i]);
		printf("Enter The Low Value for Day %d: ", i + 1);
		scanf(" %d", &low[i]);
		while (low[i] > high[i] || high[i] > 40 || low[i] < -40)
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low. \n");
			i = i--;


			break;
		}
	}
	for (int j = 0; j<NUMS; j++)
	{
		s = s + high[j] + low[j];
		if (high[j] > Ht)
		{
			Ht = high[j];
			day = j + 1;

		}
		if (low[j] < Lt)
		{
			Lt = low[j];
			day2 = j + 1;
		}
	}
	mean = s / 8;
	printf("The Average (mean) temperature was: %.2lf\n", mean);
	printf("Highest Temeprature was %d, on day %d\n", Ht, day);
	printf("Highest Temeprature was %d, on day %d\n", Lt, day2);
	return 0;
}