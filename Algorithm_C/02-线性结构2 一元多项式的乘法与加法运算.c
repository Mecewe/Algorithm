#include <stdio.h>
#include <stdlib.h>

typedef struct LNode *List;
struct LNode
{
	int coef;
	int expon;
	List Next;
};

List ReadPoly();
void Attach(int, int, List *);
List Add(List, List);
void PrintN(List);
List Mult(List, List);

int main()
{
	List p1,p2,PA,PM;

	p1 = ReadPoly();
	p2 = ReadPoly();
	PA = Add(p1, p2);
	PM = Mult(p1, p2);
	PrintN(PM);
	PrintN(PA);
	return 0;
}

List ReadPoly()
{
	List P, Rear, t;
	int c,e,n;
	scanf("%d", &n);
	P = (List)malloc(sizeof(struct LNode));
	P->Next = NULL;
	Rear = P;
	while (n-->0)
	{
		scanf("%d %d", &c, &e);
		Attach(c, e, &Rear);
	}
	t = P; P = P->Next; free(t);
	return P;
}

void Attach(int c, int e , List *pRear)
{
	List P;
	P = (List)malloc(sizeof(struct LNode));
	P->coef = c;
	P->expon = e;
	P->Next = NULL;
	(*pRear)->Next = P;
	*pRear = P;
}

List Add(List p1, List p2)
{
	List P,t1,t2,Rear,t;
	t1 = p1; t2 = p2;
	P = (List)malloc(sizeof(struct LNode));
	P->Next = NULL;
	Rear = P;
	while (t1&&t2)
	{
		if (t1->expon > t2->expon){
			Attach(t1->coef, t1->expon, &Rear);
			t1 = t1->Next;
		}
		else if (t1->expon < t2->expon)
		{
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->Next;
		}
		else if (t1->expon == t2->expon)
		{
			if (t1->coef + t2->coef){
				Attach(t1->coef + t2->coef, t1->expon, &Rear);
			}
			t1 = t1->Next;
			t2 = t2->Next;
		}
	}
	while (t1){
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->Next;
	}
	while (t2){
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->Next;
	}
	t = P; P = P->Next; free(t);
	return P;
}

List Mult(List p1, List p2)
{
	List P, Rear, t1, t2, t;
	if (!p1||!p2){
		return NULL;
	}
	t1 = p1;
	t2 = p2;
	P = (List)malloc(sizeof(struct LNode));
	Rear = P;
	while (t2)
	{
		Attach(t1->coef*t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while (t1)
	{
		t2 = p2;
		Rear = P;
		while (t2)
		{
			int c = t1->coef*t2->coef;
			int e = t1->expon + t2->expon;
			while (Rear->Next&&Rear->Next->expon>e)
			{
				Rear = Rear->Next;
			}
			if (Rear->Next&&Rear->Next->expon == e){
				if (Rear->Next->coef + c){
					Rear->Next->coef += c;
				}
				else
				{
					t = Rear->Next;
					Rear->Next = t->Next;
					free(t);
				}
			}
			else
			{
				t = (List)malloc(sizeof(struct LNode));
				t->coef = c;
				t->expon = e;
				t->Next = Rear->Next;
				Rear->Next = t;
				Rear = Rear->Next;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
	t2 = P;
	P = P->Next;
	free(t2);
	return P;
}

void PrintN(List P)
{
	int flag=0;
	if (!P)
	{
		printf("0 0\n"); /*¸ñÊ½*/
		return;
	}
	while (P)
	{
		if (!flag){
			flag = 1;
		}
		else
		{
			printf(" ");
		}
		printf("%d %d", P->coef, P->expon);
		P = P->Next;
	}
	printf("\n");
	return;
}
