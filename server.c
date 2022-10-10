#include <signal.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

int counter = 0;
int num = 0;

void	handler0()
{
	counter++;
	//write(1,"0",1);
	if (counter > 7)
	{
		write(1, &num, 1);
		num = 0;
		counter = 0;
	}
}

void	handler1()
{
	int power_of_two[] = {128, 64, 32, 16, 8, 4, 2, 1};

	num += power_of_two[counter];
	counter++;
	//printf("\nnum is %d\n", num);
	//write(1, "1", 1);
	if (counter > 7)
	{
		write(1, &num, 1);
		num = 0;
		counter = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	printf("Process Id is: %d\n", pid);
	signal(SIGUSR1, handler0);
	signal(SIGUSR2, handler1);
	while (1)
		pause();
	return (0);
}
