#include <stdio.h>
#include<ctype.h>
#include<conio.h>
#define Max 50

char stack[Max];
int top = -1;

int precedence(char x){
	if(x=='(')
	{
		return 0;
	}
	else if(x=='+' || x=='-'){
		return 1;
	}
	else if(x=='*'||x=='/'){
		return 2;
	}
	else if(x=='^'){
		return 3;
	}
	return -1;
}

void push(char x) {
    if (top == Max - 1) {
      //  printf("\nStack is full\n");
    } else {
        top++;
        stack[top] = x;
      // printf("%d Character is Pushed\n", x);
    }
}

char pop() {
    if (top == -1) {
      // printf("\nStack is empty\n");
        return -1;
    } else {
        char x = stack[top];
        top--;
       // printf("%d Character is Popped\n", x);
        return x;
    }
}

char peek() {
    if (top == -1) {
      // printf("\nStack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}


void infix_to_postfix(char infix[],char postfix[]){
	char x,symbol;
	int i,j=0;
	for(i=0;infix[i] != '\0';i++){
		symbol = infix[i];
		if(isalnum(symbol)){
			postfix[j++]= symbol;
		}
		else if(symbol=='('){
			push(symbol);
		}else if(symbol==')'){
			while((x=pop())!='('){
				postfix[j++]=x;
			}
		}else{
			while(top!=-1 && (precedence(symbol)<=precedence(peek()))){
				x=pop();
				postfix[j++]=x;
			}
			push(symbol);
		}
	}
	while(top!=-1){
		postfix[j++]=pop();
	}
	postfix[j]='\0';
}

int main(){
	char infix[30],postfix[30];
	printf("INFIX EXPN:  ");
	scanf("%s",infix);
	infix_to_postfix(infix,postfix);
	printf("POSTFIX EXPN: %s\n",postfix);
    getch();
	return 0;
}