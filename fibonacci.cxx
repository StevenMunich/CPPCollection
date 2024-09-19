//Matrix version
#include <stdio.h>
 
/* Helper function that multiplies 2 matrices F and M of size 2*2, and
puts the multiplication result back to F[][] */
void multiply(int F[2][2], int M[2][2]);
 
/* Helper function that calculates F[][] raise to the power n and puts the
result in F[][]
Note that this function is designed only for fib() and won\'t work as general
power function */
void power(int F[2][2], int n);
 
int fib(int n)
{
int F[2][2] = {{1,1},{1,0}};
if (n == 0)
    return 0;
power(F, n-1);
 
return F[0][0];
}
 
void multiply(int F[2][2], int M[2][2])
{
int x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
int y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
int z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
int w = F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
F[0][0] = x;
F[0][1] = y;
F[1][0] = z;
F[1][1] = w;
}
 
void power(int F[2][2], int n)
{
int i;
int M[2][2] = {{1,1},{1,0}};
 
// n - 1 times multiply the matrix to {{1,0},{0,1}}
for (i = 2; i <= n; i++){
    printf("step%d\n ", i);
    multiply(F, M);
    }
}

 
/* Driver program to test above function */
int main()
{
int n = 9;
printf("%d", fib(n));
getchar();
return 0;
}







/*
//Fibonacci using Dynamic Programming
//Time Complexity: O(n)
//if n = 9 #steps = 8
#include<stdio.h>
 
int fib(int n){
    
int f[n+1];
int i;
/* 0th & 1st number of the series are 0&1
f[0] = 0;
f[1] = 1;
 
for (i = 2; i <= n; i++)
{
 //Add the previous 2 numbers in the          //series and store it 
        printf("Step%d\n", i-1);
    f[i] = f[i-1] + f[i-2];
}
 
return f[n];
}

//space optimized: O(1) instead of O(n)
int fibOptimized(int n)
{
int a = 0, b = 1, c, i;
if( n == 0)
    return a;
for (i = 2; i <= n; i++)
{
    c = a + b;
    a = b;
    b = c;
}
return b;
}
 
int main ()
{
int n = 9;
printf("%d", fib(n));
getchar();
return 0;
}
*/
/*
//Fibonacci Series using Recursion
//Time Complexity: O(2^n)
// if n=9 #Steps = 54
#include<stdio.h>
int stepCount = 0;
int fib(int n)
{
if (n <= 1)
    return n;
    stepCount++;
    printf("step%d\n", stepCount);
return fib(n-1) + fib(n-2);
}
 
int main ()
{
int n = 9;
printf("%d", fib(n));
getchar();
return 0;
}
*/


/*
//OTHER MATRIX
#include <stdio.h>
 
void multiply(int F[2][2], int M[2][2]);
 
void power(int F[2][2], int n);
 
// function that returns nth Fibonacci
int fib(int n)
{
int F[2][2] = {{1,1},{1,0}};
if (n == 0)
    return 0;
power(F, n-1);
return F[0][0];
}
 
//Optimized version of power() in method
void power(int F[2][2], int n)
{
if( n == 0 || n == 1)
    return;
int M[2][2] = {{1,1},{1,0}};
 
power(F, n/2);
multiply(F, F);
 
if (n%2 != 0)
    multiply(F, M);
}
 
void multiply(int F[2][2], int M[2][2])
{
int x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
int y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
int z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
int w = F[1][0]*M[0][1] + F[1][1]*M[1][1];
 
F[0][0] = x;
F[0][1] = y;
F[1][0] = z;
F[1][1] = w;
}
 
int main()
{
int n = 9;
printf("%d", fib(9));
getchar();
return 0;
}
*/