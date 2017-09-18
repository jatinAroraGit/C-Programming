//Name-Jatin Arora(136897162)
#include<stdio.h>
#define distRate1  0.69			
#define distRate2  0.49			 

struct Rental {
	int id;
	double baseDay;
	double earnings;
};
double addPositive(double amount, double newAmount)
{
	double c = 0.00;
	if (newAmount>0)
	{
		c = amount + newAmount;
	}
	else
	{
		c = amount;
	}
	return c;
}
int main()
{


	struct Rental vRent[2];
	vRent[0].id = 123;
	vRent[0].baseDay = 9.95;
	vRent[0].earnings = 0;
	vRent[1].id = 124;
	vRent[1].baseDay = 19.95;
	vRent[1].earnings = 0;
	int ID;


	double  cost, costR, netCost, price, Total, s;
	int n = 100;
	int option, drive;
	int r = 0; int c, overhead, m;
	int flag = -1;
	int day;
	printf("***** Rental Vehicle Management App *****\n");
	do {
		printf("\n1.) Rental Status\n2.) Apply Charges\n0.) Log out \n\nPlease enter an option to continue: ");
		scanf("%d", &option);
		switch (option)
		{
		case 0:
		{
			r = 1;
			break;
		}
		case 1:
		{
			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#        Earnings\n-------- ----------\n");
			for (int j = 0; j<2; j++)
			{
				printf("%8d %10.2lf\n", vRent[j].id, vRent[j].earnings);
			}
			printf("\n");


			break;

			break;
		}
		case 2:
		{
			printf("\n-- Rental Charges -- \n\n");
			printf("Enter Vehicle id: ");
			scanf("%d", &ID);
			for (int i = 0; i < 2; i++)
			{
				
				if (ID == vRent[i].id)
				{
					flag = i;

					m = i;
				}
			}
			if (flag == -1) 
			{
				printf("ERROR: Vehicle ID does not exist.\n");
				
				break;
			}
			else
			if (flag != -1)
			{
				printf("Enter Rental Period (in Days): ");
				scanf("%d", &day);
				price = vRent[flag].baseDay*(double)day;

				printf("Enter kilometers driven: ");
				scanf("%d", &drive);




				if (drive < 100 && drive>0)
				{
					netCost = drive*distRate1;

				}
				if (drive > 100)
				{
					cost = (100 *distRate1);
					overhead = drive - n;
					costR = overhead*distRate2;
					netCost = cost + costR;

				}

			}
			Total = netCost + price;
			vRent[flag].earnings = Total;
			s = addPositive(price, netCost);
			printf("\nBase    kmCost  Total\n====== ======  ======\n");
			printf("%6.2lf  %6.2lf  %6.2lf \n ", price, netCost, s);
			flag = -1;
			break;
		}

		default:
		{
			printf("\nInvalid,Enter valid menu option\n");
			break;
		}
		}
	} while (r < 1);


}