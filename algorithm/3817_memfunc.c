#if 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_M 100000

typedef struct var {
	int addr;
	int size;
}Var;

typedef struct mem {
	int addr;
	int avail;
}t_mem;

typedef struct list {
	t_mem data;
	struct list* next;
}t_list;

t_list head;
//int mem[MAX_M+2];
Var var[MAX_M+2];
char cmd[25];
int N;

unsigned long hash(unsigned char* str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = hash * 33 + c;
	return hash;
}

int Get_var(char *str, int *size)
{
	char var[5];

	if (strstr(str, "malloc")) {
		strncpy(var, str, 4);
		var[4] = '\0';
		*size = atoi(str + 12);
	}
	else {
		strncpy(var, str + strlen(str) - 6, 4);
		var[4] = '\0';
	}
	return hash(var) % MAX_M;
}

int Malloc(int key, int size)
{
	t_list *cur = &head;

	while(cur->next) {
		if (cur->next->data.avail == size) {
			var[key].addr = cur->next->data.addr;
			var[key].size = size;
			//free
			cur->next = cur->next->next;
			return 1;
		}
		else if (cur->next->data.avail > size) {
			var[key].addr = cur->next->data.addr;
			var[key].size = size;
			cur->next->data.addr = cur->next->data.addr + size;
			cur->next->data.avail = cur->next->data.avail - size;
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

int Free(int key)
{
	t_list *temp;
	t_list *cur;
	int s = var[key].addr;
	//int size = var[key].size;

	if (s == 0) return 0;
	temp = calloc(1, sizeof(t_list));
	temp->data.addr = s;
	temp->data.avail = var[key].size;
	
	cur = &head;
	while (cur->next) {
		if (cur->next->data.addr > s) {
			temp->next = cur->next;
			cur->next = temp;
			if (temp->data.addr + temp->data.avail == temp->next->data.addr) {
				temp->data.avail += temp->next->data.avail;
				//free;
				temp->next = temp->next->next;
			}
			var[key] = (Var) { 0, 0 };
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}


void Do(void)
{
	int key, size;

	memset(cmd, 0, 25);
	scanf("%s", cmd);
	key = Get_var(cmd,&size);
	if (strstr(cmd, "malloc")) {
		Malloc(key,size);
	}
	else if (strstr(cmd, "print")) {
		printf("%d\n", var[key].addr);
	}
	else if (strstr(cmd, "free")) {
		Free(key);
	}
}

int main(void)
{
	scanf("%d", &N);
	head.next = calloc(1,sizeof(t_list));
	head.next->data = (t_mem) { 1, MAX_M };
	for (int i = 0; i < N; i++) {
		Do();
	}
	return 0;
}
#endif


#if 0

#if 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_M 100000

typedef struct var {
	int addr;
	int size;
}Var;

typedef struct mem {
	int addr;
	int avail;
}t_mem;

typedef struct list {
	t_mem data;
	struct list* next;
}t_list;

t_list head;
//int mem[MAX_M+2];
Var var[MAX_M + 2];
char cmd[25];
int N;

unsigned long hash(unsigned char* str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = hash * 33 + c;
	return hash;
}

int Get_var(char *str, int *size)
{
	char var[5];

	if (strstr(str, "malloc")) {
		strncpy(var, str, 4);
		var[4] = '\0';
		*size = atoi(str + 12);
	}
	else {
		strncpy(var, str + strlen(str) - 6, 4);
		var[4] = '\0';
	}
	return hash(var) % MAX_M;
}

int Malloc(int key, int size)
{
	t_list *cur = head.next;

	while (cur) {
		if (cur->data.avail >= size) {
			var[key].addr = cur->data.addr;
			var[key].size = size;
			cur->data.addr = cur->data.addr + size;
			cur->data.avail = cur->data.avail - size;
		}
		cur = cur->next;
	}
	return 0;


	/*
	int i, j, s, e;

	for (i = 1; i < MAX_M; i++) {
		if (mem[i] == 1) continue;
		s = i;
		for (e = i + 1; e < MAX_M && e - s < size; e++) {
			if (mem[e] == 1) {
				i = e;
				break;
			}
		}
		if (e - s >= size) {
			for (j = s; j < e; j++) mem[j] = 1;
			var[key].addr = s;
			var[key].size = size;
			return 1;
		}
	}
	var[key].addr = 0;
	return 0;
	*/
}

int Free(int key)
{
	t_list *temp;
	t_list *cur;
	int s = var[key].addr;
	//int size = var[key].size;

	if (s == 0) return 0;
	temp = calloc(1, sizeof(t_list));
	temp->data.addr = s;
	temp->data.avail = var[key].size;

	cur = &head;
	while (cur->next) {
		if (cur->next->data.addr > s) {
			temp->next = cur->next;
			cur->next = temp;
			if (temp->data.addr + temp->data.avail == temp->next->data.addr) {
				temp->data.avail += temp->next->data.avail;
				//free;
				temp->next = temp->next->next;
			}
		}
		cur = cur->next;
	}
	var[key] = (Var) { 0, 0 };
	return 1;
}


void Do(void)
{
	int key, size;

	memset(cmd, 0, 25);
	scanf("%s", cmd);
	key = Get_var(cmd, &size);
	if (strstr(cmd, "malloc")) {
		Malloc(key, size);
	}
	else if (strstr(cmd, "print")) {
		printf("%d\n", var[key].addr);
	}
	else if (strstr(cmd, "free")) {
		Free(key);
	}
}

int main(void)
{
	scanf("%d", &N);
	head.next = calloc(1, sizeof(t_list));
	head.next->data = (t_mem) { 1, MAX_M };
	for (int i = 0; i < N; i++) {
		Do();
	}
	return 0;
}
#endif


#endif