/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:53:44 by ntesfu            #+#    #+#             */
/*   Updated: 2022/10/27 16:09:12 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_server_handler(int signum, siginfo_t *info, void *context)
{
	static char	char_num;
	static char	c;

	(void)context;
	if (signum == SIGUSR2)
		c = c | (1 << char_num);
	char_num++;
	if (char_num == 8)
	{
		write(1, &c, 1);
		c = 0;
		char_num = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_server_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
