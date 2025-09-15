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
        printf("Options: \n1.Insert \n2.Delete \n3.Display \n4.Exit\n");
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
                          

void insert() {
      int num;
      printf("\nEnter the number to be inserted in the queue:");
      scanf("%d",&num);
      if(rear == MAX -1) {
            printf("\nOverflow\n");
      } else {
            if(front ==-1 && rear ==-1) {
                  front =rear =0;
            } else {
                  rear++;
            }
            
      }
      queue[rear] = num;
}
int delete_element() {
    int val;
    if(front == -1 || front>rear){
             printf("\nUnderflow\n");
             return -1;
}

else{
     val = queue[front];
     front++;
     
     if(front>rear)
{
	     front = rear = -1; }
     return val;
     }
}

void display()
{
   for(int i = front; i<= rear; i++)
{
     printf("%d", queue[i]);
     }
     printf("\n");
}
     
     
