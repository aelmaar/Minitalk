/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:19:18 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/18 19:33:42 by ael-maar         ###   ########.fr       */
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

static void	handler_sigusr(int sig, siginfo_t *info, void *vp)
{
	static int		i;
	static int		previoud_pid;

	if ((int)info->si_pid != previoud_pid)
	{
		i = 0;
		previoud_pid = (int)info->si_pid;
	}
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

	sa.sa_sigaction = handler_sigusr;
	sa.sa_flags = SA_SIGINFO;
	printf("The server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
