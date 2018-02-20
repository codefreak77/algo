#include <stdio.h>
#include <stdlib.h>


char heap[30] = {0, 'T', 'S', 'R', 'P', 'N', 'O', 'A', 'E', 'I', 'H', 'G'};
char heap_sink[30] = {0, 'H', 'S', 'R', 'N', 'P', 'O', 'A', 'E', 'I', 'G'};
char heap_bad[30] = {0, 'S', 'P', 'R', 'N', 'T', 'O', 'A', 'E', 'I', 'H', 'G'};
int heap_size = 11;


void swim(int k) {
    char tmp;

    printf("k  %c k/2  %c", heap_bad[k], heap_bad[k/2]);
    while((k/2) >= 1) {
        if (heap_bad[k] > heap_bad[k/2]) {
            tmp = heap_bad[k/2];
            heap_bad[k/2] = heap_bad[k];
            heap_bad[k] = tmp;
        }

        k = k/2;
    }
}

void sink(int k)
{
    int i = 0, j = 0, idx1 = 0, idx2 = 0, largest = 0;
    char tmp;

    while(2*k <= 10) {
        j = 2*k;

        if (heap_sink[j] > heap_sink[k]) {
            idx1 = largest = j;
        }

        i = 2*k + 1;
        if (i<= 10) {
            if (heap_sink[i] > heap_sink[k]) {
                idx2 = largest = i;
            }
        }
       
        if (idx1 && idx2) {
            if (heap_sink[i] >=  heap_sink[j]) {
                largest = i;
            } else {
                largest = j;
            }
        }

        printf("\n swap largest %d %c  k %d %c", largest, heap_sink[largest], k, heap_sink[k]);
        tmp = heap_sink[k];
        heap_sink[k] = heap_sink[largest];
        heap_sink[largest] = tmp;

        k = largest;
    } /* end of while loop */
}

main()
{
    int i = 0;
    printf("start: heap \n");
    printf("\ngood heap: ");
    for (i=0; i<heap_size; i++) {
        printf("%c ", heap[i]);
    }
   
    printf("\nbad heap:  ");
    for (i=0; i<heap_size; i++) {
        printf("%c ", heap_bad[i]);
    }

    printf("\nswim calld %d", (5/2));
    swim(5);
    
    printf("\nbad heap:  ");
    for (i=0; i<heap_size; i++) {
        printf("%c ", heap_bad[i]);
    }
   
    sink(1);
    printf("\nsink heap:  ");
    for (i=0; i<11; i++) {
        printf("%c ", heap_sink[i]);
    }

    printf("\nend: heap \n");
}
