#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mynode
{
	char name[100];
	char gen[20];
	int age;
	struct mynode *link;
} Node;

Node *start = NULL;

void details(int);
int seat(int);
int cal(int, int, int);
void bill(int, int);
void add_node(char lol[100], char der[20], int b);

char source[100], des[100], train[40];
char station[40], cla[40];
int time1, time2, a[55];

void main()
{
	int i, j, a1, a2, b, c;
	int x = 0, d, e, r;
	char o;
	printf("Enter Number Of Passengers: ");
	fflush(stdin);
	scanf("%d", &j);

	details(j);
	printf("Enter The Source Place: ");
	fflush(stdin);
	gets(source);
	printf("Enter The Destination Place: ");
	gets(des);
	printf("The Following Trains Are Available.....\n");
	printf("1. Rajdhani Express.........10:00 a.m........Sealdah Station\n");
	printf("2. Satabdi Express..........05:00 p.m........Howrah Station\n");
	printf("3. Humsafar Express..........11:00 p.m........Kolkata Chitpur Station\n");
	printf("4. Garib-Rath Express.........05:00 p.m........Sealdah Station\n");
	printf("5. Duronto Express............07:00 a.m.........Santraganchi Station\n");
	scanf("%d", &i);
	do
	{
		switch (i)
		{
		case 1:
		{
			strcpy(train, "Rajdhani Express");
			strcpy(station, "Sealdah Station");
			time1 = 10;
			time2 = 00;
			a1 = 2099;
			a2 = 1560;

			d = cal(a1, a2, j);
			printf("Total Bill Amount: %d\n", d);
		};
		break;
		case 2:
		{
			strcpy(train, "Satabdi Express");
			strcpy(station, "Howrah Station");
			time1 = 05;
			time2 = 00;
			a1 = 1801;
			a2 = 981;

			d = cal(a1, a2, j);
			printf("Total Bill Amount: %d\n", d);
		};
		break;
		case 3:
		{
			strcpy(train, "Humsafar Express");
			strcpy(station, "Kolkata Chitpur Express");
			time1 = 11;
			time2 = 00;
			a1 = 2199;
			a2 = 1780;

			d = cal(a1, a2, j);
			printf("Total Bill Amount: %d\n", d);
		};
		break;
		case 4:
		{
			strcpy(train, "Garib-Rath Express");
			strcpy(station, "Sealdah Station");
			time1 = 05;
			time2 = 00;
			a1 = 1759;
			a2 = 1200;

			d = cal(a1, a2, j);
			printf("Total Bill Amount: %d\n", d);
		};
		break;
		case 5:
		{
			strcpy(train, "Duronto Express");
			strcpy(station, "Santraganchi Station");
			time1 = 07;
			time2 = 00;
			a1 = 2205;
			a2 = 1905;

			d = cal(a1, a2, j);
			printf("Total Bill Amount: %d\n", d);
		};
		break;
		default:
			printf("Enter Correct choice.....\n");
			x = 1;
			break;
		}
	} while (x);
	printf("Now Book Your Seats......\n");

	seat(j);

	bill(d, j);
}

int cal(int y1, int y2, int h)
{
	int b, c, i, t, r, n;
	printf("Enter Your Choice......\n");
	printf("1. Slepper Class....\n");
	printf("2. A.C Class.......\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
	{
		strcpy(cla, "Slepper Class");
		b = y2 * h;
		c = b + (b * 0.18);
	}
	break;
	case 2:
	{
		printf("Enter Your Choice....\n");
		printf("1. 3A Class....\n");
		printf("2. 2A Class....\n");
		printf("3. 1st Class A.C.....\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			strcpy(cla, "3A Class");
			b = y1 * h;
			c = b + (b * 0.18);
		}
		break;
		case 2:
		{
			strcpy(cla, "2A Class");
			b = (y1 + 1000) * h;
			c = b + (b * 0.18);
		}
		break;
		case 3:
		{
			strcpy(cla, "1st Class A.C.");
			b = (y1 + 5000) * h;
			c = b + (b * 0.18);
		}
		break;
		default:
		{
			printf("Enter Right Choice......\n");
		}
		}
	}
	break;
	default:
	{
		printf("Enter Right Choice......\n");
	}
	}
	return c;
}

