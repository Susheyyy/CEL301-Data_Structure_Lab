#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1;
void insert();
int delete_element();
void display(void);

int main()
{
    int option, val;
    do 
    {
        printf("\nOptions: \n1.Insert \n2.Delete \n3.Display\n4.Exit\n");
        printf("\nEnter an option: ");
        scanf("%d", &option);
        
        switch(option)
        {
                      case 1:
                            insert();
                            break;
                      case 2:
                           delete_element();
                           break;
                           
                     case 3:
                     	   display();
                     	   break;

        }      
    }
                      while(option!= 4);
                      getch();
                          
}

void insert()
	{
		int num;
		printf("\nEnter the number to be inserted in the queue : ");
		scanf("%d", &num);
		
			if((front==0 && rear==MAX-1) || (front == rear+1))
			{
				printf("\nOVERFLOW\n");
		}
				
			else if(front==-1 && rear==-1)
				{
					front=rear=0;
					queue[rear]=num;
				}
			else if(rear==MAX-1 && front!=0)
				{
					rear=0;
					queue[rear]=num;
				}
			else
				{
					rear++;
					queue[rear]=num;
					printf("Inserted %d \n", num);
				}
	}
	
int delete_element()
	{	
		int val;
		if(front == -1 && rear == -1 )
			{
				printf("\nUnderflow \n");
				return -1;
			}
		val = queue[front];
		if(front == rear)
			{
			front = rear =-1;
			}
		else
		{
			if(front == MAX -1)
			   front = 0;
			else 
				front++;
		}
		return val;
	}
	
void display()
{
	if(front== -1)
	{
		printf("\nUNDERFLOW\n");
	}
	if(front <= rear)
	{
   for(int i = front; i<= rear; i++)
{
     printf("%d", queue[i]);
     }
     printf("\n");
 }
 else 
 {
 	for(int i = front; i<= MAX-1; i++)
 	{
 		printf("%d", queue[i]);
	 }
	 for(int i = 0; i<= rear; i++)
	 {
	 	printf("%d", queue[i]);
	 }
 }
}


