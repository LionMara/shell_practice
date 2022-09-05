#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 0, j;
	const int num_of_strings = 128;
	char *str_array[num_of_strings];
	char writable_string[] = "The C programming Language";
	char *token = strtok(writable_string, " ");

	for (j = 0; j < num_of_strings; j++)
	{
		str_array[j] = new char[40];
	}

	while (token != NULL)
	{
		strcpy(str_array[i], token);
		printf("[%s]\n", token);
		token = strtok(NULL, " ");
		i++;
	}
	return (0);
}
