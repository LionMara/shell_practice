#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", av[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(av[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while((nread = getline(&line, &len, stream)) != -1)
	{
		printf("Retrieved line of length %zd:\n", nread);
		fwrite(line, nread, 1, stdout);
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
