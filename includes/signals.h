/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:15 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/27 16:01:12 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

typedef struct s_shell	t_shell;

/* handler for signals */
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	disable_slprint(void);

#endif
