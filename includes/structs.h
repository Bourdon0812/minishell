/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:48:12 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/05 15:48:13 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_shell
{
	int		running; // 1 si le shell fonctionne, 0 sinon
	char	*input; //  La commande en cours d'exécution
	char	**cmd; //   Tableau des arguments de la commande
	char	**envp; //  Tableau des variables d'environnement
}	t_shell;

#endif