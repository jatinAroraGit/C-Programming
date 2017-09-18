//Name-Jatin Arora(136897162)
#include<stdio.h>
#define SIZE 2
struct employee
{
	int	id[3];
	int age[2];
	double sal[6];
	

};
int main()
{
	int a = 0;
	int r = 0;
	int n = 0;
	struct employee employee[SIZE];
	int option;
	printf("---=== EMPLOYEE DATA ===---\n");
	
	do {
		printf("\n1. Display Employee Information\n2. Add Employee\n0. Exit\n");
		printf("\nPlease select from the above options: ");
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
			printf("\nEMP ID  EMP AGE  EMP SALARY\n======  =======   ==========\n");


			for (int n = 0; n < a; n++)
			{
				printf("   %s       %s   %s \n", employee[n].id, employee[n].age,employee[n].sal);
			}

			break;
		}
		case 2:
		{
			if (a < SIZE) {
		
				printf("\nAdding Emoloyee\n===============\n");
				printf("Enter Employee ID: ");
				scanf("%s", &employee[a].id);
				
				printf("Enter Employee Age: ");
				scanf("%s", &employee[a].age);
				printf("Enter Employee Salary: ");
				scanf("%s", &employee[a].sal);
				a++;
			}
			else
			{
				printf("\nAdding Employee\n===============\nERROR!!!Maximum Number of Employees Reached\n");

			}
			break;
		}

		default:
		{
			printf("\nERROR: Incorrect Option: Try Again\n");
			break;

		}
		}
	} while (r<1);
	printf("\nExiting Employee Data Program. Good Bye!!!\n");
	return 0;
}