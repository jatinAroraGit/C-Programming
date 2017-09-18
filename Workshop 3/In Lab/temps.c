/*NAME- Jatin Arora
Seneca ID- 136897162
*/
#include<stdio.h>
#define nums 3

void main()
{
	printf("---=== IPC Temperature Calculator ===---\n");
	int low[3], high[3];
	double mean,s;
	
	s = 0.00;
	for (int i = 0; i <nums; i++)
	{

		printf("Enter The High Value for Day %d: ", i+1);
		scanf(" %d", &high[i]);
		printf("Enter The Low Value for Day %d: ", i+1);
		scanf(" %d", &low[i]);

		while (low[i] > high[i] || high[i] > 40 || low[i] < -40)
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low. \n");
			i = i--;
		
		}
	}
	for (int j = 0; j < nums; j++)
	{
		s = s + low[j] + high[j];
			}
	mean = s / 6;
		
	printf("The Average (mean) temperature was: %.2lf\n", mean);
}