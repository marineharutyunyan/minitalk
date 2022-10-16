/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:26:36 by maharuty          #+#    #+#             */
/*   Updated: 2022/10/16 13:26:38 by maharuty         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;
	int		i;
	int		j;

	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		j = -1;
		while (++j <= 7)
		{
			if ((message[i] >> (7 - j) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	return (0);
}
