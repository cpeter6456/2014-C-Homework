#include <stdio.h>
#include <stdlib.h>
/*
Author：雷皓博 (B013040033)
Date：2013/11/1
Purpose：習題 5 進行Ackerman function 之測試 (recursion之應用)

*/
long long int c;                //計算呼叫幾次function
int A(int ,int );
int main(){
     //freopen("hw5-b013040033.out","w",stdout);
     c=0;
    int m,n;
    printf("input m n\n");
    scanf("%d %d",&m,&n);           //INPUT
    printf("%lld= %d ",c,A(m,n));

    return 0;
}
int A(int m,int n){             //Ackerman function 之測試

    c++;                        //計算呼叫幾次function

    if(m==0)
        return  n+1;
    if(m!=0 && n==0)
        return  A(m-1,1);
    if(m!=0&&n!=0)
        return A(m-1,A(m,n-1));

}
