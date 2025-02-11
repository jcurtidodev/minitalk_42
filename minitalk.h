/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:40:45 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/07 20:14:06 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// Server
void	append_char(char x, int length);
void	handle_signal(int sig, siginfo_t *info, void *context);

// Client
void	send_char(pid_t pid, char c);
void	send_string(pid_t pid, char *str);

#endif
