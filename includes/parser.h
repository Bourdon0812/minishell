/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:13 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/12 17:11:27 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_shell	t_shell;

/* lexer.c */
int		count_args(char *input);
char	*get_arg(char *input, int start, int end, int keep_quotes);
char	**split_args(char *input, int keep_quotes);
void	lexer(t_shell *shell);

/* quotes.c */
int		has_unclosed_quotes(char *str);
void	skip_quotes_and_copy(char *str, char *nstr, int *i, int *i2);
char	*remove_quotes(char *str);
void	skip_quotes(char *input, int *i, char quote);

/* parsing.c */
void	allocate_and_copy_args(t_cmd *cmd, char *arg);
void	add_argument(t_cmd *cmd, char *arg);
void	handle_redirections(t_cmd *cmd, char **cmds, int *i);
int		check_syntax_errors(char **cmds);
t_cmd	*parsing(t_shell *shell);

#endif
