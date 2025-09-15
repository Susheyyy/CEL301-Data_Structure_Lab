#include<stdio.h>

int GCD(int,int);
int main()
{
    int num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);
    result=GCD(num1,num2);
    printf("GCD of %d and %d is %d",num1,num2,result);
    return 0;
}
int GCD(int a,int b)
{
    int rem;
    rem = a % b;
    if(rem==0)
        return b;
    else
        return (GCD(b,rem));
}