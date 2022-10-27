/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:54:36 by ntesfu            #+#    #+#             */
/*   Updated: 2022/10/27 16:17:14 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_msg_len;

void	sig_client_handler(int signum, siginfo_t *info, void *context)
{
	static int	count_reply;

	(void) context;
	(void) info;
	if (signum == SIGUSR1)
		count_reply++;
	if (count_reply == g_msg_len)
	{
		ft_printf("Server accepted message successfully\n");
		exit(EXIT_FAILURE);
	}
}

void	string_to_binary(pid_t server_pid, char *msg)
{
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	j = 8;
	while (i < g_msg_len && msg[i])
	{
		c = msg[i];
		j = 8;
		while (j > 0)
		{
			if (c % 2 == 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j--;
			c = c >> 1;
			usleep(150);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;

	sa.sa_sigaction = sig_client_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
		ft_printf("Error: wrong number of arguments");
	else
	{
		g_msg_len = strlen(argv[2]);
		server_pid = atoi(argv[1]);
		string_to_binary(server_pid, argv[2]);
		pause();
		return (0);
	}
}
