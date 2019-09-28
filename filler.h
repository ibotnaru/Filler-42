/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:36:31 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/27 19:53:57 by ibotnaru         ###   ########.fr       */
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

void	parsing(int fd, char *line, t_struct *strct);
char	*get_player(char *line, t_struct *strct, int fd);
char	*get_plt(char *line, t_struct *strct, int fd);
char	*fill_plt(int fd, char *line, t_struct *strct);
char	*get_piece(char *line, t_struct *strct, int fd);
char	*create_piece_in_strct(char *line, t_struct *strct, int fd);

/* testing */
// void	print_map(int **heat_map, t_struct *strct); //delete me
void	print_map2(char **heat_map, t_struct *strct); //delete

// void			parsing(int fd, char *line, t_struct *strct);
// void			get_player(char *line, t_struct *strct);
// void			get_plt(char *line, t_struct *strct);
// char			*fill_plt(int fd, char *line, t_struct *strct);
// void			get_piece(int fd, char *line, t_struct *strct);
// void			create_piece_in_strct(int fd, char *line, t_struct *strct);

/*
** Validation
*/

void			validation(t_struct *strct);
int				find_match(t_struct *strct, int j, int i);

/*
** Heat map
*/

int				**heat_map(t_struct *strct);
int				**create_map(t_struct *strct);
int				**surround_opp(int **map, int j, int i, int cnt);

/*
** Algorithm
*/

void			place_piece(t_struct *strct, int **map);
int				clc_sum(t_struct *strct, int **map, int j, int i);

#endif
