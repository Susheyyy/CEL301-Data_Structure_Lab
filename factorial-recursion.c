#include <stdio.h>

int factorial(int);
int main()
{
    int num,val;
    prinft("\nEnter a number:");
    scanf("%d",&num);
    val=factorial(num);
    printf("Factorial of %d is %d",num,val);
    return 0;
}
int factorial(int n)
{
    if(n==1)
        return 1;
    else
        return (n*factorial(n-1));
}
