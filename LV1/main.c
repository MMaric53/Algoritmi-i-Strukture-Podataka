#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {

    char ime[20];
    char prezime[20];
    int bodovi;
};

int main() {

    FILE* fp;
    fp = fopen("studenti.txt", "r");

    if (fp == NULL) {
        printf("Error");
        return 1;
    }
    
    int c = 0;
    char myString[50];

    while (fgets(myString, 50, fp) != NULL) {
        c = c + 1;
    }

    rewind(fp);

    struct student* s = malloc(c * sizeof(struct student));

    if (s == NULL) {
        printf("Error");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < c; i++) {
        fscanf(fp, "%19s %19s %d",
            s[i].ime, s[i].prezime, &s[i].bodovi);
    }

    for (int i = 0; i < c; i++) {
        printf("%s %s %d %lf\n",
            s[i].ime,
            s[i].prezime,
            s[i].bodovi,
            s[i].bodovi / 25.0 * 100);
    }

    free(s);

    fclose(fp);
    
    return 0;
}
