#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
/**
 *  main - PID
 *  
 *  Return: Always 0.
 */
int main()
{
	pid_t  my_ppid;
	my_ppid = getppid();

	printf("%u\n", my_ppid);
	return (0);
}

