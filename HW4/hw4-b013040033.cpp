#include<stdio.h>
#include<stdlib.h>
/*
Author：雷皓博 (B013040033)
Date：2013/11/1
Purpose：4 將上一個習題改為recursive program (recursion之應用)


*/
using namespace std;
int arr[7][7],N=1;

int dx[8]={1,2,2,1,-1,-2,-2,-1};                                //八個direction
int dy[8]={-2,-1,1,2,2,1,-1,-2};


int recursive(  int loc_row ,int loc_column,int the_time ){   ////!!!!!!!the recursive!!!!!
        if(the_time==N*N){
                arr[loc_row][loc_column]=the_time;
                return 0;
        }
        int k,flag=0;
        for(k=0;k<8;k++){                              //find direction  r,c is target
                int r=loc_row+dy[k];                    //八個direction
                int c=loc_column+dx[k];

                if(r>=0&&c>=0&&r<N&&c<N && arr[r][c]==0 ){
                    arr[loc_row][loc_column]=the_time;
                    flag=recursive(r,c,1+the_time);
                    if(flag==-1){
                        arr[loc_row][loc_column]=0;              //清位子
                    }
                    else if(flag==0)
                        return 0;

                }

        }
        if(k>=8){                                   // direction more 8     direction(0~7)

            arr[loc_row][loc_column]=0;              //清位子

            if(the_time==N*N)return 0;
            return -1;
        }
        if(the_time==N*N)return 0;
        return 0;

}
int main(){
    //freopen("hw4-b013040033.out","w",stdout);
    for( N=1 ; N<=6 ; N++){

        for(int i=0 ; i<7 ; i++ ){                  //   初始化
            for(int j=0 ; j< 7 ; j++ )
                arr[i][j]=0;
                                           //
        }
        arr[0][0]=1;
        if(N!=1)recursive(0,0,1);
        if(arr[0][0]!=0){
            for(int i=0 ; i<N ; i++ ){
                    for(int j=0 ; j< N ; j++ )
                            printf("%2d ",arr[i][j]);
                        printf("\n");
                    }printf("\n");
        }
        else{
            printf("no solution\n\n");
        }
    }

    return 0;
}
