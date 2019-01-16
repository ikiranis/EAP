/**
 *
 * File: XORLogic.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-16
 * Time: 21:36
 *
 * Άσκηση 1Β, 3ης εργασίας 2016-2017
 *
 * Να γραφεί πρόγραμμα στη γλώσσα προγραμματισμού C, το οποίο διαβάζει τις τιμές των εισόδων
 * A, B και C λογικού κυκλώματος και εμφανίζει την τιμή της εξόδου (A XOR B) XOR C.
 * Το πρόγραμμα πρέπει να ελέγχει εάν οι τιμές των A, B και C είναι έγκυρες και,
 * σε αντίθετη περίπτωση, να επαναλαμβάνει την ανάγνωση.
 *
 */

#include <stdio.h>

int main()
{
    int A, B,C, output;

    do {
        printf("Give A input: ");
        scanf("%d", &A);
    } while (A < 0 || A > 1);

    do {
        printf("Give B input: ");
        scanf("%d", &B);
    } while (B < 0 || B > 1);

    do {
        printf("Give C input: ");
        scanf("%d", &C);
    } while (C < 0 || C > 1);

    output = (A ^ B) ^ C;

    printf("(%d XOR %d) XOR %d = %d\n", A, B, C, output);


    return 0;

}