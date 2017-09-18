// Final Project Milestone 1
// Student defined values tester
// Version 1.0
// Date	2017/03/07
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the UI tools
// and Application User Interface for submission.
//
/////////////////////////////////////////////////////////////////
//NAME- JATIN ARORA (136897162)
/////////////////////////////////////////////////////////////////
#include <stdio.h>
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);

void welcome(void)
{
	printf(">---=== Grocery Inventory System ===---< \n\n");
}
void printTitle(void)
{
	printf(">Row | SKU | Name | Price | Taxed | Qty | Min | Total | Atn<\n>---- + -- - +-------------------- + -------- + ---- - +---- - +---- - +------------ |--\n");


}
void printFooter(double gTotal)
{
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0)
	{
		printf("                                           Grand Total: |     %lf<\n", gTotal);
	}
}
void flushKeyboard(void)
{
	while (getchar() != '\n');
}
void pause(void)
{
	printf("Press <ENTER> to continue... ");
	flushKeyboard();
}

int getInt(void)
{
	int k = 0;
	int Irt = 0;

	int num;
	char term;
	do
	{
		scanf("%d%c", &num, &term);
		if (term == '\n')
		{

			Irt = num;

			k = 1;
			break;
		}
		else
		{
			printf("Invalid integer, please try again: ");
			flushKeyboard();
		}

	} while (k == 0);
	return Irt;
}

double getDouble()
{
	int j = 0;
	double dVal, rt;
	char term;
	while (j == 0)
	{
		if (scanf("%lf%c", &dVal, &term) != 2 || term != '\n')
		{
			printf("Invalid number, please try again: ");
			flushKeyboard();
		}
		else
		{
			rt = dVal;

			j = 1;

		}
	}
	return rt;
}
int getIntLimited(int lowerLimit, int upperLimit)
{

	int chk, If; int z = 0;
	while (z == 0)
	{
		chk = getInt();
		if (chk > lowerLimit && chk < upperLimit)
		{
			z = 1;
			If = chk;


		}
		else
			printf("Invalid value, 10 < value < 20: ");

	}
	return If;
}
double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double ck, Df; int s = 0;
	while (s == 0) {
		ck = getDouble();
		if (ck > lowerLimit && ck < upperLimit)
		{
			Df = ck;


			s = 1;
		}
		else
			printf("Invalid value, 10.000000< value < 20.000000: ");


	}
	return Df;
}
int yes(void)
{

	int g = 0; int h;
	char opt;

	printf("Exit the program? (Y)es or (N)o : ");
	while (g == 0)
	{

		scanf("%c", &opt);
		if (opt == 'Y' || opt == 'y')
		{
			g = 1;
			h = 1;

		}
		else
			if (opt == 'n' || opt == 'N')
			{
				g = -1;
				h = 0;

			}
			else
			{
				printf("Only (Y)es or (N)o are acceptable: ");
				flushKeyboard();
			}
	}

	return h;
}
int main(void) {
	int iVal;
	double dVal;
	welcome();

	// uncommnet each tester as you complete the develpment of that section:

	//// testing printTitle()
	printf("listing header and footer with grand total:\n");
	printTitle();

	////---------------------------------------------------------------


	//// Testing printFooter()  

	printFooter(1234.5678);
	printf("listing header and footer without grand total:\n");
	printTitle();
	printFooter(-1);

	////---------------------------------------------------------------


	pause();
	////---------------------------------------------------------------


	//// Testing 

	printf("Enter an integer: ");
	iVal = getInt();
	printf("You entered: %d\n", iVal);
	////---------------------------------------------------------------


	//// Testing Get Int Limited 
	printf("Enter an integer between 10 and 20: ");
	iVal = getIntLimited(10, 20);
	printf("Your entered %d\n", iVal);
	////---------------------------------------------------------------


	//// Testing Get Double 
	printf("Enter a floating point number: ");
	dVal = getDouble();
	printf("You entered: %0.2lf\n", dVal);

	////---------------------------------------------------------------


	//// Tesing Get Double Limited 
	printf("Enter a floating point number between 10.00 and 20.00: ");
	dVal = getDoubleLimited(10.0, 20.0);
	printf("You entered: %0.2lf\n", dVal);
	////---------------------------------------------------------------

	printf("End of tester program for milestone one!\n\n");

	//// testing the App interface
	GroceryInventorySystem();
	////---------------------------------------------------------------


	return 0;
}
int menu(void)
{

	int x = 0, m; int p = 0;
	while (x == 0) {
		printf("1- List all items\n2 - Search by SKU\n3 - Checkout an item\n4 - Stock an item\n5 - Add new item or update item\n6 - delete item\n7 - Search by name\n0 - Exit program\n > ");
		scanf("%d", &m);
		if (m < 0 || m>7)
		{
			printf("Invalid value, 0 < value < 7: ");

		}
		else
		{
			p = m;
			x = 1;
		}
	}
	return p;
}

void GroceryInventorySystem(void)
{
	int l = 1;
	while (l == 1) {
		int option = menu();

		switch (option)
		{
		case 1:
		{
			printf("List Items under construction!\n");
			flushKeyboard();
			break;
		}
		case 2:
		{
			printf("Search Items under construction!\n");
			flushKeyboard();
			break;
		}
		case 3:
		{
			printf(">Checkout Item under construction!\n");
			flushKeyboard();
			break;
		}
		case 4:
		{
			printf("Stock Item under construction!<\n");
			flushKeyboard();
			break;
		}
		case 5:
		{
			printf("Add/Update Item under construction!\n");
			flushKeyboard();
			break;
		}
		case 6:
		{
			printf("Delete Item under construction!\n");
			flushKeyboard();
			break;
		}
		case 7:
		{
			printf("Search by name under construction!\n");
			flushKeyboard();
			break;
		}
		case 0:
		{
			int v;
			flushKeyboard();
			v = yes();
			if (v == 1)
			{
				l = 0;
				break;
			}
		}

		default:
		{

			break;
		}
		}
		if (l == 1)
		{
			pause();
			printf("\n");
		}
	}
}