void details(int k)
{
	int i, a;
	char val[100], gen[20];
	for (i = 1; i <= k; i++)
	{
		printf("Enter The %dth Passenger Name: ", i);
		fflush(stdin);
		scanf("%s", val);
		printf("Enter The %dth Passenger Gender: ", i);
		fflush(stdin);
		scanf("%s", gen);
		printf("Enter The %dth Passenger Age: ", i);
		fflush(stdin);
		scanf("%d", &a);

		add_node(val, gen, a);
	}
}

void add_node(char lol[100], char der[20], int b)
{
	Node *newptr = NULL, *ptr;
	newptr = (Node *)malloc(sizeof(Node));
	strcpy(newptr->name, lol);
	strcpy(newptr->gen, der);
	newptr->age = b;
	newptr->link = NULL;
	if (start == NULL)
		start = newptr;
	else
	{
		ptr = start;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = newptr;
	}
}

int seat(int p)
{
	int i;
	printf("\t-:SEAT MATRIX:-\t\n");
	printf("(U)    (M)        (L)    (L)    "
				 "    (U)\n\n");
	printf("01\t02\t03\t04\t05\n\n");
	printf("06\t07\t08\t09\t10\n");
	printf("11\t12\t13\t14\t15\n\n");
	printf("16\t17\t18\t19\t20\n");
	printf("21\t22\t23\t24\t25\n\n");
	printf("26\t27\t28\t29\t30\n");
	printf("31\t32\t33\t34\t35\n\n");
	printf("36\t37\t38\t39\t40\n");
	printf("41\t42\t43\t44\t45\n\n");
	printf("46\t47\t48\t49\t50\n");
	printf("51\t52\t53\t54\t55\n\n");
	printf("56\t57\t58\t59\t60\n");
	printf("Enter Seat Numbers: \n");
	for (i = 0; i < p; i++)
		scanf("%d", &a[i]);
}

// Function for printing receipt
void bill(int y, int j)
{
	int i;
	Node *ptr = start;
	FILE *fptr = fopen("bill.txt", "w");
	for (i = 1; i <= j; i++)
	{
		printf("%dst Passenger Name: %s\n", i, ptr->name);
		fprintf(fptr, "%dst Passenger Name: %s\n", i, ptr->name);
		printf("%dst Passenger Gender: %s\n", i, ptr->gen);
		fprintf(fptr, "%dst Passenger Gender: %s\n", i, ptr->gen);
		printf("%dst Passenger Age: %d\n\n", i, ptr->age);
		fprintf(fptr, "%dst Passenger Age: %d\n\n", i, ptr->age);
		ptr = ptr->link;
	}
	printf("Source Place: %s\n", source);
	fprintf(fptr, "Source Place: %s\n", source);
	printf("Destination Place: %s\n", des);
	fprintf(fptr, "Destination Place: %s\n", des);
	printf("The Boarding Station: %s\n", station);
	fprintf(fptr, "The Boarding Station: %s\n", station);
	printf("Train Is: %s\n", train);
	fprintf(fptr, "Train Is: %s\n", train);
	printf("Allocated Class: %s\n", cla);
	fprintf(fptr, "Allocated Class: %s\n", cla);
	printf("Boarding Time: %d:%d\n", time1, time2);
	fprintf(fptr, "Boarding Time: %d:%d\n", time1, time2);
	printf("Total Bill Amount: %d\n", y);
	fprintf(fptr, "Total Bill Amount: %d\n", y);
	printf("Allocated Seats Are: \n");
	fprintf(fptr, "Allocated Seats Are: \n");
	for (i = 0; i < j; i++)
	{
		printf("%d ", a[i]);
		fprintf(fptr, "%d ", a[i]);
	}
	printf("\n");
	fprintf(fptr, "\n");
	printf("Thank You......\n");
	fprintf(fptr, "Thank You......");
	fclose(fptr);
}