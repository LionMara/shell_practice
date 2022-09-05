#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: always 0
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *new_environ[] = { NULL };

	printf("Before execve\n");
	if (execve(argv[0], argv, new_environ) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
