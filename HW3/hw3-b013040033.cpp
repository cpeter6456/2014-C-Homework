#include<stdio.h>
#include<stdlib.h>
/*
Author：雷皓博 (B013040033)
Date：2013/10/26
Purpose：習題 3 西洋棋騎士(knight)走完棋盤的順序 (stack之應用)


*/
using namespace std;

struct node{                                            //模擬stack紀錄位子 和 放向
    int row,colum,direct;
};
typedef node thenode;
int main(void){
    //freopen("hw3-b013040033.out","w",stdout);
    for(int N=1 ; N<=6 ; N++){
        int arr[N+5][N+5],i;                                //construct array && 初始化
        thenode narray[500];
        for( i=0 ; i<N ; i++ ){
            for(int j=0 ; j< N ; j++ )
                arr[i][j]=0;                            //
        }
        for(i=0;i<50;i++){
            narray[i].colum=0 , narray[i].row=0 , narray[i].direct=0;   //   初始化
        }

        int dx[8]={1,2,2,1,-1,-2,-2,-1};                                //八個direction
        int dy[8]={-2,-1,1,2,2,1,-1,-2};

        int time=1,k=0,row=0,colum=0,ldir = -1;                         //   初始化
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
                    arr[row][colum]=0;                      //清位子
                    ldir=narray[time-1].direct , row=narray[time-1].row , colum=narray[time-1].colum;   //存之前的值


                }
            }
        }while(time!=0 && time!=(N*N) );                //終止條件  1->都找到time=N*N  2->找不到 減到最後time=0



        if(N==1){
            printf("1\n\n");
        }
        else if(N>1){                                   //輸出
            if(time!=0 ){
                for(int i=0 ; i<N ; i++ ){

                    for(int j=0 ; j< N ; j++ )
                        printf("%2d ",arr[i][j]);
                    printf("\n");
                }printf("\n");
                //for(int i=0 ; i<(N*N+1) ; i++ )printf("r=%d c=%d k=%d\n",narray[i].row,narray[i].colum,narray[i].direct);
            }
            else{

                printf("no solution\n\n");              //輸出
                //for(int i=0 ; i<(N*N+1) ; i++ )printf("r=%d c=%d k=%d\n",narray[i].row,narray[i].colum,narray[i].direct);
            }
        }
    }                                                     //most outside FOR

    return 0;
}
