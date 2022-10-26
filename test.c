char c;
int char_num;

void	sig_server_handler(int signum)
{
	//printf("I am here");
	if (signum == 0)
		c = c << 1;
	else if (signum == 1)
	{
		c = c << 1;
		c = c | 00000001; 
	}
	if (char_num == 7)
	{
		printf("done:");
		write(1, &c, 1);
		c = 0;
		char_num = 0;
	}
	char_num++;
}

int main()
{
	char_num = 0;
	c = 0;

	sig_server_handler()
}