#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct osoba* Pozicija;

struct osoba {
    char ime[50];
    char prezime[50];
    int godina;
    struct osoba * next;
};

void Ispis(struct osoba *P){
    printf("\nIspis liste: \n");
    P = P->next;
    while(P!=NULL)
    {
        printf("%s %s %d \n", P->ime, P->prezime, P->godina);
        P = P->next;
    }
}

Pozicija Trazi(struct osoba *P, char* prez){
    while (P != NULL && strcmp(P->prezime, prez))
        P = P->next;
    return P;
    
}

void UnosP(struct osoba *P){
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

void UnosK(struct osoba *P){
    struct osoba* q;
    q = (struct osoba*)malloc(sizeof(struct osoba));
    printf("Unesi ime: \n");
    scanf("%s", q->ime);
    printf("Unesi prezime: \n");
    scanf("%s", q->prezime);
    printf("Unesi godinu rodenja: \n");
    scanf("%d", &q->godina);
    
    while(P->next != NULL)
        P = P->next;
    
    q->next = P->next;
    P->next = q;
}

int main(){
    struct osoba head;
    Pozicija temp;
    head.next = NULL;
    UnosP(&head);
    Ispis(&head);
    UnosK(&head);
    Ispis(&head);
    printf("Trazeni element je: %s %s %d",Trazi(&head,"m")->ime, Trazi(&head,"m")->prezime, Trazi(&head,"m")->godina);
    return 0;
}
























