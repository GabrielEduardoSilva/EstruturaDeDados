//
//  main.c
//  QuickSort
//
//  Created by Gabriel Eduardo on 02/09/23.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

void quick_sort(int *a, int left, int right);

int main(void) {
    
    return 0;
}

void quick_sort(int *a, int left, int right){
    int i, j, x, y;
    
    i = left;
    j = right;
    x = a[(left + right) / 2];
    
    while ( i <= j ){
        while(a[i] < x && i < right){
            i++;
        }
        while(a[j] > x &&  j > left){
            j--;
        }
        if( i <= j ){
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
            
        }
    }
    
    
}
