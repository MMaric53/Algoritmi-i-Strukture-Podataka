#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Position;

struct Node
{
	int el;
	struct Node* next;
};

void EnterList(Position head)
{
	Position temp = head;
	int n, i;
	printf("Unesi broj elemenata: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		Position q = (Position)malloc(sizeof(struct Node));
		printf("Unesi element %d: ", i + 1);
		scanf("%d", &q->el);
		q->next = NULL;
		temp->next = q;
		temp = q;
	}
}

void printList(Position head)
{
	Position temp = head->next;
	while (temp != NULL)
	{
		printf("%d ", temp->el);
		temp = temp->next;
	}
	printf("\n");
}

void Union(Position h1, Position h2, Position hr)
{
	Position temp, q;
	int temp_el = 0;

	while (h1 != NULL && h2 != NULL)
	{
		if(h1->el > h2->el)
		{ 
			temp_el = h2->el;
			h2 = h2->next;
		}
		else if(h1->el < h2->el){

			temp_el = h1->el;
			h1 = h1->next;
		}
		else
		{
			temp_el = h1->el;
			h1 = h1->next;
			h2 = h2->next;
		}

		q = (Position)malloc(sizeof(struct Node));
		if (q == NULL)
		{
			printf("Greska\n");
		}
		else
		{
			q->el = temp_el;
			q->next = hr->next;
			hr->next = q;
			hr = q;
		}
	}

	if (h1 == NULL)
	{
		temp = h2;
	}
	else
	{
		temp = h1;
	}

	while (temp != NULL)
	{
		q = (Position)malloc(sizeof(struct Node));
		if (q == NULL)
		{
			printf("Greska\n");
		}
		else
		{
			q->el = temp->el;
			q->next = hr->next;
			hr->next = q;
			hr = q;
		}
		
		temp = temp->next;
	}
	
}

void Presjek(Position h1, Position h2, Position hr)
{
	Position temp, q;
	int temp_el = 0;

	while (h1 != NULL && h2 != NULL)
	{
		if (h1->el > h2->el)
		{
			h2 = h2->next;
		}
		else if (h1->el < h2->el) {

			h1 = h1->next;
		}
		else
		{
			temp_el = h1->el;
			h1 = h1->next;
			h2 = h2->next;

			q = (Position)malloc(sizeof(struct Node));
			if (q == NULL)
			{
				printf("Greska\n");
			}
			else
			{
				q->el = temp_el;
				q->next = hr->next;
				hr->next = q;
				hr = q;
			}
		}

	}

}

int main()
{
	Position headL1, headL2, headU, headP;

	headL1 = (Position)malloc(sizeof(struct Node));
	EnterList(headL1);
	printList(headL1);

	headL2 = (Position)malloc(sizeof(struct Node));
	EnterList(headL2);
	printList(headL2);

	headU = (Position)malloc(sizeof(struct Node));
	headU->next = NULL;

	headP = (Position)malloc(sizeof(struct Node));
	headP->next = NULL;

	printf("Unija unesenih listi je: ");
	Union(headL1, headL2, headU);
	printList(headU->next);

	printf("Presjek unesenih listi je: ");
	Presjek(headL1, headL2, headP);
	printList(headP->next);

	return 0;
}


