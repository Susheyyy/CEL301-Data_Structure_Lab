#include<stdio.h>
#include<conio.h>
#define max 100

int stack[max];
int top = -1;

void push(int value)
{
	if(top == max-1)
	{
		printf("Stack Overflow. Cannot push %d\n", value);
	}
	else 
	{
		stack[++top]=value;
		printf("%d pushed to stack.\n", value);
	}
}

int pop()
{
	if (top == -1)
	{
		printf("Stack Underflow. Nothing to pop.\n");
        return -1;
	}
	else
	{
		return stack[top--];
	}
}

int peek()
{
	if (top == -1)
	{
		printf("Stack is Empty \n");
	}	
	else 
	{
		return stack[top];
	}
}
void display()
{ int i;
	if (top == -1)
	{
		printf("Stack is Empty \n");
	}
	else {
		printf("Stack Elements: ");
		for(i = 0; i <= top; i++)
		{
			printf("%d", stack[i]);
		}
		printf("\n");
	}
}

int main ()
{
	int choice, value;

do{
printf("Choices: \n 1.Push \n 2. POP \n 3.Peek \n 4. Display \n 5. Exit \n");
printf("Enter a choice: \n  ");
scanf("%d", &choice);
switch(choice)
{
	case 1:
		printf("Enter value to push: ");
		scanf("%d", &value);
		push(value);
		break;
		
	case 2:
		value = pop();
		if (value != -1)
		{
			printf("Popped Element: %d\n ", value);
		}
		break;
		
	case 3:
		value = peek();
		if (value != -1)
		{
        printf("Top element: %d\n", value);
    }
        break;
		
	case 4:
		display();
		break;
	 default:
       printf("Invalid choice. \n");
       
   }
}
while(choice !=5);
getch();
return 0;

}
