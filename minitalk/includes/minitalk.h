#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

int		ft_atoi(char *str);
void	send_to_client(int sig);
void	add_c_buffer(char c);

#endif
