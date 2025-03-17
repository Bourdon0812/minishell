/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:48:12 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/17 15:50:19 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_shell
{
	int		running;
	char	*input;
	char	**cmd;
	char	**envp;
}	t_shell;

typedef struct s_cmd
{
	char			**args;
	char			*input_file;
	char			*output_file;
	char			*heredoc;
	int				append;
	int				pipe;
	struct s_cmd	*next;
}	t_cmd;

#endif
