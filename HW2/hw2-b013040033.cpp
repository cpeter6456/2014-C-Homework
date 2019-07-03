#include "hw2-b013040033.h"
#include <iostream>
using namespace std;
/*
Author：雷皓博 (B013040033)
Date：2013/10/12
Purpose：習題 2 以C++製作一個「集合」類別(set class)，使其能進行加入、刪除、聯集、交集、差集、包含等運算。


*/
int main(){
    //freopen("hw2input.txt","r",stdin);
    //freopen("hw2-b013040033.out","w",stdout);

    int time;
    char CCR;
    scanf("%d",&time);                                       //跑幾次

    scanf("%c",&CCR);                                               //吃掉\n 避免影響其他輸入
    for(int k=1;k<= time ; k++ ){                            //跑幾次
            Set A,B;                                         //輸入的兩組字串
            A.sc_string();                                  //讀一行字串存到A
                                                  //吃掉\n 避免影響其他輸入
            B.sc_string();                                  //讀一行字串存到B

            char x;
            scanf("%c",&x);                                 //讀第三row單個的字元
            scanf("%c",&CCR);

                        printf("Test Case %d\n",k);
                        printf("A:{");
                A.pr_string();                              //輸出A的集合
                        printf("}\n");

                        printf("B:{");
                B.pr_string();                              //輸出B的集合
                        printf("}\n");

                Set C,D,E,F;

                C.initial();
                C=A+B;
                        printf("A+B:{");
                C.pr_string();                              //輸出A+B的集合
                        printf("}\n");
                D.initial();
                D=A*B;
                        printf("A*B:{");
                D.pr_string();                              //輸出A*B的集合
                        printf("}\n");
                E.initial();
                E=A-B;
                        printf("A-B:{");
                E.pr_string();                              //輸出A-B的集合
                        printf("}\n");
                F.initial();
                F=B-A;
                        printf("B-A:{");
                F.pr_string();                              //輸出B-A的集合
                        printf("}\n");
                if(A>=B)printf("A contains B\n");            //判斷是否A>=B
                else printf("A dose not contain B\n");

                if(B>=A)printf("B contains A\n");            //判斷是否B>=A
                else printf("B dose not contain A\n");

                if(A.in(x))printf("'%c' is in A\n",x);      //判斷是否x在A裡
                else printf("'%c' is not in A\n",x);

                if(B.in(x))printf("'%c' is in B\n",x);      //判斷是否x在B裡
                else printf("'%c' is not in B\n",x);







            printf("\n");
    }
return 0;
}

