/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:19:10 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/18 19:33:50 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"

void	send_signal(int pid, char c)
{
	int	send;
	int	cnt_bits;

	send = 0;
	cnt_bits = 0;
	while (c > 0)
	{
		if ((c % 2) == 0)
			send = kill(pid, SIGUSR1);
		else
			send = kill(pid, SIGUSR2);
		cnt_bits++;
		if (send == -1)
			exit(0);
		c /= 2;
		usleep(120);
	}
	while (cnt_bits <= 7)
	{
		send = kill(pid, SIGUSR1);
		cnt_bits++;
		usleep(120);
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_signal(pid, argv[2][i++]);
		}
	}
	return (0);
}
