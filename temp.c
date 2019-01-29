/**
 *
 * File: temp.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-21
 * Time: 18:33
 *
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char a[10], b[10];

    printf("Give a: ");
    scanf("%s", a);
    printf("Give b: ");
    scanf("%s", b);

    if (strcmp(a,b)>0) {
        printf("ο α %s ειναι μεγαλύτερος από %s %d", a, b, strcmp(a,b));

    }

    return 0;
}