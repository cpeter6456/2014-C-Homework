/* 作者：蘇炯綸*/
/* 學號：Ｂ０１３０４０００６*/ 
/*撰寫日期Dec，21，２０１３*/
/*本程式用來比較三種SORT的速度*/
#include <stdio.h>
#include <stdlib.h>
# include <iostream>
#include <time.h>
using namespace std;
int array3[500000];//merge sort輸入數字空間 

struct btreenode//binary tree sort節點 
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
};
void insert(struct btreenode** ,int );//binary tree sort 
void inorder(struct btreenode* ,FILE* );//binary tree sort 
void MergeSort(int x[ ], int left, int right);

int main(void)
{   
    clock_t start, end;//用於計算時間(開始,結束) 
    struct btreenode *bt ;//binary tree sort--head 
    int i=0 ;int j=0;//for迴圈用 
    int size=0;//記憶大小 
    int tmp=0;//swap--temp 
    int array2[500000]={0};//bubble sort輸入數字空間
//bubble sort     
    FILE* input=fopen("input.txt","r");
    FILE* output=fopen("outputA.txt","w");
    fscanf(input,"%d",&size);//讀大小 
    printf ( "Bubble Sort.\n" ) ;
    for ( i = 0 ; i < size ; i++ )//資料讀入 
        fscanf(input,"%d\n",&array2[i]);
    double diff2=0;//計算時間 
    start = clock();
    //實作 
    for (i = 0; i < size; i++) {
        for (j = size - 1; j > i; j--) {
            if (array2[j] < array2[j-1]) {
                tmp = array2[j-1];
                array2[j-1] =  array2[j];
                array2[j] = tmp;
            }
        }
        end = clock();
        diff2=(double)(end - start)/CLOCKS_PER_SEC;
        if(diff2>600) goto out;//超過5分鐘 執行失敗 
    }   
    diff2=(double)(end - start)/CLOCKS_PER_SEC;
    printf(" %.3lf  sec\n",diff2);  
  
    for (i = 0; i < size; i++) 
        fprintf(output,"%d ", array2[i]);        
    if(0){out:;printf("it's beyond 5 minutes");}//失敗區 
    fclose(input);
    fclose(output);
//binary tree sort 
    input=fopen("input.txt","r");
    output=fopen("outputB.txt","w");   
    fscanf(input,"%d",&size);//讀入大小 
    int temp2=0;//數字暫存 
    bt=NULL ;
    start=clock();
    printf("Binary tree sort.\n");
    for (i=1;i<=size;i++)
        {
          fscanf(input,"%d\n",&temp2);
          insert(&bt,temp2);//輸入 
        }
    inorder(bt,output);//輸出 
    end=clock();
    double diff=(double)(end-start)/CLOCKS_PER_SEC;
    printf(" %.3lf  sec\n",diff);
    fclose(input);
    fclose(output);
//merge sort
    input=fopen("input.txt","r");
    output=fopen("output3.txt","w");      
    printf ("Merge Sort.\n");
    fscanf(input,"%d",&size);//讀入大小 
    for (i=0;i<size;i++)
        fscanf(input,"%d\n",&array2[i]);
    start=clock();
    MergeSort(array2,0,size-1);//主體 
    end=clock();
    double diff3=(double)(end - start)/CLOCKS_PER_SEC;
    printf(" %.3lf  sec\n",diff3);
    for (i = 0; i < size; i++) 
        fprintf(output,"%d ", array2[i]);             
    fclose(input);
    fclose(output);
    return 0;  
}

void insert ( struct btreenode **sr, int num )
{
    if ( *sr == NULL )
    {
        *sr =(btreenode *) malloc ( sizeof ( struct btreenode ) ) ;

        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *sr ) -> data )
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else
            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}

void inorder ( struct btreenode *sr ,FILE* output)
{
    if ( sr != NULL )
    {
        inorder ( sr -> leftchild ,output) ;
        fprintf (output, "%d ", sr -> data ) ;
        inorder ( sr -> rightchild,output ) ;
        free(sr);
    }
}
void MergeSort(int x[ ], int left, int right)
{
    int mid, i, j, k;
    if (left >= right)  return;                                                   
    mid = (left + right) / 2;   
    MergeSort(x, left, mid);        
    MergeSort(x, mid + 1, right);   
    
    for (i = left; i <= mid; i++)
        array3[i] = x[i];

    for (i = mid + 1, j = right; i <= right; i++, j--)
        array3[i] = x[j];

    i = left;
    j = right;

    for (k = left; k <= right; k++)
        if (array3[i] <= array3[j])
            x[k] = array3[i++];
        else
            x[k] = array3[j--];
}
