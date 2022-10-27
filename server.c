#include "minitalk.h"


//int char_num;
void print_ascii(char c);

void	sig_server_handler(int signum, siginfo_t *info, void *context)
{
	static char	char_num;
	static char c;

	(void) context;
	if (signum == SIGUSR1)
	{
		write(1, "0", 1);
	}
	
	else if (signum == SIGUSR2)
	{
		write(1, "1", 1);
		c = c | (1 << char_num); 
	}
	char_num++;
	if (char_num == 8)
	{
		write(1, &c, 1);
		write(1, "\n", 1);
		c = 0;
		char_num = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

void print_ascii(char c)
{
	int j = 8;
	while (j > 0)
	{
		if (c % 2 == 0)
		{
			write(1, "0", 1);
		}
		else
		{
			write(1, "1", 1);
		}
		j--;
		c = c >> 1;
	}
}

int main(int argc, char **argv)
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