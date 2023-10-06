#include "../includes/minitalk.h"

static pid_t	g_client_pid = 0;

void	send_to_client(int sig)
{
	if (kill(g_client_pid, sig) == -1)
		printf("signal error occurred\n");
}

static void	get_bits(int sig, siginfo_t *sig_info, void *ptr)
{
	static int	bits = 0;
	static char	c = 0;
	int			signal;

	(void)ptr;
	if (sig == SIGUSR1)
		signal = 0;
	if (sig == SIGUSR2)
		signal = 1;
	c += (signal << bits++);
	if (bits == 8)
	{
		add_c_buffer(c);
		bits = 0;
		c = 0;
	}
	if (sig_info->si_pid > 1)
		g_client_pid = sig_info->si_pid;
	send_to_client(SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	siga;

	siga.sa_sigaction = get_bits;
	siga.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &siga, NULL) == -1)
		|| (sigaction(SIGUSR2, &siga, NULL) == -1))
		printf("signal error occurred\n");
	pid = getpid();
	printf("pid: %d\n", pid);
	while (1)
		pause();
	return (0);
}
