//MILESTONE 2
//Name - JATIN ARORA(136897162)

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define LINEAR 1
#define FORM 0


// Constant TAX value:

const double TAX = 0.13;


// Item structure:

struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};




// Function Prototypes Milestone 1:
// tools
void welcome(void);
void printTitle(void);
void printFooter(double grandTotal);
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

// code your functions here:
// Function Implementations Milestone 1:
void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n\n");
}

void printTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double grandTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (grandTotal > 0) {
		printf("\t\t\t\t\t   Grand Total: |%12.2lf\n", grandTotal);
	}
}

void flushKeyboard(void) {
	while (getchar() != '\n')
		;
}

void pause(void) {
	printf("Press <ENTER> to continue...");
	while (getchar() != '\n')
		;
}

int getInt(void) {
	int newInput;
	char lineDown;

	scanf("%d%c", &newInput, &lineDown);

	if (lineDown != '\n') {
		do {
			while (getchar() != '\n')
				;
			printf("Invalid integer, please try again: ");
			scanf("%d%c", &newInput, &lineDown);
		} while (lineDown != '\n');

	}

	return newInput;
}

int getIntLimited(int lowerLimit, int upperLimit) {
	int value;


	do {
		value = getInt();

		if (value < lowerLimit || value > upperLimit) {
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		}

	} while (value < lowerLimit || value > upperLimit);

	return value;
}

double getDouble(void) {
	double newInput;
	char lineDown;

	scanf("%lf%c", &newInput, &lineDown);

	if (lineDown != '\n') {
		do {
			while (getchar() != '\n')
				;
			printf("Invalid number, please try again: ");
			scanf("%lf%c", &newInput, &lineDown);
		} while (lineDown != '\n');

	}

	return newInput;

}

double getDoubleLimited(double lowerLimit, double upperLimit) {
	double number;

	do {
		number = getDouble();

		if (number < lowerLimit || number > upperLimit) {
			printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		}

	} while (number < lowerLimit || number > upperLimit);

	return number;
}


int yes(void) {
	char character = 'x';

	do {

		scanf("%c", &character);
		flushKeyboard();
		if (character != 'Y' && character != 'y' && character != 'N' && character != 'n') {
			printf("Only (Y)es or (N)o are acceptable: ");
		}

	} while (character != 'Y' && character != 'y' && character != 'N' && character != 'n');

	if (character == 'Y' || character == 'y') {
		return 1;
	}

	else {
		return 0;
	}
}

int menu(void) {
	int choice;

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");

	choice = getIntLimited(0, 7);

	return choice;
}

void GroceryInventorySystem(void) {
	int validInput = '\0';
	int yesInput = '\0';

	welcome();

	do {
		validInput = menu();

		switch (validInput) {
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			yesInput = yes();
			break;

		case 1:
			printf("List Items under construction!\n");
			pause();
			break;


		case 2:
			printf("Search Items under construction!\n");
			pause();
			break;


		case 3:
			printf("Checkout Item under construction!\n");
			pause();
			break;


		case 4:
			printf("Stock Item under construction!\n");
			pause();
			break;


		case 5:
			printf("Add/Update Item under construction!\n");
			pause();
			break;


		case 6:
			printf("Delete Item under construction!\n");
			pause();
			break;


		case 7:
			printf("Search by name under construction!\n");
			pause();
			break;



		}
	} while (yesInput != 1);

}













// Function Prototypes Milesone 2:


double totalAfterTax(struct Item item);

int isLowQuantity(struct Item item);

struct Item itemEntry(int sku);

void displayItem(struct Item item, int linear);

void listItems(const struct Item item[], int noOfItems);

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);



// Function Implementations Milestone 2:


double totalAfterTax(struct Item item) {
	double totalPrice = 0;
	if (item.isTaxed == 0) {
		totalPrice = item.price * item.quantity;
		return totalPrice;
	}

	else if (item.isTaxed == 1) {
		totalPrice = item.price * item.quantity;
		totalPrice = totalPrice + (totalPrice * TAX);
		item.isTaxed = 1;
		return totalPrice;
	}

}

int isLowQuantity(struct Item item) {
	if (item.quantity < item.minQuantity) {
		return 1;
	}

	else {
		return 0;
	}
}

struct Item itemEntry(int sku) {
	double price;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
	int ret;
	printf("        SKU: %d\n", sku);
	printf("       Name: ");
	scanf("%20[^\n]", &name);
	flushKeyboard();
	printf("      Price: ");
	price = getDouble();
	printf("   Quantity: ");
	quantity = getInt();
	printf("Minimum Qty: ");
	minQuantity = getInt();
	printf("   Is Taxed: ");
	ret= yes();
	if ("ret==0")
	{
		isTaxed = "NO";
	}
	else
		isTaxed = "YES";
}

void displayItem(struct Item item, int linear) {
	
	if (linear == 1) {
		if (item.quantity < item.minQuantity) {
			printf("|%3d|%20s|%8.2lf|%3c|%3d|%3d|%12.2lf|***\n", item.sku, item.name, item.price, item.isTaxed, item.quantity, item.minQuantity);
		}

		else if (item.quantity > item.minQuantity) {
			printf("|%3d|%20s|%8.2lf|%3c|%3d|%3d|%12.2lf|\n", item.sku, item.name, item.price, item.isTaxed, item.quantity, item.minQuantity);
		}
	}

	else if (linear == 0) {
		if (item.quantity < item.minQuantity) {
			printf("        SKU: %d\n", item.sku);
			printf("       Name: \n", item.name);
			printf("      Price: \n", item.price);
			printf("   Quantity: \n", item.quantity);
			printf("Minimum Qty: \n", item.minQuantity);
			printf("   Is Taxed: \n", item.isTaxed);
			printf("WARNING: Quantity low, please order ASAP!!!");
		}

		else if (item.quantity > item.minQuantity) {
			printf("        SKU: %d\n", item.sku);
			printf("       Name: \n", item.name);
			printf("      Price: \n", item.price);
			printf("   Quantity: \n", item.quantity);
			printf("Minimum Qty: \n", item.minQuantity);
			printf("   Is Taxed: \n", item.isTaxed);
		}
	}
}


