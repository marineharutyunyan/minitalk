#include <signal.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

int counter = 0;
int *byte[7];

void handler0() {
	if (counter == 8)
	{
		write(1,"\n",1);
		counter = -1;
	}
	byte[counter] = 0;
	counter++;
	write(1,"0",1);
}

void handler1() 
{
	if (counter == 8)
	{
		write(1,"\n",1);
		counter = -1;
	}
	byte[counter] = 1;
	counter++;
	write(1,"1",1);
}

int	main(int argc, char **argv)
{
	int pid;

	pid = getpid();
	printf("Process Id is: %d\n", pid);
	signal(SIGUSR1, handler0);
	signal(SIGUSR2, handler1);
	while (1)
		pause();
	return (0);
}
