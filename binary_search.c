#include <stdio.h>

int array1[8] = {45, 67, 82, 84, 90, 100, 110, 3000};
int array2[11] = {45, 67, 82, 84, 90, 100, 110, 3000, 6000, 9309, 21000};

int binary_search(int arr[], int lo, int hi, int value)
{
    int mid = 0;

    if (hi >= lo) {
        mid = lo + (hi - lo)/2;

        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            mid = binary_search(arr, (mid + 1), hi, value);
            return mid;
        } else {
            mid = binary_search(arr, lo, (mid - 1), value);
            return mid;
        }
    }

    return (-1);
}

main() 
{
    int rank = 0;
    printf("\nHello World\n");

    rank = binary_search(array1, 0, 7, 90);
    printf("\nRank 1 = %d", rank);
    rank = binary_search(array2, 0, 10, 6000);
    printf("\nRank 2 = %d", rank);
    rank = binary_search(array2, 0, 10, 5);
    printf("\nRank 3 = %d", rank);

    printf("\n");
}
