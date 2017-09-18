//Name - JATIN ARORA (136897162)  Workshop 8         LAB
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20
void searchInventory(const struct Book book[], const int isbn, const int size);


struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};
void addBook(struct Book book[], int *size);
void displayInventory(const struct Book book[], const int size);

void menu();
int main()
{
	struct Book book[MAX_BOOKS] = { 0,0.0,00," ",0 }; 
	const int size = 0;
	int a = size;
	int *p;
	p = &a;
	
	printf("Welcome to the Book Store\n=========================\n");
	int opt;

	int g = 0;
	do
	{
		
		struct Books *store = book;
		menu();
		printf("Select: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
		{


			displayInventory(store, *p);
			break;
		}
		case 2:
		{

			addBook(store,*p);
			a++;
			break;
		}
		case 3:
		{
			break;
		}
		case 0:
		{
			g =1;
			break;
		}
		default:
		{
			printf("Invalid input, try again: \n");
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
	
	if (strcmp(book[size]._title," ") == 0)
	{
		printf("The inventory is empty!\n===================================================\n\n");
	}
	else
	{
		int k = size;
		printf("Inventory\n===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n-------- - +------------------ - +---- + ------ - +--------\n");
		for (int j = 0; j < k; j++) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[j]._isbn, book[j]._title, book[j]._year, book[j]._price, book[j]._qty);
		}
		printf("===================================================\n");
	}
}
void addBook(struct Book book[], int *size)
{
	
	int s = size;  float p; int q;  char ttl[20];
	
	if (s == MAX_BOOKS)
	{
		printf("Inventory is full");
	}
	else
	{
		printf("ISBN:");
		scanf("%d", &book[s]._isbn);
		printf("Title:");




		fgets(book[s]._title , MAX_TITLE_SIZE , stdin);

		scanf("%[^\n]s", book[s]._title);
		
		
		
		
		printf("Year:");
		scanf("%d",&book[s]._year);
		printf("Price:");
		scanf("%f", &p);
		book[s]._price = p;
		printf("Quantity:");
		scanf("%d",&q);
		book[s]._qty = q;
		printf("The book is successfully added to the inventory.\n");
		s++;
		
	}
	}
