/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:16 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/05 15:43:41 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_shell	t_shell;

/* type_utils.c */
int	is_builtins(char *str);
int	ft_iswsp(int c);
int	is_quote(char c);
int	has_pipe(char *input);
int	has_redirection(char *input);

#endif
