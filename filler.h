/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:36:31 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/07 00:44:44 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# include "./libft/libft.h"

typedef	struct	s_struct
{
	int			player_on;
	int			flag_player;
	char		**plateau;
	int			plateau_y;
	int			plateau_x;
	char		**piece;
	int			piece_x;
	int			piece_y;
}				t_struct;

#endif
