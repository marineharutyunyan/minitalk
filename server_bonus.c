/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:27:01 by maharuty          #+#    #+#             */
/*   Updated: 2022/10/17 13:11:49 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

int	g_num = 0;

void	handler(int sig)
{
	static int	counter = 0;

	if (sig == 31)
		g_num = g_num | 128 >> counter;
	counter++;
	if (counter > 7)
	{
		write(1, &g_num, 1);
		g_num = 0;
		counter = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	printf("Process Id is: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
