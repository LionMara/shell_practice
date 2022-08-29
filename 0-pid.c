#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: always a 0
 */
int main(void)
{
	pid_t my_pid, parent_pid;

	my_pid = getpid();
	parent_pid = getppid();
	printf("PID: %u\n", my_pid);
	printf("PPID: %u\n", parent_pid);

	return (0);
}
