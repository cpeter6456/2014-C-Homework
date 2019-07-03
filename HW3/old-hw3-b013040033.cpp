#include<stdio.h>
#include<stdlib.h>

using namespace std;
struct nodeDLL{
    int row,colum,direct;
    struct nodeDLL* next;
    struct nodeDLL* pre;
};
typedef nodeDLL* nodeDLLptr;



int pushDLL(nodeDLLptr  *, nodeDLLptr * , int ,int,int);
void poplast(nodeDLLptr * ,nodeDLLptr *  );


int main(void){


    for(int N=3 ; N<=3 ; N++){

        nodeDLLptr base=NULL;
        nodeDLLptr top=NULL;
        int row=N,colum=N+1;
        int arr[row][colum];
        //////初始二維陣列
        for(int i=0 ; i<row ; i++ ){
            for(int j=0 ; j< colum-1 ; j++ )
                arr[i][j]=0;
        }
        //////
        //////運算和判斷

        int x=0,y=0;

        int dx[8]={1,2,2,1,-1,-2,-2,-1};
        int dy[8]={-2,-1,1,2,2,1-1,-2};

        int time=0,k=0;

        do{
            for(k=0;k<8;k++){       //find direction
                int a=x+dx[k];
                int b=y+dy[k];

                if(  a>=0&&b>=0&&a<N&&b<N && arr[a][b]==0 ){
                    arr[a][b]==1;
                    x=a,y=b;
                    pushDLL( &base , &top ,x,y,k);
                    ++time;
                    printf("time=%d %d %d\n",time,a,b);

                     //////輸出陣列
        for(int i=0 ; i<row ; i++ ){

            for(int j=0 ; j< colum-1 ; j++ )
                printf("%d",arr[i][j]);
            printf("\n");
        }printf("\n");
        ///////
            break;
                }
            }
            if( k == 8){            //can't find
                    --time,x=top->row,y=top->colum ;
                    //arr[x][y]=0;
                    poplast(&base,&top);
            }
        }while( time!=(N*N)+1 &&  time != 0 );
        //////
        //////輸出陣列
        for(int i=0 ; i<row ; i++ ){

            for(int j=0 ; j< colum-1 ; j++ )
                printf("%d",arr[i][j]);
            printf("\n");
        }printf("\n");
        ///////

        ///////

    }////最外層for的結尾


    return 0;
}
int pushDLL( nodeDLLptr  *firstDLL , nodeDLLptr  *lastDLL, int x,int y,int d){

    nodeDLLptr temp = (nodeDLLptr)malloc( sizeof(nodeDLL) );
    temp->pre = NULL , temp->next = NULL;

    if((*firstDLL)==NULL){                 //if empty

        temp->row = x;
        temp->colum = y;
        temp->direct = d;
        //printf("here%d !%x! !%x!\n",temp->data,temp,*firstDLL);
        (*firstDLL) = temp ;
       // printf("here  !%x!\n",*firstDLL);
        (*lastDLL) = temp;
        //printf("here\n");
    }
    else{                               //not empty

        temp->row = x;
        temp->colum = y;
        temp->direct = d;
        temp->next = NULL;
        temp->pre = (*lastDLL);

        (*lastDLL)->next = temp;


        (*lastDLL)=temp;
    }

    return 0;
}

void poplast( nodeDLLptr * firstDLL , nodeDLLptr * lastDLL){         //stack -> first in last out   //store before pop
    int num = 0;
    if( (*lastDLL) ==NULL){                                           //don't return anything   just pop
        printf("is empty , don't popL\n");

    }
    else if( (*lastDLL)->pre == NULL ){                        // only one
        nodeDLLptr  temp = (*lastDLL);


        (*firstDLL) = NULL;
        (*lastDLL) = NULL;
        free(temp);

    }
    else{
        nodeDLLptr  temp = (*lastDLL);                           // two up
        (*lastDLL) = (*lastDLL)->pre;
        (*lastDLL)->next = NULL;


        free(temp);

    }

}
