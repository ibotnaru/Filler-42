/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:36:31 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/14 20:29:03 by ibotnaru         ###   ########.fr       */
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
	char		opponent;
	int			opponent_on;
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
void	create_piece_in_strct(int fd, char *line, t_struct *strct);

/*
** Validation
*/
void	validation(t_struct *strct);
int		find_match(t_struct *strct, int j, int i); //??

/*
** Heat map
*/
int		**heat_map(t_struct *strct);
int		**create_map(t_struct *strct);
int		**surround_opp(t_struct *strct, int **map, int j, int i, int cnt);

/*
** Algorithm
*/
void	place_piece(t_struct *strct, int **map);
int		clc_sum(t_struct *strct, int j, int i);

//just for ckeck
void	print_map(int **heat_map, t_struct *strct);
void	print_map2(char **heat_map, t_struct *strct);
#endif
