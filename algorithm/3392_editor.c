#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct lst
{
	char c;
	struct lst * next;
	struct lst * prev;
}lst;

char input[100005];
int N;
lst head;
lst tail;
lst * cur;

int Insert_node(char c)
{
	lst * p;
	if ((p = calloc(1, sizeof(lst))) == NULL) return -1;
	p->c = c;
	p->next = cur;
	p->prev = cur->prev;
	p->prev->next = p;
	p->next->prev = p;
	return 1;
}

int Delete_node(void)
{
	lst * p = cur->prev;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
	return 1;
}

void print_node(lst *p) {
	while (p->next) {
		printf("%c", p->c);
		p = p->next;
	}
}

int main(void)
{
	int i;
	char t[2];

	scanf("%s", input);
	tail.prev = &head;
	head.next = &tail;
	cur = &tail;

	for (i = 0; input[i]; i++) {
		Insert_node(input[i]);
	}
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf(" %c", &t[0]);
		if (t[0] == 'P') {
			scanf(" %c", &t[1]);
			Insert_node(t[1]);
		}
		else if (t[0] == 'L') {
			if (cur->prev != &head) cur = cur->prev;
		}
		else if (t[0] == 'D') {
			if (cur->next != &tail) cur = cur->next;
		}
		else if (t[0] == 'B') {
			if (cur->prev != &head) Delete_node();
		}
	}
	print_node(head.next);
	return 0;
}

#endif
