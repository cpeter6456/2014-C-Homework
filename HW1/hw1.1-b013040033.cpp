#include <stdio.h>
#include <stdlib.h>
/*
Author �p�q��
Date�G2013/9/25
Purpose�G�s�@N��(N���_��)���]��}(magic square)
*/

int main()
{
    for(int N=1;N<10;N=N+2)                         //����N��1,3,5,7,9�����]��}
    {
        int square[N][N];                           //�G��N*N�}�C

        int x,y;                                    //x,y���G���}�C����P�C,�P�����ثe���
        for(x=0;x<N;x++)                            //�G���}�C���]��l��0
        {
            for(y=0;y<N;y++)
            square[x][y]=0;
        }
        square[(N-1)/2][0] = 1;                     //�G���}�C 1 ����l�Ȧ�l

        printf("N=%d    ",N);                       //�X���]��}

        x=(N-1)/2,y=0;
        for(int num=2;num<=N*N;num++)               //����N*N���Ʀr
        {
            if( square[(x-1+N)%N ][ (y-1+N)%N ]!=0 )//�Y���W�観�Ʀr,�h��U��
            {
                square[x][(y+1+N)%N]=num;
                y=(y+1+N)%N;                        //��sy
            }
            else{
                square[(x-1+N)%N ][(y-1+N)%N] = num;//�Y���W��S�Ʀr,��Ʀr��J���W��
                x=(x-1+N)%N;                        //��sx,y
                y=(y-1+N)%N;
            }

        }
        for(y=0;y<N;y++)
        {
            for(x=0;x<N;x++)
            {
                if(x%N==0)printf("\n");
                printf("%4d",square[x][y]);         //�L�X�]��}


            }

        }
        printf("\n\n");
    }

    return 0;
}