int main() {

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


	struct Item I[21] = {
		{ 4.4,275,0,10,2,"Royal Apples" },
		{ 5.99,386,0,20,4,"Watermelon" },
		{ 3.99,240,0,30,5,"Blueberries" },
		{ 10.56,916,0,20,3,"Seedless Grapes" },
		{ 2.5,385,0,5,2,"Pomegranate" },
		{ 0.44,495,0,100,30,"Banana" },
		{ 0.5,316,0,123,10,"Kiwifruit" },
		{ 4.49,355,1,20,5,"Chicken Alfredo" },
		{ 5.49,846,1,3,5,"Veal Parmigiana" },
		{ 5.29,359,1,40,5,"Beffsteak Pie" },
		{ 4.79,127,1,30,3,"Curry Checken" },
		{ 16.99,238,1,10,2,"Tide Detergent" },
		{ 10.49,324,1,40,5,"Tide Liq. Pods" },
		{ 10.99,491,1,50,5,"Tide Powder Det." },
		{ 3.69,538,1,1,5,"Lays Chips S&V" },
		{ 3.29,649,1,15,5,"Joe Org Chips" },
		{ 1.79,731,1,100,10,"Allen's Apple Juice" },
		{ 6.69,984,1,30,3,"Coke 24 Pack" },
		{ 7.29,350,1,50,5,"Nestea 24 Pack" },
		{ 6.49,835,1,20,2,"7up 24 pack" }
	};
	double val;
	int ival;
	int searchIndex;
	val = totalAfterTax(I[0]);
	printf("totalAfterTax:\n"
		"    yours=%lf\n"
		"program's=44.000000\n", val);
	val = totalAfterTax(I[7]);
	printf("totalAfterTax:\n"
		"    yours=%lf\n"
		"program's=101.474000\n", val);
	ival = isLowQuantity(I[0]);
	printf("isLowQuantity:\n"
		"    yours=%d\n"
		"program's=0\n", ival);
	ival = isLowQuantity(I[14]);
	printf("isLowQuantity:\n"
		"    yours=%d\n"
		"program's=1\n", ival);
	pause();

	printf("itemEntry, enter the following values:\n");
	printf("        SKU: 999\n"
		"       Name: Red Apples\n"
		"      Price: 4.54\n"
		"   Quantity: 50\n"
		"Minimum Qty: 5\n"
		"   Is Taxed: n\n");
	printf("Enter the values:\n");
	I[20] = itemEntry(999);
	printf("displayItem, Linear:\nYours: ");
	displayItem(I[20], LINEAR);
	printf(" Prog: |999|Red Apples          |    4.54|   No|  50 |   5 |      227.00|\n");
	printf("displayItem, Form:\nYours:\n");
	displayItem(I[20], FORM);
	printf("Programs: \n");
	printf("        SKU: 999\n"
		"       Name: Red Apples\n"
		"      Price: 4.54\n"
		"   Quantity: 50\n"
		"Minimum Qty: 5\n"
		"   Is Taxed: No\n");
	I[20].quantity = 2;
	I[20].isTaxed = 1;
	pause();

	printf("displayItem, Linear with low value and taxed:\nYours: ");
	displayItem(I[20], LINEAR);
	printf(" Prog: |999|Red Apples          |    4.54|  Yes|   2 |   5 |       10.26|***\n");
	printf("displayItem, Form with low value:\nYours:\n");
	displayItem(I[20], FORM);
	printf("Programs: \n");
	printf("        SKU: 999\n"
		"       Name: Red Apples\n"
		"      Price: 4.54\n"
		"   Quantity: 2\n"
		"Minimum Qty: 5\n"
		"   Is Taxed: Yes\n"
		"WARNING: Quantity low, please order ASAP!!!\n");
	pause();

	printf("Listing Items: \n");
	listItems(I, 21);
	pause();
	printf("Locate Item, successful search:\n");
	printf("program: Found the item 999 at index: 20\n");
	printf("  Yours: ");
	if (locateItem(I, 21, 999, &searchIndex)) {
		printf("Found the item 999 at index: %d\n", searchIndex);
	}
	else {
		printf("No item with the sku 999 is in the array!\n");
	}

	printf("Locae Item, unsuccessful search:\n");
	printf("Progam: No item with the sku 732 is in the array!\n");
	printf(" Yours: ");
	if (locateItem(I, 21, 732, &searchIndex)) {
		printf("Found the item at index: %d\n", searchIndex);
	}
	else {
		printf("No item with the sku 732 is in the array!\n");
	}
	return 0;
}
void listItems(const struct Item item[], int NoOfItems)
{
	int count = 0;
	double gTotal = 0;
	printTitle();
	while (count < NoOfItems)
	{
		gTotal = gTotal + totalAfterTax(item[count]);
		printf("%4d", count + 1);
		displayItem(item[count], LINEAR);
		count++;
	}
	printFooter(gTotal);
}
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int count = 0, temp = 0;
	while (count < NoOfRecs)
	{
		//printf("\nsku at index: %d is: %d", count, item[count].sku);
		if (item[count].sku == sku)
		{
			*index = count;
			temp = 1;

		}

		count++;
	}
	return temp;
}
