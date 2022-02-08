/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:57:37 by mkim2             #+#    #+#             */
/*   Updated: 2022/02/08 15:00:00 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	get_bit(int sign, siginfo_t *info, void *context)
{
	static unsigned char	msg;
	static unsigned char	cnt;

	(void)context;
	++cnt;
	if (sign == SIGUSR1)
	{
		msg = msg << 1;
		msg += 1;
	}
	else if (sign == SIGUSR2)
		msg = msg << 1;
	if (cnt == 8)
	{
		ft_putchar_fd(msg, 1);
		if (msg == 0)
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		cnt = 0;
		msg = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	print_server_pid(pid);
	sig.sa_sigaction = get_bit;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
