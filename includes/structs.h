/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:48:12 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/04 16:14:40 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_shell
{
	int		l_sig;
	char	*input;
	char	**cmd;
	char	**envp;
}	t_shell;

typedef struct s_cmd
{
	char			**args;
	char			*input_file;
	char			*output_file;
	char			**heredocs;
	int				heredoc_count;
	int				append;
	int				pipe;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_exec_ctx
{
	pid_t	pids[1024];
	int		i;
	pid_t	last;
	int		prev;
	int		fd[2];
}	t_exec_ctx;

#endif
