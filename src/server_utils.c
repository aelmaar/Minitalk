/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:26:50 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/24 22:19:21 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	bin_tochar_bonus(char binary[], siginfo_t *info)
{
	int	i;
	int	dec;

	i = 0;
	dec = 0;
	while (binary[i])
	{
		if (binary[i] == '1')
			dec += (int)ft_pow(2, i);
		i++;
	}
	if (dec == 0)
		kill(info->si_pid, SIGUSR1);
	else
		write(1, &dec, 1);
}

void	bin_tochar_mandatory(char binary[])
{
	int	i;
	int	dec;

	i = 0;
	dec = 0;
	while (binary[i])
	{
		if (binary[i] == '1')
			dec += (int)ft_pow(2, i);
		i++;
	}
	write(1, &dec, 1);
}
