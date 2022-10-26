#include "minitalk.h"

int	g_msg_len;

void	sig_client_handler(int signum)
{
	static int count_reply;

	if (signum == SIGUSR1)
		count_reply++;
	if (count_reply == g_msg_len)
	{
		printf("Server accepted message successfully\n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_client_handler;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	
	if (argc == 3)
	{
		
		int i = 0;
		g_msg_len = strlen(argv[2]);
		pid_t	server_pid = atoi(argv[1]);
		printf("%d:\n", server_pid);
		unsigned	char c;

		//signal(SIGUSR1, sig_client_handler);
		while (i < g_msg_len && argv[2][i])
		{
			c = argv[2][i];
			int j = 8;
			write(1, &c, 1);
			while (j > 0)
			{
				if (c % 2 == 0){
					write(1, "0", 1);
				
					kill(server_pid, SIGUSR1);}
				else
				{write(1, "1", 1);
					kill(server_pid, SIGUSR2);}
				j--;
				c = c >> 1;
				usleep(100);
			}
			i++;
		}
		//while (1)
		//	pause();
		return (0);
	}
}