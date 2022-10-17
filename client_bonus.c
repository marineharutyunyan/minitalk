/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:26:36 by maharuty          #+#    #+#             */
/*   Updated: 2022/10/17 13:18:10 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num = num * 10;
		num = num + (str[i] - 48);
		i++;
	}
	return (num);
}

void	checkdelivery(int delivered)
{
	while (1)
	{
		if (delivered == 0)
		{
			write(1, "delivered\n", 10);
			break ;
		}
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;
	int		i;
	int		j;
	int		delivered;

	delivered = -1;
	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		j = -1;
		while (++j <= 7)
		{
			if ((message[i] >> (7 - j) & 1) == 0)
				delivered = kill(pid, SIGUSR1);
			else
				delivered = kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	checkdelivery(delivered);
	return (0);
}
