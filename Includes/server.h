/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:27:09 by ael-maar          #+#    #+#             */
/*   Updated: 2022/12/22 19:16:06 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	bin_tochar_mandatory(char binary[]);
void	bin_tochar_bonus(char binary[], siginfo_t *info);
void	send_signal(int pid, char c);

#endif