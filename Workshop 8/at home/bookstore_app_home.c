//Name - JATIN ARORA (136897162)  Workshop 8         HOME
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20



struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};
struct Book book[MAX_BOOKS] = { 0,0.0,00," ",0 };
struct Books *store = book;
void addBook(struct Book book[], int *size);
void displayInventory(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void checkPrice(const struct Book book[], const int size);
void menu();
int main()
{
	 //An array of Book representing the inventory
	const int size = 0;
	int p;
	p = size;

	printf("Welcome to the Book Store\n=========================\n");
	int opt;

	int g = 0;
	do
	{

		
		menu();
		printf("Select: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
		{


			displayInventory(store, p);
			break;
		}
		case 2:
		{

			addBook(store, p);
			p++;
			break;
		}
		case 3:
		{
			checkPrice(store, p);
			break;
		}
		case 0:
		{
			g = 1;
			break;
		}
		default:
		{
			printf("Invalid input, try again: \n\n");
			break;
		}

		}
	} while (g == 0);
	printf("Goodbye!\n");
	return 0;
}
void menu()
{
	printf("Please select from the following options:\n1) Display the inventory.\n2) Add a book to the inventory.\n3) Check price.\n0) Exit.\n\n");
}
void displayInventory(const struct Book book[], const int size)
{
	
	
	if (strcmp(book[size]._title, " ") == 0)
	{
		printf("The inventory is empty!\n===================================================\n");
	}
	else
	{
		printf("ISBN      Title               Year Price  Quantity\n-------- - +------------------ - +---- + ------ - +--------\n");
		int k = size;
		for (int j = 0; j < k; j++) {
			if(book[j]._year != 00)
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[j]._isbn, book[j]._title, book[j]._year, book[j]._price, book[j]._qty);
			
		}
		printf("===================================================\n\n");
	}
}
void addBook(struct Book book[], int *size)
{
	int isbn; int q; float y;
	int s = size;
	if (s == MAX_BOOKS)
	{
		printf("Inventory is full");
	}
	else
	{
		int x;
		printf("ISBN:");
		scanf("%d",&isbn);
		
		printf("Quantity:");
			scanf("%d",&q);
			x = searchInventory(store, isbn, s);
		if (x == -1) {
			book[s]._isbn = isbn;
			book[s]._qty = q;
			printf("Title:");
			fgets(book[s]._title, MAX_TITLE_SIZE, stdin);

			scanf("%[^\n]s", &book[s]._title);
			printf("Year:");
				scanf("%d", &book[s]._year);
			printf("Price:");
			scanf("%f",&y);
			book[s]._price = y;
			printf("The book is successfully added to the inventory.\n\n");
			
			s++;
		}
		else
		{
			printf("The book exists in the repository, quantity is updated.\n");
			book[x]._qty = book[x]._qty + q;
			
			
		}
		

	}
}
int searchInventory(const struct Book book[], const int isbn, const int size)
{
	int search = isbn; int r = 0; int h; int st;
	for (int d = 0; d < size; d++)
	{
		if (search == book[d]._isbn)
		{
			
			r = 1;
			
			st = d;
			
		}
	}
		if(r==0) {
			
			st = -1;
			
		}
		return st;
}
void checkPrice(const struct Book book[], const int size)
{
	int num, l;
	int h = size;
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &num);
	l = searchInventory(store, num, h);
	if (l == -1) {
		printf("\nBook does not exist in the bookstore! Please try again.\n");
	}
	else {
		printf("Book %d costs $%.2f\n\n",book[l]._isbn, book[l]._price);
	}
}