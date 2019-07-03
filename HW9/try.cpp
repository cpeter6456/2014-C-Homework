
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
int rec(int);
int main (){
    int a=0,b=0;
    printf("a to b\n");
    scanf("%d %d",&a,&b);
    int total=0;
    for(int t=0;t<=b;t++)
    {
        total=total+rec(t);
        printf("THE ANS IS %d\n",total);
    }
    printf("THE ANS IS %d\n",total);
    for(int t=0;t<=(a-1);t++)
    {
        total-=rec(t);
    }
    printf("THE ANS IS %d",total);

    return 0;
}
int rec(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n%10 != 0)
    {
        return n%10;
    }
    if(n!=0 && n%10==0)
    {
        return rec(n/10);
    }

}
