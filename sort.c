#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));

	size_t size;
	printf("NUMBER: ");
	scanf("%d", &size);
	int* num_list = (int*) malloc(size*sizeof(int));
	printf("%d", (sizeof(num_list)/sizeof(num_list[0])));
	for (int i = 0; i <  size; i++)
	{
		num_list[i] = rand();
		printf("%d, num_list[i]\n", num_list[i]);
	}
	int* as_sort = (int*) malloc((size+1)*sizeof(int));
	for (int i = 0; i < size; i++)
	{
		as_sort[i] = num_list[i];
	}
	for (int i = size-1; i <= 0; i--)
	{
		int key =  i;
		int j = as_sort[i-1];
		while (i < j)
		{
			as_sort[i] = as_sort[j];
			i--;
			j--;
			for (int printi = 0; printi < size+1; i++)
			{
				printf("|%d", as_sort[printi]);
			}
			printf("\n");
		}
	}

	return 0;
}
