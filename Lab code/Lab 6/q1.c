#include <stdio.h>
#include<math.h>
int max(int a,int b){
    if(a>b)
    return a;
    else 
    return b;
}
int size_find(int x){
    int no=0;
    while(x)
    {
        x/=10;
        no++;
    }
    return no;
}
long int multiply( int x, int y)
{
  
    int n=max(size_find(x),size_find(y));
    if(n==1)
    return x*y;
    else if(n>1){
        long int m,a,b,c,d,p1,p2,p3,mul;
        m=(long int)(n/2);
        a=x/pow(10,m);
        b=x%(long int)pow(10,m);
        c=y/pow(10,m);
        d=y%(long int)pow(10,m);
        p1=multiply(a,c);
        p2=multiply(b,d);
        p3=multiply(a+b,c+d);
        mul=p1*pow(10,2*m)+p2+(long int)pow(10,m)*(p3-p1-p2);
        return mul;
    }
}

int main()
{
    int x=multiply(16363,234);
    printf("%d",x);

    return 0;
}