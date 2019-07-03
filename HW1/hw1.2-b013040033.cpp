#include<stdio.h>
#include<stdlib.h>
#define MAX 100                                 //設MAX
/*
Author 雷皓博
Date：2013/9/25
Purpose：印出介於1與N之間所有數之階乘(factorial)
*/
int main()
{




    int N=1;                            //N是階乘
    while(N!=0)
    {
        scanf("%d",&N);                         //N是多少的階乘,輸入0時跳出
        if(N!=0)
        {

            int BIG[MAX]={0};
            BIG[MAX-1]=1;                       //整數陣列BIG做大數,設初始值
            int num,left=0;                     //left是最高位數 num為乘數
            for(num=1;num<=N;num++)             //增加乘數
            {
                left=0;
                while(BIG[left]==0)left++;      //找left最高位數

                int now=MAX-1;                  //now是紀錄目前做到哪
                while(now>=left-1)              //保險做到最高位數的左邊
                {
                    BIG[now]=BIG[now]*num;      //陣列乘上要乘的數字num

                    now--;                      //更新now
                }
                now=MAX-1;
                while(now>=left-1)              //保險最高位數的左邊
                {
                    BIG[now-1]+=BIG[now]/10;    //進位10
                    BIG[now]=BIG[now]%10;       //更新被除的
                    now--;                      //更新now
                }
                left=0;                         //找left最高位數
                while(BIG[left]==0)left++;

                int i=left;
                printf("%d!=",num);        //印出目前第幾階
                for(;i<MAX;i++)
                {
                    printf("%d",BIG[i]);        //印出對應的數字
                }
                printf("\n");


            }
            printf("\n");



        }

    }

}
