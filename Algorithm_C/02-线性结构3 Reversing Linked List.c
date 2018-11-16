/*
Tip:对于数据的存储空间依然较为浪费 
*/

#include <stdio.h>

#define MAXSIZE 100002

typedef int Ptr;
struct node{
	int key;
	Ptr next;
}List[MAXSIZE];
void PrintList();

Ptr Reverse(Ptr head, int k)
{
	Ptr New, Old, Temp;
	int count = 1;
	New = head;
	Old = List[New].next;
	while (count < k){
		Temp = List[Old].next;
		List[Old].next = New;
		New = Old;
		Old = Temp;
		count++;
	}
	List[head].next = Old;
	return New;
}

void ReversingLinkList(int N,int k)
{
	int count = 0;
	Ptr head, tail = 100001, temp;
	if (k == 1) return;
	head = List[100001].next;
	for (temp = List[100001].next; List[temp].next != -1; temp = List[temp].next){
		count++;
		if (count % k == 0){
			List[tail].next = Reverse(head,k);
			tail = head;
			head = List[tail].next;
			temp = tail;
		}
	}
	//针对于刚好全部需要反转的情况 
	count++;
	if (count % k == 0){
		List[tail].next = Reverse(head, k);
		tail = head;
		head = List[tail].next;
	}
	return;
}

void PrintList()
{
	Ptr temp;
	for (temp = List[100001].next; List[temp].next != -1; temp = List[temp].next){
		printf("%05d %d %05d\n", temp, List[temp].key, List[temp].next);
	}
	printf("%05d %d %d\n", temp, List[temp].key, List[temp].next);
	return;
}

int main()
{
	int i, N, k,add;
	scanf("%d %d %d", &List[100001].next, &N, &k);
	for (i = 0; i < N; i++){
		scanf("%d", &add);
		scanf("%d %d", &List[add].key, &List[add].next);
	}
	ReversingLinkList(N,k);
	PrintList();
	return 0;
}

