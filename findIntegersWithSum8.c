/**
 *
 * File: findIntegersWithSum8.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-16
 * Time: 19:57
 *
 * Άσκηση 1Α, 3ης εργασίας 2016-2017
 *
 * Να γραφεί πρόγραμμα στη γλώσσα προγραμματισμού C, το οποίο βρίσκει όλες τις πιθανές τριάδες
 * θετικών ακέραιων αριθμών (a, b, c), των οποίων το άθροισμα είναι 8.
 *
 */

#include <stdio.h>

#define TARGET_SUM 8

int main()
{

    int a, b, c;
    int sum;
    int maxSearchLimit;

    maxSearchLimit = TARGET_SUM - 2;

    for(a=1; a<=maxSearchLimit; a++) {
        for(b=1; b<=maxSearchLimit; b++) {
            for(c=1; c<=maxSearchLimit; c++) {
                sum = a + b + c;

                if(sum == TARGET_SUM) {
                    printf("%d + %d + %d = %d\n", a, b, c, sum);
                }

            }
        }
    }

    return 0;
}

