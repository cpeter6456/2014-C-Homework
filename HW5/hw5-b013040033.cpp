#include <stdio.h>
#include <stdlib.h>
/*
Author�G�p�q�� (B013040033)
Date�G2013/11/1
Purpose�G���D 5 �i��Ackerman function ������ (recursion������)

*/
long long int c;                //�p��I�s�X��function
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
int A(int m,int n){             //Ackerman function ������

    c++;                        //�p��I�s�X��function

    if(m==0)
        return  n+1;
    if(m!=0 && n==0)
        return  A(m-1,1);
    if(m!=0&&n!=0)
        return A(m-1,A(m,n-1));

}
