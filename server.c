/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:19:18 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/18 20:17:29 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>

char	bin[9];

static void	send_signal(int pid, char c)
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

static void	send_to_clients(siginfo_t *info)
{
	char	*message;

	message = "MSG RECEIVED";
	while (*message)
	{
		send_signal((int)info->si_pid, *message);
		message++;
	}
	if (*message == 0)
		send_signal((int)info->si_pid, *message);
}

static void	bin_tochar(char binary[], siginfo_t *info)
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
	if (dec == 0)
		send_to_clients(info);
	else
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
		bin_tochar(bin, info);
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
