/**
 *
 * File: displayStringOnlyWithLatinChars.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-16
 * Time: 22:55
 *
 * Άσκηση 2Α, 3ης εργασίας 2016-2017
 *
 * Να γραφεί πρόγραμμα στη γλώσσα προγραμματισμού C, το οποίο ζητά από τον χρήστη να δώσει μία ακολουθία χαρακτήρων
 * που αποτελείται από (πεζά ή κεφαλαία) γράμματα του λατινικού αλφαβήτου. Σε περίπτωση εισαγωγής
 * αριθμών ή συμβόλων ή του κενού το πρόγραμμα να τα αγνοεί. Η εισαγωγή της ακολουθίας χαρακτήρων
 * ολοκληρώνεται με Enter και στη συνέχεια, το πρόγραμμα πρέπει να εκτυπώνει τα γράμματα που εμφανίζονται στη
 * λέξη και το πλήθος εμφάνισής τους, με αλφαβητική σειρά, χωρίς να κάνει διάκριση πεζών- κεφαλαίων
 *
 */

#include <stdio.h>

int getCharAsciiNumberDifference(int theChar);

int main()
{
    int i;
    int theChar;
    int charsFrequency[50];

    for(i=0; i<50; i++) {
        charsFrequency[i] = 0;
    }

    printf("Δώσε μια ακολουθία χαρακτήρων: ");

    do {
        theChar = getchar();

        if( (theChar>=65 && theChar<=90) || (theChar>=97 && theChar<=122) ) {
            printf("%c", theChar);

            charsFrequency[theChar - getCharAsciiNumberDifference(theChar)]++;
        }

    } while (theChar != '\n');

    printf("\n");

    for(i=0; i<50; i++) {
        if(charsFrequency[i] != 0) {
            printf("%c (%d) -> %d\n", i + getCharAsciiNumberDifference(i), getCharAsciiNumberDifference(i) + i,
                    charsFrequency[i]);
        }
    }


    return 0;
}

/**
 * Convert ascii number to start from 0
 *
 * @param theChar
 * @return
 */
int getCharAsciiNumberDifference(int theChar)
{
    if(theChar>=65 && theChar<=90) {
        return 66;
    } else {
        return 73;
    }
}
