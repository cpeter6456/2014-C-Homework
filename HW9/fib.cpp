
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INT_MIN -9999

void createFibonacci(int[], int);     // �إ߶O��ƦC
int findY(int[], int);          // ��Y��
int fibonacciSearch(int[], int, int);  // �O��j�M

int main(void) {
    int number[] = {0, 1,2,3,4,5,6,7,8,9,10,11,12,13};
    int length = sizeof(number) / sizeof(int);

    printf("�ƦC�G");
    int i;
    for(i = 0; i < length; i++)
        printf("%d ", number[i]);

    printf("\n��J�M���H�G");
    int find;
    scanf("%d", &find);

    if((i = fibonacciSearch(number, length, find)) >= 0)
        printf("���Ʀr����� %d ", i);
    else
        printf("\n�䤣����w��");

    printf("\n");

    return 0;
}

// �إ߶O��ƦC
void createFibonacci(int Fib[], int length) {
    Fib[0] = 0;
    Fib[1] = 1;
    int i;
    for(i = 2; i < length; i++)
        Fib[i] = Fib[i-1] + Fib[i-2];
}

// �� y ��
int findY(int Fib[], int n) {
    int i = 0;
    while(Fib[i] <= n) i++;
    i--;
    return i;
}

// �O���j�M
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
