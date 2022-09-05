#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prints all args without using ac
 *
 * Return: 0
 */

int main(/*__attribute__((unused))*/int ac, char **av)
{
	int i;
	i = 1;


	if (av[1] == NULL)
	{
		printf("No arg passed\n");
		exit(1);
	}


	while (av[i] != NULL)
	{
		printf(" %s", av[i]);
		i++;
	}
	putchar('\n');
	return (0);
}
