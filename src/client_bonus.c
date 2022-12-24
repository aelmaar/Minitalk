/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:34:56 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/24 18:28:42 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"
#include "ft_printf.h"

static void	handler_sigusr(int sig)
{
	(void)sig;
	ft_printf("MSG RECEIVED 🔥");
	exit(0);
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	sa;
	unsigned char		*argv_test;

	i = 0;
	pid = 0;
	argv_test = (unsigned char *)argv[2];
	sa.sa_handler = handler_sigusr;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 1)
			return (0);
		while (argv_test[i])
			send_signal(pid, argv_test[i++]);
		if (argv_test[i] == 0)
			send_signal(pid, argv_test[i]);
		while (1)
			pause();
	}
	return (0);
}
