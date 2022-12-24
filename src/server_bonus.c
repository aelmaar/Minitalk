/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:34:54 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/24 22:23:49 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_printf.h"

char	g_bin[9];

static void	handler_sigusr(int sig, siginfo_t *info, void *vp)
{
	static int		i;
	static int		previoud_pid;

	(void)vp;
	if ((int)info->si_pid != previoud_pid)
	{
		i = 0;
		previoud_pid = (int)info->si_pid;
	}
	g_bin[8] = '\0';
	if (sig == SIGUSR1)
		g_bin[i++] = '0';
	else if (sig == SIGUSR2)
		g_bin[i++] = '1';
	if (i == 8)
	{
		bin_tochar_bonus(g_bin, info);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("The server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
