#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*  define macros */
#define MAX_COUNT 200
#define BUF_SIZE 100

/*prototype for child_process*/
void child_process(char [], char []);
/**
 * main - main function,
 *
 * Return: 0
 */
void main(void)
{
	pid_t pid1, pid2, pid; /* declare PID vars */
	int status;
	int i;
	char buf[BUF_SIZE]; /* declare array of size 100*/

	printf("*** Parent is about to fork process 1 ***\n");
	/*creates a child process using the fork()
	 *prints something incase of failure
	 *fork() returns cp and 0
	 */
	if ((pid1 = fork()) < 0)
	{
		printf("Failed to fork process 1\n");
		exit(1);
	}
	/* when the fork is succesful it returns 0 to the child
	 * in here the child_process func is called
	 * with two strings to be passed
	 */
	else if (pid1 == 0)
		child_process("First", "   "); /* two strings are passed*/

	printf("***Parent is about to fork process 2 ***\n");
	/* forks a second child
	 * this if statement checks for failure
	 */
	if((pid2 = fork()) < 0)
	{
		printf("Faild to fork process 2 ***\n");
		exit(1);
	}
	/* when the second pid is formed
	 * the following strings are passed in
	 */
	else if (pid2 == 0)
		child_process("Second", "      ");

	sprintf(buf, "*** Parent enters waiting status ....\n");
	write(STDOUT_FILENO, buf, strlen(buf)); /* write to stdout*/
	pid = wait(&status);
	sprintf(buf, "***Parent detects process %d is done ***\n", pid);
	write(STDOUT_FILENO,  buf, strlen(buf));
	/* wait returns terminated cp's PID
	 * OR -1 ON FAILURE
	 */
	pid = wait(&status);
	printf("***Parent detects process %d is done **\n", pid);
	printf("*** Parentexits ***\n");
	exit(0);
}

void child_process(char *number, char *space)
{
	pid_t pid;
	int i;
	char buf[BUF_SIZE];

	pid = getpid(); /* parent ID*/
	sprintf(buf, "%s%s child process starts (pid = %d)\n",
		space, number, pid);
	write(STDOUT_FILENO, buf, strlen(buf));

	/* for loop running for 200 times
	 */
	for (i = 1; i <= MAX_COUNT; i++)
	{
		sprintf(buf, "%s%s childs's output, value = %d\n",
			space, number, i);
		write(STDOUT_FILENO, buf, strlen(buf));
	}
	sprintf(buf, "%s%s child (pid = %d) is about to exit\n",
		space, number, pid);
	write(STDOUT_FILENO, buf, strlen(buf));
	exit(0);
}
