#include<stdio.h>
#include<stdlib.h>
#define MAX 100                                 //�]MAX
/*
Author �p�q��
Date�G2013/9/25
Purpose�G�L�X����1�PN�����Ҧ��Ƥ�����(factorial)
*/
int main()
{




    int N=1;                            //N�O����
    while(N!=0)
    {
        scanf("%d",&N);                         //N�O�h�֪�����,��J0�ɸ��X
        if(N!=0)
        {

            int BIG[MAX]={0};
            BIG[MAX-1]=1;                       //��ư}�CBIG���j��,�]��l��
            int num,left=0;                     //left�O�̰���� num������
            for(num=1;num<=N;num++)             //�W�[����
            {
                left=0;
                while(BIG[left]==0)left++;      //��left�̰����

                int now=MAX-1;                  //now�O�����ثe�����
                while(now>=left-1)              //�O�I����̰���ƪ�����
                {
                    BIG[now]=BIG[now]*num;      //�}�C���W�n�����Ʀrnum

                    now--;                      //��snow
                }
                now=MAX-1;
                while(now>=left-1)              //�O�I�̰���ƪ�����
                {
                    BIG[now-1]+=BIG[now]/10;    //�i��10
                    BIG[now]=BIG[now]%10;       //��s�Q����
                    now--;                      //��snow
                }
                left=0;                         //��left�̰����
                while(BIG[left]==0)left++;

                int i=left;
                printf("%d!=",num);        //�L�X�ثe�ĴX��
                for(;i<MAX;i++)
                {
                    printf("%d",BIG[i]);        //�L�X�������Ʀr
                }
                printf("\n");


            }
            printf("\n");



        }

    }

}
