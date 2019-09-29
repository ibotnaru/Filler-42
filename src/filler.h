/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:36:31 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/29 13:14:21 by ibotnaru         ###   ########.fr       */
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
	char		**plt;
	int			plt_y;
	int			plt_x;
	char		**piece;
	int			piece_y;
	int			piece_x;
	char		**changed_piece;
	int			x_for_print;
	int			y_for_print;
}				t_struct;

/*
** All the functions are arranged in order
** that they appear in the programm
*/

/*
** Parsing
*/

void			parsing(int fd, char *line, t_struct *sct);
char			*get_player(char *line, t_struct *sct, int fd);
char			*get_plt(char *line, t_struct *sct, int fd);
char			*fill_plt(int fd, char *line, t_struct *sct);
char			*get_piece(char *line, t_struct *sct, int fd);
char			*create_piece_in_sct(char *line, t_struct *sct, int fd);

/*
** Validation
*/

void			validation(t_struct *sct);
int				find_match(t_struct *sct, int j, int i);

/*
** Heat map
*/

int				**heat_map(t_struct *sct);
int				**create_map(t_struct *sct);
int				**surround_opp(int **map, int j, int i, int cnt);

/*
** Algorithm
*/

void			place_piece(t_struct *sct, int **map);
int				clc_sum(t_struct *sct, int **map, int j, int i);

/*
** Leaks
*/

void			rm_leaks(int ***map, t_struct *sct);

#endif
