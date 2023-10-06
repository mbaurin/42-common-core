#include "../includes/minitalk.h"

bool	check_signal(bool sendable)
{
	static bool	sig = false;

	if (sendable)
		sig = true;
	else if (sig)
	{
		sig = false;
		return (true);
	}
	return (false);
}

static void	send_signals(char c, int pid)
{
	int			i;
	int			bit;

	i = 0;
	while (i < 8)
	{
		bit = c & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		while (!check_signal(false))
			continue ;
		c = c >> 1;
		i++;
	}
}

static void	handle_server_sig(int sig)
{
	if (sig == SIGUSR1)
		check_signal(true);
	if (sig == SIGUSR2)
		printf("message succesfully sent\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
		printf("error 3 arguments required\n");
	else
	{
		pid = ft_atoi(argv[1]);
		if ((signal(SIGUSR1, handle_server_sig) == SIG_ERR)
			|| (signal(SIGUSR2, handle_server_sig) == SIG_ERR))
			printf("signal error occurred\n");
		while (argv[2][i])
			send_signals(argv[2][i++], pid);
		send_signals('\0', pid);
		send_signals('\n', pid);
	}
	return (0);
}
