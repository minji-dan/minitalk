/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:53:59 by mkim2             #+#    #+#             */
/*   Updated: 2022/02/08 16:53:54 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_bit(int pid, char *str)
{
	unsigned char	byte;
	int				i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		byte = 1 << 7;
		while (byte)
		{
			if (str[i] & byte)
			{
				if (kill(pid, SIGUSR1) == -1)
					print_error();
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					print_error();
			}
			usleep(150);
			byte = byte >> 1;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		print_error();
	else
	{
		pid = ft_atoi(argv[1]);
		if (ft_atoi(argv[1]) < 100 || ft_atoi(argv[1]) > 100000)
			print_error();
		if (!argv[1])
			print_error();
		signal(SIGUSR1, print_success);
		send_bit(pid, argv[2]);
	}
	return (0);
}
