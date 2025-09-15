#include<stdio.h>

int fibonacci(int);
int main()
{
    int n,i = 0, result;
    printf("Enter the number of terms: \n");
    scanf("%d",&n); 
    printf("Fibonacci Series: \n");
    for(i=0;i<n;i++)
    {
        result=fibonacci(i);
        printf("%d\t",result);
    }
    return 0;
}
int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return (fibonacci(n-1)+fibonacci(n-2));
}