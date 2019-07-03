#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

/*
Author：雷皓博 (B013040033)
Date：2013/12/9
Purpose：習題 8 測試三種排序(sorting)演算法的執行效率 (sorting之應用)

*/
using namespace std;

void make_file_data(int *arr,int now);
void bubble_sort(int *arr,int arr_size);
void heap_sort(int *arr,int arr_size);
void merge_sort(int *arr,int arr_size);


int parent(int);
int left(int);
int right(int);
void Max_Heapify(int [], int, int);
void Build_Max_Heap(int [], int);
void print(int [], int);
void HeapSort(int [], int);

void merge_cut(int n, int*s);
void merge_combine(int left, int right, int*l, int*r, int*s);
FILE *file;

int main(void){

    int num_arr[10]={100,500,1000,5000,10000,50000,100000,500000},num=0;
    for(int k=0;k<10;k++){
        for(num=0;num<8;num++){

            clock_t start_tick, end_tick;/** 算時間的變數 **/
            double diff_time;
            /***** 製作 input.txt *****/
            make_file_data(num_arr,num);
            int a_size=num_arr[num];
            printf("***********%d 個資料************\n", num_arr[num]);
            int *in_arr = new int [a_size];
            int maxnum=0;
            int *temp_arr = new int [a_size];
            printf("%d",num_arr[num]);
            file = fopen("input.txt","r");

            fscanf(file,"%d",&maxnum);
            for(int i=0;i<maxnum;i++){
                fscanf(file,"%d",&in_arr[i]);
                temp_arr[i]=in_arr[i];
            }

            for(int i=0;i<maxnum;i++)
                temp_arr[i]=in_arr[i];


            start_tick = clock();//開始時間

            bubble_sort(temp_arr,maxnum);

            end_tick = clock();//結束時間


            diff_time =(double) (end_tick-start_tick)/CLOCKS_PER_SEC;//秒數
            printf("\nBUUBLE 執行時間 = %.5lf s \t %d ms\n\n",diff_time,(end_tick-start_tick));
            //printf("\nBUUBLE 執行時間 = %.5lf s \t %d ms\n\n",end_tick,start_tick);


            for(int i=0;i<maxnum;i++)
                temp_arr[i]=in_arr[i];
            start_tick = clock();//開始時間

            heap_sort(temp_arr,maxnum);

            end_tick = clock();//結束時間
            diff_time =(double) (end_tick-start_tick)/CLOCKS_PER_SEC;//秒數
            printf("\nHEAP   執行時間 = %.5lf s \t %d ms\n\n",diff_time,(end_tick-start_tick));
            //printf("\nBUUBLE 執行時間 = %.5lf s \t %d ms\n\n",end_tick,start_tick);
            for(int i=0;i<maxnum;i++)
                temp_arr[i]=in_arr[i];

            start_tick = clock();//開始時間

            merge_sort(temp_arr,maxnum);


            end_tick = clock();//結束時間
            diff_time =(double) (end_tick-start_tick)/CLOCKS_PER_SEC;//秒數
            printf("\nMERGE  執行時間 = %.5lf s \t %d ms\n\n",diff_time,(end_tick-start_tick));
            //printf("\nBUUBLE 執行時間 = %.5lf s \t %d ms\n\n",end_tick,start_tick);
            fclose(file);
        }
    }
    return 0;
}
void make_file_data(int *arr,int now){
    FILE *file = fopen("input.txt","w");
    srand(time(0));
    fprintf(file,"%d\n",arr[now]);
    for (int i = 1; i <= arr[now]; i++) {
        fprintf(file,"%d ", rand()%1000000);
        fprintf(file,"\n");

    }
    fclose(file);
    return;
}
void bubble_sort(int *arr,int arr_size){

    FILE *foutA = fopen("outputA.txt","w");

    int i,j,temp;
    printf("");
    for (i = arr_size - 1; i > 0; i--)
    {
        for (j = 0; j <= i - 1; j++)
        {
            if (arr[j] >arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(i=0;i < arr_size ;i++){
        fprintf(foutA,"%d\n",arr[i]);
    }

    fclose(foutA);
}
void heap_sort(int *arr,int arr_size){


    HeapSort(arr, arr_size);

}
void merge_sort(int *arr,int arr_size){

    FILE *foutC = fopen("outputC.txt","w");
    merge_cut(arr_size, arr);
    for(int i=0;i<arr_size;i++){
        fprintf(foutC,"%d\n",arr[i]);

    }

    fclose(foutC);

}


/*父結點*/
int parent(int i)
{
    return (int)floor((i - 1) / 2);
}

/*左子結點*/
int left(int i)
{
    return (2 * i + 1);
}

/*右子結點*/
int right(int i)
{
    return (2 * i + 2);
}

/*單一子結點最大堆積樹調整*/
void Max_Heapify(int A[], int i, int heap_size)
{
    int l = left(i);
    int r = right(i);
    int largest;
    int temp;
    if(l < heap_size && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if(r < heap_size && A[r] > A[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        Max_Heapify(A, largest, heap_size);
    }
}

/*建立最大堆積樹*/

void Build_Max_Heap(int A[],int heap_size)
{
    for(int i = (heap_size-2)/2; i >= 0; i--)
    {
            Max_Heapify(A, i, heap_size);
    }
}

/*印出樹狀結構*/
void print(int A[], int heap_size)
{   FILE * foutB = fopen("outputB.txt","w");
    for(int i = 0; i < heap_size;i++)
    {
        fprintf(foutB,"%d\n", A[i]);
    }

}

/*堆積排序程序碼*/
void HeapSort(int A[], int heap_size)
{
    Build_Max_Heap(A, heap_size);

    int temp;
    for(int i = heap_size - 1; i >= 0; i--)
    {

        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        Max_Heapify(A, 0, i);
    }
    print(A, heap_size);
}
void merge_cut(int n, int*s)
{
    if (n > 1)
    {
        int left = n / 2, right = n - left;
        int *l = new int[left];
        int *r = new int[right];
        for (int i = 0; i < left; i++)
            l[i] = s[i];
        for (int i = 0; i < right; i++)
            r[i] = s[left + i];
        merge_cut(left, l);
        merge_cut(right, r);
        merge_combine(left, right, l, r, s);
    }

}

void merge_combine(int left, int right, int*l, int*r, int*s)
{
    int i = 0, j = 0, k = 0;

    while (i < left && j < right)
    {
        if (l[i] < r[j])
        {
            s[k] = l[i];
            i++;
        }
        else
        {
            s[k] = r[j];
            j++;
        }
        k++;
    }
    if (i >= left)
        for (int m = j, c = 0; m < right; m ++, c ++)
            s[k + c] = r[m];
    else
        for (int m = i, c = 0; m < left; m ++, c ++)
            s[k + c] = l[m];
}
