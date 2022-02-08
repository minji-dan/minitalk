/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmsg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:02:27 by mkim2             #+#    #+#             */
/*   Updated: 2022/02/08 15:02:47 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_server_pid(int pid)
{
	ft_putstr_fd("server pid : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	print_error(void)
{
	ft_putstr_fd("Error Message\n", 1);
	exit(-1);
}

void	print_success(int sign)
{
	(void)sign;
	ft_putstr_fd("Transmission Success\n", 1);
}
