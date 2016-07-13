/* Christopher Liu */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printlist(int * list, int size)
{
	printf("LIST: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}

int main()
{
	srand(time(NULL));

	int size;
	printf("NUMBER: ");
	scanf("%d", &size);
	int* num_list = (int*) malloc(size*sizeof(int));
	for (int i = 0; i <  size; i++)
	{
		num_list[i] = rand()%40;
	}
	int* as_sort = (int*) malloc((size+1)*sizeof(int));
	int* de_sort = (int*) malloc((size+1)*sizeof(int));
	for (int i = 0; i < size; i++)
	{
		as_sort[i] = num_list[i];
		de_sort[i] = num_list[i];
	}

	for (int i = 1; i < size; i++)
	{
		int key =  as_sort[i];
		int j = i-1;
		while (key < as_sort[j])
		{
			as_sort[i] = as_sort[j];
			i--;
			j--;
		}
		as_sort[i] = key;
	}
		for (int i = 1; i < size; i++)
	{
		int key =  de_sort[i];
		int j = i-1;
		while (key > de_sort[j] && i > 0)
		{
			de_sort[i] = de_sort[j];
			i--;
			j--;
		}
		de_sort[i] = key;
	}
	printf("NUMLIST: ");
	printlist(num_list, size);
	printf("AS_SORT: ");
	printlist(as_sort, size);
	printf("DE_SORT: ");
	printlist(de_sort, size);
	free(num_list);
	free(de_sort);
	free(as_sort);

	return 0;
}
