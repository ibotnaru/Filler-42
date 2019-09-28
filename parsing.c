/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:43:54 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/27 23:14:33 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*create_piece_in_strct(char *line, t_struct *strct, int fd)
{
	int		i;
	int		j;

	i = -1;
	free(line);
	get_next_line(fd, &line);
	free(line);
	strct->piece = (char **)malloc(sizeof(char*) * (strct->piece_y + 1));
	while (++i < strct->piece_y)
		strct->piece[i] = (char *)malloc(sizeof(char) * (strct->piece_x + 1));
	i = 0;
	while (i < strct->piece_y)
	{
		j = 0;
		while (j < strct->piece_x)
		{
			strct->piece[i][j] = line[j];
			j++;
		}
		strct->piece[i][j] = '\0';
		i++;
		if (i < strct->piece_y)
		{
			get_next_line(fd, &line);
			free(line);
		}
	}
	strct->piece[i] = NULL;
	return (line);
}

char	*get_piece(char *line, t_struct *strct, int fd)
{
	char	**str_d;

	while (ft_strncmp(line, "Piece", 4) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	str_d = ft_strsplit(line, ' ');
	strct->piece_y = ft_atoi(str_d[1]);
	strct->piece_x = ft_atoi(str_d[2]);
	free(str_d[0]);
	free(str_d[1]);
	free(str_d[2]);
	free(str_d);
	return (line);
}

/*
** This funct reads data from the map and fills the plateau
** (skips the 000, 001 etc.. and starts from the 4th position)
** byte by byte, line by line.
*/

char		*fill_plt(int fd, char *line, t_struct *strct)
{
	int		i;
	int		j;
	int		idx;

	idx = 4;
	i = 0;
	j = 0;
	if (ft_strncmp(line, "000", 3) == 0)
	{
		strct->plt = (char **)malloc(sizeof(char *) * (strct->plt_y + 1));
		while (j < strct->plt_y)
		{
			idx = 4;
			i = 0;
			strct->plt[j] = (char *)malloc(sizeof(char) * (strct->plt_x + 1));
			while (i < strct->plt_x)
			{
				strct->plt[j][i] = line[idx];
				idx++;
				i++;
			}
			strct->plt[j][i] = '\0';
			j++;
			free(line);
			get_next_line(fd, &line);
		}
		strct->plt[j] = NULL;
	}
	return (line);
}

/*
** Get the plateau_y and plateau_x (the dimensions) of the Plateau
** by split the "Plateau 15 17:" to
** "Plateau" "15" "17:"
*/

char	*get_plt(char *line, t_struct *strct, int fd)
{
	char	**str_d;

	while (ft_strncmp(line, "Plateau ", 7) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	str_d = ft_strsplit(line, ' ');
	strct->plt_y = ft_atoi(str_d[1]);
	strct->plt_x = ft_atoi(str_d[2]);
	free(str_d[0]);
	free(str_d[1]);
	free(str_d[2]);
	free(str_d);
	while (ft_strncmp(line, "000", 3) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	return (line);
}

/*
** This function should find player "ibotnaru" and the opponent
** searching line by line.
** Be careful in which directory you create your player! (../, ./, etc)
** $$$ exec p1 : [../ibotnaru.filler]
*/

char	*get_player(char *line, t_struct *strct, int fd)
{
	while (ft_strncmp(line, "$$$ exec p", 9) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	if (line[10] == '1')
	{
		strct->player = 'O';
		strct->opponent = 'X';
	}
	else
	{
		strct->player = 'X';
		strct->opponent = 'O';
	}
	strct->player_on = 1;
	return (line);
}
