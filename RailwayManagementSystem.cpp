#include <stdio.h>
#include <string.h>
struct Profile
{
	char sex;
    char name[50];
    int age, phno, passID;
    float cost;
}record[10];

int profile(int i )
{
			printf("\nPassenger %d :- \n", (i+1));
	    	printf("name : %s\n", record[i].name);
            printf("age and gender : %d %c\n", record[i].age, record[i].sex);
            printf("phone number %d\n", record[i].phno);
            printf("original cost of ticket : %f\n", record[i].cost);
            return 0;
}
float Discount(int i){
        	if(record[i].age >= 60)
            {
                if(record[i].sex == 'M')
                { return (0.40 * record[i].cost);}
                else
                {return (0.50 * record[i].cost);}
            }
            else if(record[i].age <= 12)
            {
			    if(record[i].age <= 5)
                {return (record[i].cost);}
                else
                {return (0.50 * record[i].cost);}
            }
            else
            {
			    return 0.00;
		    }
}
int Search()
{
	int search, c = -1, i;
	printf("Enter passenger ID number : \n");
	scanf("%d", &search);
	for(i=0;i<10;i++)
	{
		if(search == record[i].passID)
		{ c=i;
		  break;
		}
	}
	return c;
}
int E_ticket(int j)
{
            printf("\t\t\t\tRAILWAY MANAGEMENT\n\t\t\t\t (Domain based project)\n");
            printf("Passenger ID number : %d", record[j].passID);
            printf("Name : %s\n", record[j].name);
            printf("Age : %d\n", record[j].age);
            printf("Gender : %c\n", record[j].sex);
            printf("Final ticket cost : %f\n",(record[j].cost - Discount(j) ));	
            return 0;
}
int BalanceSheet()
{
	int *ptr;
	int i;
	float total;
	float *cptr;
	printf("\n\n\t RAILWAY ACCOUNT BALANCE SHEET\n");
	printf("\nSNo \tPASSENGER ID NUMBER \t TICKET COST \n\n");
	for(i=0; i<10; i++)
	{
		ptr = &record[i].passID;
		cptr = &record[i].cost - Discount(i);
		total = total + *cptr;
		printf ("%d.  \t\t %d \t\t %f\n", (i+1) , *ptr, *cptr);
	}
	printf("\n\nTOTAL AMOUNT : %f\n", total);
}
int main(){
	int i,j, ch;
	for( i=0; i<10; i++)
	{
	    	printf("Passenger ID number%d : ", (i+1));
		    scanf("%d", &record[i].passID);
            printf("Enter name%d: ", (i+1));
    		scanf("%s", record[i].name);
            printf("Enter age%d and gender%d : \n",(i+1) ,(i+1));
            scanf("%d %c", &record[i].age, &record[i].sex);
            printf("enter phone number%d\n",(i+1));
            scanf("%d", &record[i].phno);
            printf("Enter original cost of ticket%d : \n", (i+1));
            scanf("%f", &record[i].cost);
    }
    do
    {
    printf("\n\nENTER USER'S CHOICE : \n1. Passenger Profile \n2. Discount calculation. \n3.Search a Passenger ID number. \n4. e-ticket. \n5.Print Railway Balance Sheet \n6.Exit \n");
    scanf("%d", &ch);
    switch (ch)
    {
    	case 1 :
    		j = Search();
    		if(i>=0)
            i = profile(j);
            else
        	printf("Passenger ID NUMBER not found.\n");
            break;
        case 2 :
        	i = Search();
        	if(i>=0)
        	printf("\nDiscount for Passenger %d = %f\n",i+1, Discount(i));
        	else
        	printf("Passenger ID NUMBER not found.\n");
            break;
        case 3 :
        	i= Search();
        	if(i == -1)
	        {printf("Passenger ID NUMBER not found.\n");}
          	else
	        { printf("Passenger ID Number found at %d : %d\n", ++i, record[i].passID);}
	        break;
        case 4 :
        	i = Search();
        	if(i>=0)
        	j = E_ticket(i);
        	else
        	printf("Passenger ID NUMBER not found.\n");
            break;
        case 5 :
        	i = BalanceSheet();
        	break;
        case 6 :
		    printf("Thankyou");
            break;
        default : printf("Invalid Choice");
    }
    }while(ch < 6);
    return 0;
}

