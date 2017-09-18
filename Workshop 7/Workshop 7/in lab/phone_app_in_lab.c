//Name- JATIN ARORA(136897162)

#include<stdio.h>
#define SIZE 3

void decompose(long long phonenumbers, int *area, int *prefix, int *lineno) {
	*area = (int)(phonenumbers / (10000000));
	*prefix = (int)((phonenumbers % (10000000) / 10000));
	*lineno = (int)(phonenumbers % (10000));
}



int main()
{
	int area, prefix, lineno; long long int n = 0LL;
	int f = 0;  int k = 0; int a = 0;
	int option;
	long long int number;
	long long int phonenumbers[SIZE];
	phonenumbers[0] = 0LL;
	phonenumbers[1] = 0LL;
	phonenumbers[2] = 0LL;

	printf("---=== Phone Numbers ===---\n\n");
	while (f == 0)
	{
		printf("1. Display Phone List\n2. Add a Number\n0. Exit\n\nPlease select from the above options : ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
		{
			printf("\nPhone Numbers\n==============\n");
			for (int n = 0; n < SIZE; n++)
			{
				if (phonenumbers[n] != 0LL)
				{

					decompose(phonenumbers[n], &area, &prefix, &lineno);
					printf("(%3d)-%3d-%4d \n", area, prefix, lineno);
				}


			}
			printf("\n");
			break;
		}

		case 2:
		{
			if (a < SIZE)
			{
				printf("\nAdd a Number\n============\n");
				scanf("%d", &phonenumbers[k]);
				printf("\n");
				k++;
				a++;
				break;
			}
			else
			{
				printf("ERROR!!! Phone Number List is Full\n\n");
				break;
			}
		}
		case 0:
		{
			f = 1;
			break;
		}
		default:
		{
			printf("ERROR!!!: Incorrect Option: Try Again\n\n");
			break;
		}
		}
	}
	printf("\nExiting Phone Number App. Good Bye!!!\n");
	return 0;
}

