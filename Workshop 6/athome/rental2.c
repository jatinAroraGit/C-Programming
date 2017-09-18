//Name-JATIN ARORA(136897162)
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
double taxCalc(double price, double rate)
{
	double tax = price*(rate / 100);
	double sT = price + tax;
	return sT;
}
double subtractPositve(double amount, double newAmount)
{
	double t = 0.00;
	if (newAmount > 0)
	{
		t = newAmount - amount;
	}
	else
		t = amount;
	return t;
}
int main()
{


	struct Rental vRent[3];
	vRent[0].id = 123;
	vRent[0].baseDay = 9.95;
	vRent[0].earnings = 0.00;
	vRent[1].id = 124;
	vRent[1].baseDay = 19.95;
	vRent[1].earnings = 0;
	vRent[2].id = 125;
	vRent[2].baseDay = 29.95;
	vRent[2].earnings = 0.00;
	int ID, e;
	char ch;
	double discount = 5.00;
	double taxed, gift, diff;

	double cost, costR, netCost, price, Total, s;
	int n = 100;
	int option, drive;
	int r = 0; int overhead, m;
	int flag = -1;
	int day;
	printf("***** Rental Vehicle Management App *****\n");
	do {
		printf("\n1.) Rental Status\n2.) Apply Charges\n3.) Apply Taxes to All Rentals\n4.) Apply Gift Card\n0.) Log out\n\nPlease enter an option to continue: ");
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
			printf("ID#      Earnings\n-------- ----------\n");
			for (int j = 0; j < 3; j++)
			{
				printf("%8d %10.2lf\n", vRent[j].id, vRent[j].earnings);
			}
			printf("\n");


			break;

			break;
		}
		case 2:
		{
			printf("\n-- Rental Charges --\n\n");
			printf("Enter Vehicle id: ");
			scanf("%d", &ID);
			for (int i = 0; i < 3; i++)
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
						cost = (100 * distRate1);
						overhead = drive - n;
						costR = overhead*distRate2;
						netCost = cost + costR;

					}

				}
			Total = netCost + price;

			printf("Apply Discount: ");
			scanf(" %c", &ch);

			if (ch == 'Y' || ch=='y')
			{

				s = subtractPositve(discount, Total);
				vRent[flag].earnings = s;
			}
			else
			{
				s = addPositive(price, netCost);
				vRent[flag].earnings = s;

			}
			double discount = price + netCost - s;


			printf("\nBase   kmCost   DiscStatus  Total\n====== ======   ==========  ======\n");
			printf("%6.2lf  %6.2lf %10c  %6.2lf \n", price, netCost, ch, s);
			flag = -1;
			break;
		}

		case 3:
		{
			printf("\n-- Apply Taxes To all Accounts--\n\n");
			printf("ID#      Earnings      Taxes\n-------- ----------   ------\n");
			for (int g = 0; g < 3; g++)
			{
				taxed = taxCalc(vRent[g].earnings, 14);
				diff = taxed - vRent[g].earnings;
				vRent[g].earnings = taxed;
				printf("%8d %10.2lf%10.2lf\n", vRent[g].id, vRent[g].earnings, diff);
			}
			break;
		}
		case 4:
		{
			flag = -1;
			printf("\n-- Apply Gift Card --\n\n");
			printf("Enter Vehicle ID: ");
			scanf("%d", &e);
			for (int k = 0; k < 3; k++)
			{
				if (e == vRent[k].id)
				{
					flag = k;
				}
			}
			if (flag != -1)
			{
				printf("Enter Gift Card Amount: ");
				scanf("%lf", &gift);
				s = subtractPositve(gift, vRent[flag].earnings);
				vRent[flag].earnings = s;
				printf("Discount Applied");
			}
			break;
		}
		default:
		{
			printf("\nInvalid,Select option from menu\n");
			break;
		}
		}
	} while (r < 1);

}

