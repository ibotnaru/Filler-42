/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:36:31 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/08 13:27:52 by ibotnaru         ###   ########.fr       */
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
	char		player_on;
	int			flag_player;
	char		**plateau;
	int			plateau_y;
	int			plateau_x;
	char		**piece;
	int			piece_y;
	int			piece_x;
}				t_struct;

/*
** All the functions are arranged in order
** that they appear in the programm
*/

/*
** Parsing
*/
void	parsing(int fd, char *line, t_struct *strct);
void	get_player(int fd, char *line, t_struct *strct);
void	get_plateau(char *line, t_struct *strct);
char	*fill_plt(int fd, char *line, t_struct *strct);
void	get_piece(int fd, char *line, t_struct *strct);
void	put_piece(int fd, char *line, t_struct *strct);

#endif
