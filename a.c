#include <stdio.h>
/*Question 1*/
int n,fibo;
int fib(int n){
if(n==1){
    return 0;
}
else if(n==2){
    return 1;
}
return fib(n-1)+fib(n-2);

}
void main(){
    printf("Enter value of n:");
    scanf("%d",&n);
    fibo=fib(n);
    printf("The fibonacci number is:%d",fibo);

}
/*Question 2*/
int n,fact;
int factorial(int n){
if(n==0){
    return 1;
}
if(n==1){
    return 1;
}

return n*factorial(n-1);
}
void main(){
    printf("Enter value of n:");
    scanf("%d",&n);
    fact=factorial(n);
    printf("The factorial:%d",fact);
}

/*Tower of hanoi*/

int n;
char s,d,t;
void TOH(int n, char s, char t, char d) {
    if (n == 1) {
        printf("Move disk %d from %c -> %c\n",n, s, d);
        return;
    }
    TOH(n - 1, s, d, t);
    printf("Move disk %d from %c -> %c\n", n, s, d);
    TOH(n - 1, t,s,d);
}

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    TOH(n,'s','t','d');
    return 0;
}
