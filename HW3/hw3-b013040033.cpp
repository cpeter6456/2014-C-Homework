#include<stdio.h>
#include<stdlib.h>
/*
Author�G�p�q�� (B013040033)
Date�G2013/10/26
Purpose�G���D 3 ��v���M�h(knight)�����ѽL������ (stack������)


*/
using namespace std;

struct node{                                            //����stack������l �M ��V
    int row,colum,direct;
};
typedef node thenode;
int main(void){
    //freopen("hw3-b013040033.out","w",stdout);
    for(int N=1 ; N<=6 ; N++){
        int arr[N+5][N+5],i;                                //construct array && ��l��
        thenode narray[500];
        for( i=0 ; i<N ; i++ ){
            for(int j=0 ; j< N ; j++ )
                arr[i][j]=0;                            //
        }
        for(i=0;i<50;i++){
            narray[i].colum=0 , narray[i].row=0 , narray[i].direct=0;   //   ��l��
        }

        int dx[8]={1,2,2,1,-1,-2,-2,-1};                                //�K��direction
        int dy[8]={-2,-1,1,2,2,1,-1,-2};

        int time=1,k=0,row=0,colum=0,ldir = -1;                         //   ��l��
            arr[0][0]=1;
        do{

            for(k=0;k<8;k++){                              //find direction  r,c is target
                int r=row+dy[k];
                int c=colum+dx[k];
                if(r>=0&&c>=0&&r<N&&c<N && arr[r][c]==0 && k > ldir){
                    narray[time-1].row=row, narray[time-1].colum=colum ,narray[time-1].direct=k;
                    row=r,colum=c;
                    arr[row][colum]=++time;
                    ldir=-1;
                    break;
                }
            }
            if(k==8){                                       // direction more 8     direction(0~7)

                if(N!=1)--time;
                if(time!=0){
                    arr[row][colum]=0;                      //�M��l
                    ldir=narray[time-1].direct , row=narray[time-1].row , colum=narray[time-1].colum;   //�s���e����


                }
            }
        }while(time!=0 && time!=(N*N) );                //�פ����  1->�����time=N*N  2->�䤣�� ���̫�time=0



        if(N==1){
            printf("1\n\n");
        }
        else if(N>1){                                   //��X
            if(time!=0 ){
                for(int i=0 ; i<N ; i++ ){

                    for(int j=0 ; j< N ; j++ )
                        printf("%2d ",arr[i][j]);
                    printf("\n");
                }printf("\n");
                //for(int i=0 ; i<(N*N+1) ; i++ )printf("r=%d c=%d k=%d\n",narray[i].row,narray[i].colum,narray[i].direct);
            }
            else{

                printf("no solution\n\n");              //��X
                //for(int i=0 ; i<(N*N+1) ; i++ )printf("r=%d c=%d k=%d\n",narray[i].row,narray[i].colum,narray[i].direct);
            }
        }
    }                                                     //most outside FOR

    return 0;
}
