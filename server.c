/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:28:05 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/10 19:23:45 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minitalk.h"
#include "libft/libft.h"

char	*g_str = NULL;

void	append_char(char x, int length)
{
	char	*new_str;

	new_str = malloc(length + 2);
	if (!new_str)
		return ;
	new_str[0] = '\0';
	if (g_str)
	{
		ft_strlcpy(new_str, g_str, length + 1);
		free(g_str);
	}
	new_str[length] = x;
	new_str[length + 1] = '\0';
	g_str = new_str;
}

static void	manage_char(char *current_char, int *length, int *bit_pos)
{
	if (*current_char == '\0')
	{
		ft_printf("%s\n", g_str);
		free(g_str);
		g_str = NULL;
		*length = 0;
	}
	else
	{
		append_char(*current_char, *length);
		*length += 1;
	}
	*bit_pos = 7;
	*current_char = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit_pos = 7;
	static char	current_char = 0;
	static int	length = 0;
	pid_t		client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (sig == SIGUSR2)
		current_char |= (1 << bit_pos);
	bit_pos--;
	if (bit_pos < 0)
	{
		manage_char(&current_char, &length, &bit_pos);
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Servidor iniciado. PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
