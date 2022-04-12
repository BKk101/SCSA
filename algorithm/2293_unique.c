#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct st
{
	int id;
	int next;
}data[5] = { {0, -1}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };

int Insert(int d)
{
	// 코드작성
	int i, nex, head = 0;

	for (i = 1; i < 5; i++) {
		if (data[i].id != 0) continue;
		while ((nex = data[head].next) != -1) {
			if (data[nex].id == d) return -1;
			if (data[nex].id > d) {
				data[i].next = nex;
				data[i].id = d;
				data[head].next = i;
				return i;
			}
			head = nex;
		}
		data[i].next = nex;
		data[i].id = d;
		data[head].next = i;
		return i;
	}
	return -1; //빈방x
}

int Delete(int d)
{
	// 코드작성
	int i, nex, head = 0;
	
	for (i = 1; i < 5; i++) {
		if (data[i].id != d) continue;
		while ((nex = data[head].next) != -1) {
			if (data[nex].id == d) {
				data[head].next = data[nex].next;
				data[nex].id = 0;
				return i;
			}
			head = nex;
		}
	}
	return -1; //데이터x
}

/********************************************************************************/
/* 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지*/
/********************************************************************************/

int main(void)
{
	int i;
	int r;

	int j;

	int oper[] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,   1, 0 };
	int val[] = { 10, 5, 20, 5, 7, 8, 10, 20, 15, 80, 100, 20, 7 };
	int next[] = { -1, 1, -1, 0, 1, 0, 0, 0, 0, -1, -1,   0, 0 };
	int res[] = { 1, 2, 3, -1, 4, -1, 1, 3, -1, 1, 3,   -1, 4 };

	printf("ROOM-NO\tID\tNEXT\n");
	printf("---------------------\n");

	for (j = 0; j < 5; j++)
	{
		printf("%d\t%d\t%d\n", j, data[j].id, data[j].next);
	}

	printf("---------------------\n");

	for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
	{
		printf("TEST VECTOR [%d]\n", i);

		if (oper[i] == 1) r = Insert(val[i]);
		else r = Delete(val[i]);

		printf("ROOM-NO\tID\tNEXT\n");
		printf("---------------------\n");

		for (j = 0; j < 5; j++)
		{
			printf("%d\t%d\t%d\n", j, data[j].id, data[j].next);
		}

		printf("---------------------\n");

		if (res[i] != r)
		{
			printf(">>>>Fail: Expected Return=> %d, Your Return=> %d\n", res[i], r);
			return 0;
		}

		else
		{
			if (r == -1)
			{
				printf("return => %d\n", r);
			}

			else
			{
				printf("return => %d\n", r);

				if ((val[i] != data[r].id) && (oper[i] == 1))
				{
					printf(">>>>Fail: Expected Saved ID => %d, Your ID => %d\n", val[i], data[r].id);
					return 0;
				}

				else
				{
					if (oper[i] == 1)
					{
						printf("id => %d\n", data[r].id);
					}

					else
					{
						printf("id => %d\n", data[r].id);
					}


					if (oper[i] == 1)
					{
						if (next[i] != data[r].next)
						{
							printf(">>>>Fail: Expected next => %d, Your next => %d\n", next[i], data[r].next);
							return 0;
						}

						else
						{
							printf("next => %d\n", data[r].next);
						}
					}
				}
			}
		}
	}

	return 1;
}

#endif