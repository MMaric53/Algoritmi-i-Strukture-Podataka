#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct osoba* Pozicija;

struct osoba {
    char ime[50];
    char prezime[50];
    int godina;
    struct osoba* next;
};

void Ispis(struct osoba* P) {
    printf("\nIspis liste: \n");
    P = P->next;
    while (P != NULL)
    {
        printf("%s %s %d \n", P->ime, P->prezime, P->godina);
        P = P->next;
    }
}

Pozicija Trazi(struct osoba* P, char* prez) {
    while (P != NULL && strcmp(P->prezime, prez))
        P = P->next;
    return P;

}

void UnosP(struct osoba* P) {
    struct osoba* q;
    q = (struct osoba*)malloc(sizeof(struct osoba));
    printf("Unesi ime: \n");
    scanf("%s", q->ime);
    printf("Unesi prezime: \n");
    scanf("%s", q->prezime);
    printf("Unesi godinu rodenja: \n");
    scanf("%define", &q->godina);

    q->next = P->next;
    P->next = q;
}

void UnosK(struct osoba* P) {
    struct osoba* q;
    q = (struct osoba*)malloc(sizeof(struct osoba));
    printf("Unesi ime: \n");
    scanf("%s", q->ime);
    printf("Unesi prezime: \n");
    scanf("%s", q->prezime);
    printf("Unesi godinu rodenja: \n");
    scanf("%d", &q->godina);

    while (P->next != NULL)
        P = P->next;

    q->next = P->next;
    P->next = q;
}

void UnosNakon(struct osoba* P, char* prez) {
    struct osoba* q;
    q = (struct osoba*)malloc(sizeof(struct osoba));
    printf("Unesi ime: \n");
    scanf("%s", q->ime);
    printf("Unesi prezime: \n");
    scanf("%s", q->prezime);
    printf("Unesi godinu rodenja: \n");
    scanf("%d", &q->godina);

    P = Trazi(P, prez);

    q->next = P->next;
    P->next = q;
}

void UnosPrije(struct osoba* P, char* prez) {
    struct osoba* q;
    q = (struct osoba*)malloc(sizeof(struct osoba));
    printf("Unesi ime: \n");
    scanf("%s", q->ime);
    printf("Unesi prezime: \n");
    scanf("%s", q->prezime);
    printf("Unesi godinu rodenja: \n");
    scanf("%d", &q->godina);

    P->next = Trazi(P, prez);

    q->next = P->next;
    P->next = q;
}

void Sort(Pozicija P)
{
    Pozicija j, prev_j, temp, end;

    end = NULL;
    while (P->next != end) {
        prev_j = P;
        j = P->next;

        while (j->next != end) {
            if (strcmp(j->prezime, j->next->prezime) > 0) {
                temp = j->next;
                prev_j->next = temp;
                j->next = temp->next;
                temp->next = j;
                j = temp;
            }

            prev_j = j;
            j = j->next;
        }
        end = j;
    }
}

int UpisiUDatoteku(Pozicija P)
{
    FILE* fp;
    fp = fopen("datoteka.txt", "w");
    if (fp == NULL)
    {
        printf("Otvaranje nije uspjelo!");
        return 1;
    }
    while (P != NULL) {
        fprintf(fp, "%s %s %d\n", P->ime, P->prezime, P->godina);
        P = P->next;
    }

    fclose(fp);
    return 0;
}

int ProcitajIzDatoteke(Pozicija P)
{
    char* ime;
    char* prezime;
    int godina;

    struct osoba* q;
    q = (struct osoba*)malloc(sizeof(struct osoba));
    q = q->next;
    FILE* fp;
    fp = fopen("datoteka.txt", "w");
    if (fp == NULL)
    {
        printf("Otvaranje nije uspjelo!");
        return 1;
    }
    while (fscanf(fp, "%49s %49s %d", q->ime, q->prezime, &q->godina) == 3) {
        q=q->next;
        
    }

    fclose(fp);
    return 0;
}


int main() {
    struct osoba head;
    head.next = NULL;
    UnosP(&head);
    Ispis(&head);
    UnosK(&head);
    Ispis(&head);
    printf("Trazeni element je: %s %s %d \n", Trazi(&head, "m")->ime, Trazi(&head, "m")->prezime, Trazi(&head, "m")->godina);
    UnosPrije(&head, "m");
    Ispis(&head);
    UnosNakon(&head, "m");
    Ispis(&head);
    Sort(&head);
    Ispis(&head);
    UpisiUDatoteku(&head);
    ProcitajIzDatoteke(&head);
    Ispis(&head);
    return 0;
}
