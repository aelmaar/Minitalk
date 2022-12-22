/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:19:10 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/22 18:21:08 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

char	bin[9];

int	main(int argc, char *argv[])
{
	int					i;
	int					pid;

	i = 0;
	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 1)
			return (0);
		while (argv[2][i])
			send_signal(pid, argv[2][i++]);
		if (argv[2][i] == 0)
			send_signal(pid, argv[2][i]);
	}
	return (0);
}
