#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HT (1<<14)
#define MOD (MAX_HT-1)

typedef struct candi {
	int id;
	int score;
	char name[20 + 1];
}Candi;

typedef struct list {
	Candi * data;
	struct list *next;
}t_list;

int N,M;
t_list table[MAX_HT];
Candi candi[10000 + 5];

unsigned long hash(unsigned char* str)
{
	unsigned long hash = 5381;
	while (*str)
		hash = hash * 33 + *str++;
	return hash & MOD;
}

int addlist(unsigned long key, Candi *s)
{
	int ret;
	t_list *head = &table[key];
	t_list *temp = calloc(1, sizeof(t_list));

	while (head->next) {
		ret = strcmp(head->next->data->name, s->name);
		if (ret > 0) break;
		head = head->next;
	}
	temp->next = head->next;
	temp->data = s;
	head->next = temp;
	return 1;
}

int vote(unsigned long key, char *s, int score)
{
	int ret;
	t_list *head = &table[key];
	while (head->next) {
		ret = strcmp(head->next->data->name, s);
		if (ret == 0) {
			head->next->data->score += score;
			return 1;
		}
		else if (ret > 0) break;
		head = head->next;
	}
	return -1;
}

int Comp(Candi* c1, Candi* c2)
{
	if (c1->score < c2->score) return 1;
	else if (c1->score == c2->score) {
		if (c1->id > c2->id) return 1;
		else return 0;
	}
	else return 0;
}

int main(void)
{
	int i,n;
	char temp[21];
	unsigned long key;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", temp);
		candi[i].id = i;
		strcpy(candi[i].name, temp);
		key = hash(temp);
		addlist(key, &candi[i]);
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%s %d", temp, &n);
		key = hash(temp);
		vote(key, temp, n);
	}
	qsort(candi, N, sizeof(Candi), Comp);
	for (i = 0; i < 3; i++) {
		printf("%s %d\n", candi[i].name, candi[i].score);
	}
}

#endif
