/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:52:34 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/22 19:40:36 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send_signal(int pid, unsigned char c)
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
		usleep(200);
	}
	while (cnt_bits <= 7)
	{
		send = kill(pid, SIGUSR1);
		cnt_bits++;
		usleep(200);
	}
}
