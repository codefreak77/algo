#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pattern_search(char text[], int len_t, char pat[], int p_len)
{
    int i = 0, j = 0;

    printf("\ntext = %s pattern %s\n", text, pat);
    for (i=0; i<len_t; i++) {
        //printf("\n text %c pat %c j %d", text[i], pat[j], j);
        if (text[i] == pat[j]) {
            //printf("\n Match!");
            j++;
            if (j == p_len) {
                printf("\nMatch found at index %d\n", (i + 1 - p_len));
                j = 0;
            }
        } else {
            j = 0;
        }
    } /* end of for loop */
}


main()
{
    char text[] = "THIS TEST IS A TEST TEXT INSIDE A TEST CASE";
    char pattern[] = "TEST";
    printf("\nPattern maching start\n");

    pattern_search(text, strlen(text), pattern, strlen(pattern));

    printf("\nPattern maching end\n");
}
