/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:28:29 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/01 14:53:37 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* lib c */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <dirent.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>

/* lib readline */
# include <readline/readline.h>
# include <readline/history.h>

/* struct */
typedef struct s_shell
{
	int		running; // 1 si le shell fonctionne, 0 sinon
	char	*input; //  La commande en cours d'exécution
	char	**cmd; //   Tableau des arguments de la commande
	char	**envp; //  Tableau des variables d'environnement
}	t_shell;

/* libs */
# include "../libft/libft.h"
# include "builtins.h"
# include "executor.h"
# include "parser.h"
# include "signals.h"
# include "utils.h"

/* color */
# define GREEN "\033[0;32m"
# define RESET "\033[0m"
#endif