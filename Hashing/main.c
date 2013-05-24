#include <stdio.h>

int linearH(int s, int i);
int quadH(int s, int i);
int doubleH(int s, int i);
int doubleH2(int s);
void printHashTable();
void resetHash();
void compareAll();

int m = 11;
int c1 = 1;
int c2 = 3;
int hashTable[11] = {0,0,0,0,0,0,0,0,0,0,0};
int numberArray[9] = {10,22,31,4,15,28,17,88,59};

int main() {
    char menu = '1';
    int i;
    int j;
    printf("Welcome \n");
    while (menu != '0') {
        printf("\n 1. Linear Hashing \n 2. Quadratic Hashing \n 3. Double Hashing \n 4. Compare all \n 0. Exit \n \n");

        scanf(" %c", &menu);

        j = 0;

        if (menu == '1') {
            for (i = 0; i < 9; ++i) {

                while (!linearH(i, j)) {
                    ++j;
                }
            }
            printHashTable();
        } else if (menu == '2') {
            for (i = 0; i < 9; ++i) {

                while (!quadH(i, j)) {
                    ++j;
                }
            }
            printHashTable();
        } else if (menu == '3') {
            for (i = 0; i < 9; ++i) {

                while (!doubleH(i, j)) {
                    ++j;
                }
            }
            printHashTable();
        } else if (menu == '4') {
            compareAll();
        }
        resetHash();
    }

    return 0;
}

int linearH(int s, int i) {

    int pos = (numberArray[i] + i) % m;
    if (pos < 11 && hashTable[pos] == 0) {
        hashTable[pos] = numberArray[s];
        return 1;
    }

    return 0;
}

int quadH(int s, int i) {

    unsigned int pos = (numberArray[i] + c1*i + c2*(i*i)) % m; //unsigned ist wichtig sonst kann pos negativ werden (bei 59 z. B.)
    if (pos < 11 && hashTable[pos] == 0) {
        hashTable[pos] = numberArray[s];
        return 1;
    }

    return 0;
}


int doubleH(int s, int i) {
    unsigned int pos = (numberArray[i] + i*doubleH2(numberArray[i])) %m;

    if (pos < 11 && hashTable[pos] == 0) {
        hashTable[pos] = numberArray[s];
        return 1;
    }

    return 0;
}

int doubleH2(int s) {
    return 1+(s % (m-1));
}

void printHashTable() {
    int k;
    for (k = 0; k < m; ++k) {
        printf("%i: %i \n", k, hashTable[k]);
    }
}

void resetHash() {
    int k;
    for (k = 0; k < m; ++k) {
        hashTable[k] = 0;
    }
}

void compareAll() {
    int j;
    int i;
    int k;

    int linearTable[11] = {0,0,0,0,0,0,0,0,0,0,0};
    int quadTable[11] = {0,0,0,0,0,0,0,0,0,0,0};
    int doubleTable[11] = {0,0,0,0,0,0,0,0,0,0,0};

    j = 0;
    for (i = 0; i < 9; ++i) {
        while (!linearH(i, j)) {
            ++j;
        }
    }
    for (k = 0; k < m; ++k) {
        linearTable[k] = hashTable[k];
    }
    resetHash();

    j = 0;
    for (i = 0; i < 9; ++i) {
        while (!quadH(i, j)) {
            ++j;
        }
    }
    for (k = 0; k < m; ++k) {
        quadTable[k] = hashTable[k];
    }
    resetHash();

    j = 0;
    for (i = 0; i < 9; ++i) {
        while (!doubleH(i, j)) {
            ++j;
        }
    }
    for (k = 0; k < m; ++k) {
        doubleTable[k] = hashTable[k];
    }
    resetHash();
    printf("Linear    Quad      Double \n");
    for (k = 0; k < m; ++k) {
        printf("%i: %i      %i: %i     %i: %i\n", k, linearTable[k], k, quadTable[k], k, doubleTable[k]);
        printf("----------------------------\n");
    }

}
