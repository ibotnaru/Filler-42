/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:43:54 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/29 13:14:00 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*create_piece_in_sct(char *line, t_struct *sct, int fd)
{
	int		i;
	int		j;

	free(line);
	get_next_line(fd, &line);
	sct->piece = (char **)malloc(sizeof(char*) * (sct->piece_y + 1));
	i = -1;
	while (++i < sct->piece_y)
	{
		j = -1;
		sct->piece[i] = (char *)malloc(sizeof(char) * (sct->piece_x + 1));
		while (++j < sct->piece_x)
			sct->piece[i][j] = line[j];
		sct->piece[i][j] = '\0';
		if (i + 1 < sct->piece_y)
		{
			free(line);
			get_next_line(fd, &line);
		}
	}
	sct->piece[i] = NULL;
	return (line);
}

char	*get_piece(char *line, t_struct *sct, int fd)
{
	char	**substr;

	while (ft_strncmp(line, "Piece", 4) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	substr = ft_strsplit(line, ' ');
	sct->piece_y = ft_atoi(substr[1]);
	sct->piece_x = ft_atoi(substr[2]);
	free(substr[0]);
	free(substr[1]);
	free(substr[2]);
	free(substr);
	return (line);
}

/*
** This funct reads data from the map and fills the plateau
** (skips the 000, 001 etc.. and starts from the 4th position)
** byte by byte, line by line.
*/

char	*fill_plt(int fd, char *line, t_struct *sct)
{
	int		i;
	int		j;
	int		idx;

	j = -1;
	sct->plt = (char **)malloc(sizeof(char *) * (sct->plt_y + 1));
	while (++j < sct->plt_y)
	{
		idx = 4;
		i = -1;
		sct->plt[j] = (char *)malloc(sizeof(char) * (sct->plt_x + 1));
		while (++i < sct->plt_x)
		{
			sct->plt[j][i] = line[idx];
			idx++;
		}
		sct->plt[j][i] = '\0';
		free(line);
		get_next_line(fd, &line);
	}
	sct->plt[j] = NULL;
	return (line);
}

/*
** Get the plateau_y and plateau_x (the dimensions) of the Plateau
** by split the "Plateau 15 17:" to
** "Plateau" "15" "17:"
*/

char	*get_plt(char *line, t_struct *sct, int fd)
{
	char	**substr;

	while (ft_strncmp(line, "Plateau ", 7) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	substr = ft_strsplit(line, ' ');
	sct->plt_y = ft_atoi(substr[1]);
	sct->plt_x = ft_atoi(substr[2]);
	free(substr[0]);
	free(substr[1]);
	free(substr[2]);
	free(substr);
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

char	*get_player(char *line, t_struct *sct, int fd)
{
	while (ft_strncmp(line, "$$$ exec p", 9) != 0)
	{
		free(line);
		get_next_line(fd, &line);
	}
	if (line[10] == '1')
	{
		sct->player = 'O';
		sct->opponent = 'X';
	}
	else
	{
		sct->player = 'X';
		sct->opponent = 'O';
	}
	sct->player_on = 1;
	return (line);
}
