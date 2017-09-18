//Name-Jatin Arora(136897162)
#include<stdio.h>
#define SIZE 4
struct employee
{
	int	id[10];
	int age[3];
	double sal[7];


};
int main()
{
	double nS[10];
	int ID[10];
	int eID[10];
	int a = 0;
	int r = 0;
	int n = 0;
	int x = 0;
	int f = 0;
	struct employee employee[SIZE];
	int options;
	printf("---=== EMPLOYEE DATA ===---\n");

	do {
		printf("\n1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\n");
		printf("\nPlease select from the above options: ");
		scanf("%d", &options);

		switch (options)
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
				if (strcmp(employee[n].id, "") == 1)
					printf("   %s       %s   %s \n", employee[n].id, employee[n].age, employee[n].sal);
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
		case 3:
		{
			do
			{
				printf("Update Employee Salary \n======================\n");
				printf("Enter Employee ID : ");
				scanf("%s", &ID);
				for (int j = 0; j < SIZE; j++)
				{
					if (strcmp(ID, employee[j].id) == 0)
					{
						printf("The current salary is %s", employee[j].sal);
						printf("Enter new Salary:");
						scanf("%s", &nS);
						strcpy(employee[j].sal, nS);
						x = 1;
					}
				}

			} while (x < 1);
			break;
		}
		case 4:
		{
			do
			{
				printf("\nRemove Employee\n===============\n");
				printf("Enter Employee ID :");
				scanf("%s", &eID);
				for (int c = 0; c < SIZE; c++)
				{
					if (strcmp(eID, employee[c].id) == 0)
					{
						printf("Employer with ID %s will be removed", eID);
						strcpy(employee[c].id, "");
						strcpy(employee[c].age, "");
						strcpy(employee[c].sal, "");
						a--;
						f = 1;

					}

				}
			} while (f < 1);
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