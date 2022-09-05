#include <stdio.h>
#include <stdlib.h>

/**
 * main - make stuff up
 *
 * return: as usual ,0
 */

int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;

	printf("$ ");
	if (getline(&buffer, &len, stdin) > 0)
	{
		printf("%s", buffer);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}
