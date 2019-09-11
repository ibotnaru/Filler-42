/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:36:31 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/10 20:11:59 by ibotnaru         ###   ########.fr       */
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
	char		player;
	int			player_on;
	char		**plateau;
	int			plateau_y;
	int			plateau_x;
	char		**piece;
	int			piece_y;
	int			piece_x;
	char		**changed_piece;
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

/*
** Validation
*/
void	validation(t_struct *strct);
char	**sub_plateu(t_struct *strct, int i, int j);
void	change_piece(t_struct *strct);
int		valid_plc(t_struct *strct, char **sub_plt);

#endif
