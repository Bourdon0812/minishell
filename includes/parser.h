/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:13 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/05 15:44:00 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_shell	t_shell;

/* lexer.c */
void	lexer(t_shell *shell);

/* quotes.c */
int		has_unclosed_quotes(char *str);
void	skip_quotes_and_copy(char *str, char *nstr, int *i, int *i2);
char	*remove_quotes(char *str);
void	skip_quotes(char *input, int *i, char quote);

#endif
