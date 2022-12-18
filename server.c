/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:19:18 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/18 11:19:14 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>

char	bin[9];

static void	bin_tochar(char binary[])
{
	int	i;
	int	dec;

	i = 0;
	dec = 0;
	while (binary[i])
	{
		if (binary[i] == '1')
			dec += (int)pow(2, i);
		i++;
	}
	write(1, &dec, 1);
}

static void	handler_sigusr(int sig)
{
	static int		i;

	bin[8] = '\0';
	if (sig == SIGUSR1)
		bin[i++] = '0';
	else if (sig == SIGUSR2)
		bin[i++] = '1';
	if (i == 8)
	{
		bin_tochar(bin);
		i = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	sa.sa_handler = handler_sigusr;
	printf("The server ID: %d\n", getppid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
