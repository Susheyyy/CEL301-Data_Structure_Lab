#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 

struct node 
    { 
         int data; 
        struct node *next; 
    }; 

struct node *top = NULL; 
struct node *push(struct node *, int); 
struct node *display(struct node *); 
struct node *pop(struct node *); 
int peek(struct node *); 

int main()   
    { 
        int val, option; 
        do 
            { 
                printf("\n 1. PUSH"); 
                printf("\n 2. POP"); 
                printf("\n 3. PEEK"); 
                printf("\n 4. DISPLAY"); 
                printf("\n 5. EXIT"); 
                printf("\n Enter your option: "); 
                scanf("%d", &option); 

                switch(option) 
                    { 
                        case 1: 
                        printf("\n Enter the number to be pushed on stack: "); 
                        scanf("%d", &val); 
                        top = push(top, val); 
                        break; 

                        case 2: 
                        top = pop(top); 
                        break; 

                        case 3: 
                        val = peek(top); 
                        if (val != -1) 
                        printf("\n The value at the top of stack is: %d", val); 
                        else 
                        printf("\n STACK IS EMPTY"); 
                        break; 

                        case 4: 
                        top = display(top); 
                        break; 
                     } 
                }

                while(option != 5); 
                return 0; 
} 

struct node *push(struct node *top, int val) 
{ 
    struct node *new_node; 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node -> data = val; 
    if(top == NULL) 
        { 
            new_node -> next = NULL; 
            top = new_node; 
        } 
    else 
        { 
            new_node -> next = top; 
            top = new_node; 
        } 
    return top; 
} 

struct node *display(struct node *top) 
{ 
    struct node *ptr; 
    ptr = top; 
    if(top == NULL) 
        printf("\n STACK IS EMPTY"); 
    else 
        { 
            while(ptr != NULL) 
                { 
                    printf("\n %d", ptr -> data); 
                    ptr = ptr -> next; 
                } 
        } 
    return top; 
} 

struct node *pop(struct node *top) 
{ 
    struct node *ptr; 
    ptr = top; 
    if(top == NULL) 
        printf("\n STACK UNDERFLOW"); 
    else 
    { 
        top = top -> next; 
        printf("\n The value being deleted is: %d", ptr -> data); 
        free(ptr); 
    } 
    return top; 
} 

int peek(struct node *top) 
{ 
    if(top==NULL) 
        return -1; 
    else 
        return top ->data; 
} 

 