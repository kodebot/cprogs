#include <stdio.h>


// function pointer examples
// looks like a normal function declaration but with paranthesis around * to tell compiler that this
// is not a function reutrning int pointer rather the function itself is a pointer => function pointer
// WHY: it is useful to pass around functions like a normal value
int run(int (*)(int,int), int, int);

int add(int, int);
int sub(int, int);
int div(int, int);
int mul(int, int);

int main()
{
    printf("add result %d\n", run(add, 10, 2));  
    printf("sub result %d\n", run(sub, 10, 2));  
    printf("div result %d\n", run(div, 10, 2));  
    printf("mul result %d\n", run(mul, 10, 2));  
    return 0;
}

int run(int (*op)(int,int), int a, int b)
{
    return op(a, b);
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int div(int a , int b)
{
    return a / b;
}

int mul(int a, int b)
{
    return a * b;
}

