#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - main function
 *
 * return: nothing
 */

int main(void)
{
	pid_t child_pid;
	int status;

	if ((child_pid = fork()) < 0)
	{
		perror("Error:");
		return (1);
	}
	else if ((child_pid = fork()) == 0)
	{
		printf("Wait for me, wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh. it's all better now\n");
	}
	return (0);
}
