/* Christopher Liu */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	FILE * file_var = fopen("averagestd.txt", "r");
	float distance_sum = 0, total = 0;
	int conv = 1, count = 0;
	while (!feof(file_var))
	{
		conv = fscanf(file_var, "%*f");
		count++;
	} 	
	fseek (file_var, 0, SEEK_SET);
	float num_list[count];

	for (int i = 0; i < count; i++)
	{
		fscanf(file_var, "%f", &num_list[i]);
		total += num_list[i];
	}
	float avg = total/count;
	for (int i = 0; i < count; i++)
	{
		distance_sum += (float) fabs((avg - num_list[i])*(avg - num_list[i]));
	}
	float std = sqrt(distance_sum/count);
	printf("AVG: %f, TOTAL: %f, COUNT: %d, STD: %f", avg, total, count, std);
	
	fclose(file_var);
}

