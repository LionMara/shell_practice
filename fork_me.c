#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(void)
{
	pid_t childPID;
	int var_lcl = 0;

	childPID = fork();

	if (childPID >= 0)
	{
		if (childPID == 0)
		{
			var_lcl++;
			var_glb++;
			printf("\n Child Process :: var_lcl = [%d],"
			       "var_glb[%d]\n", var_lcl, var_glb);
		}
		else
		{
			var_lcl = 10;
			var_glb = 20;
			printf("\n Parent Process :: var_lcl = [%d],"
			       "var_glb[%d]\n", var_lcl, var_glb);
		}
	}
	else
	{
		printf("\n Fork failed!!!!\n");
		return (1);
	}
	return (0);
}
