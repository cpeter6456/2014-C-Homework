#include <stdio.h>
#include <stdlib.h>
/*
Author 雷皓博
Date：2013/9/25
Purpose：製作N階(N為奇數)的魔方陣(magic square)
*/

int main()
{
    for(int N=1;N<10;N=N+2)                         //控制N做1,3,5,7,9階的魔方陣
    {
        int square[N][N];                           //二維N*N陣列

        int x,y;                                    //x,y為二維陣列的行與列,與紀錄目前到哪
        for(x=0;x<N;x++)                            //二維陣列全設初始值0
        {
            for(y=0;y<N;y++)
            square[x][y]=0;
        }
        square[(N-1)/2][0] = 1;                     //二維陣列 1 的初始值位子

        printf("N=%d    ",N);                       //幾的魔方陣

        x=(N-1)/2,y=0;
        for(int num=2;num<=N*N;num++)               //做到N*N的數字
        {
            if( square[(x-1+N)%N ][ (y-1+N)%N ]!=0 )//若左上方有數字,則放下面
            {
                square[x][(y+1+N)%N]=num;
                y=(y+1+N)%N;                        //更新y
            }
            else{
                square[(x-1+N)%N ][(y-1+N)%N] = num;//若左上方沒數字,把數字放入左上方
                x=(x-1+N)%N;                        //更新x,y
                y=(y-1+N)%N;
            }

        }
        for(y=0;y<N;y++)
        {
            for(x=0;x<N;x++)
            {
                if(x%N==0)printf("\n");
                printf("%4d",square[x][y]);         //印出魔方陣


            }

        }
        printf("\n\n");
    }

    return 0;
}
