#if 0

#include <stdio.h>
#include <stdlib.h>

typedef struct paper {
	int lx, ly;
	int rx, ry;
	int size;
	int color;
	struct paper * left;
	struct paper * right;
}t_paper;
int wid, hei;
int N;
int X[30000 + 10];
int Y[30000 + 10];
int min, max;
t_paper root;


void cut(t_paper *cur, int color, int x, int y)
{
	if (color) {
		cur->left = malloc(sizeof(t_paper));
		*cur->left = (t_paper) { cur->lx, cur->ly, cur->rx, y,
				(cur->rx - cur->lx) * (y - cur->ly), !cur->color, 0};
		cur->right = malloc(sizeof(t_paper));
		*cur->right = (t_paper) { cur->lx, y, cur->rx, cur->ry,
				(cur->rx - cur->lx) * (cur->ry - y), !cur->color, 0};
	}
	else {
		cur->left = malloc(sizeof(t_paper));
		*cur->left = (t_paper) { cur->lx, cur->ly, x, cur->ry,
				(x - cur->lx) * (cur->ry - cur->ly), !cur->color, 0};
		cur->right = malloc(sizeof(t_paper));
		*cur->right = (t_paper) { x, cur->ly, cur->rx, cur->ry,
				(cur->rx - x) * (cur->ry - cur->ly), !cur->color, 0};
	}
}

void check(int x, int y)
{
	t_paper *temp = &root;
	while (temp->left || temp->right) {
		if (temp->left) {
			if (x >= temp->left->lx && x <= temp->left->rx && y >= temp->left->ly && y <= temp->left->ry) {
				temp = temp->left;
				continue;
			}
		}
		if (temp->right) {
			if (x >= temp->right->lx && x <= temp->right->rx && y >= temp->right->ly && y <= temp->right->ry) {
				temp = temp->right;
				continue;
			}
		}
	}
	cut(temp, temp->color, x, y);
}

void search(t_paper *t)
{
	if (t->left == 0 && t->right == 0) {
		if (t->size > max) max = t->size;
		if (t->size < min) min = t->size;
		return;
	}
	else {
		search(t->left);
		search(t->right);
	}
}

int main(void)
{
	int i;

	scanf("%d%d", &wid, &hei);
	scanf("%d", &N);

	root = (t_paper) { 0, 0, wid, hei, wid * hei, 1, 0 };

	for (i = 0; i < N; i++) {
		scanf("%d%d", &X[i], &Y[i]);
		check(X[i], Y[i]);
	}
	max = 0;
	min = root.size;
	search(&root);
	printf("%d %d\n", max, min);
	return 0;
}

#endif