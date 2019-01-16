/**
 *
 * File: print_ascii_table.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-16
 * Time: 19:39
 *
 */

#include <stdio.h>

int main()
{
    int i;

    for(i=33; i<128; i++) {
        printf("%d %c\t", i, i);

        if(i%6 == 0) {
            printf("\n");
        }
    }

    return 0;
}