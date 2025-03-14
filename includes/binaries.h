/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:56:39 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/13 12:08:14 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARIES_H
# define BINARIES_H

/* function */
void	launch_bin(t_shell *shell, char **cmd, int in, int out);
int		check_cmd(char **args, char **env);

#endif