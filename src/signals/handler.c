/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:38:25 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/10 17:10:13 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// rewrite shell for ctrl c
void	handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	//rl_replace_line("", 0);
	rl_redisplay();
}

///////////////////////////////////////////////////////////////////////////////
// Function for desactivate ctrl^x printing
void	disable_slprint(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

///////////////////////////////////////////////////////////////////////////////
// rewrite shell for ctrl c
void	handle_sigquit(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
