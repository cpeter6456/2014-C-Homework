
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INT_MIN -9999

void createFibonacci(int[], int);     // ミ禣ん计
int findY(int[], int);          // тY
int fibonacciSearch(int[], int, int);  // 禣ん穓碝

int main(void) {
    int number[] = {0, 1,2,3,4,5,6,7,8,9,10,11,12,13};
    int length = sizeof(number) / sizeof(int);

    printf("计");
    int i;
    for(i = 0; i < length; i++)
        printf("%d ", number[i]);

    printf("\n块碝т癸禜");
    int find;
    scanf("%d", &find);

    if((i = fibonacciSearch(number, length, find)) >= 0)
        printf("т计ま %d ", i);
    else
        printf("\nтぃ﹚计");

    printf("\n");

    return 0;
}

// ミ禣ん计
void createFibonacci(int Fib[], int length) {
    Fib[0] = 0;
    Fib[1] = 1;
    int i;
    for(i = 2; i < length; i++)
        Fib[i] = Fib[i-1] + Fib[i-2];
}

// т y 
int findY(int Fib[], int n) {
    int i = 0;
    while(Fib[i] <= n) i++;
    i--;
    return i;
}

// 禣Α穓碝
int fibonacciSearch(int number[], int length, int find) {
    int* Fib = (int *)malloc(length * sizeof(int));
    int f;
    for(f = 0; f < length; f++) {
        Fib[f] = INT_MIN;
    }

    createFibonacci(Fib, length);

    int y  = findY(Fib, length + 1);
    int m = length - Fib[y];
    int x = y - 1;
	 printf("\nx = %d, m = %d, Fib[x] = %d\n\n", x, m, Fib[x]);
    int i = x;
    if(number[i] < find)
        i += m;

    int result = -1;
    while(Fib[x] > 0) {
        if(number[i] < find)
            i += Fib[--x];
        else if(number[i] > find)
            i -= Fib[--x];
        else {
            result = i;
            break;
        }
    }

    free(Fib);

    return result;
}
