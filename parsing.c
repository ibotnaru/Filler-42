/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:22:07 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/08 23:05:58 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		put_piece(int fd, char *line, t_struct *strct)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	strct->piece = (char **)malloc(sizeof(char *) * (strct->piece_y + 1));
	while(j < (strct->piece_y))
	{
		strct->piece[j] = (char *)malloc(sizeof(char) * (strct->piece_x + 1));
		while(i < (strct->piece_x))
		{
			strct->piece[j][i] = line[i];
			i++;
		}
		strct->piece[j][i] = '\0';
		printf("[%2d]  %s\n", j, strct->piece[j]);
		j++;
		free(line);
		get_next_line(fd, &line);
	}
	strct->piece[j] = NULL;
}

void		get_piece(int fd, char *line, t_struct *strct)
{
	char	**substr;

	if (ft_strncmp(line, "Piece", 5) == 0)
	{
		substr = ft_strsplit(line, ' ');
		strct->piece_y = ft_atoi(substr[1]);
		strct->piece_x = ft_atoi(substr[2]);
		free(substr[0]);
		free(substr[1]);
		free(substr[2]);
		free(substr);
		free(line);
		get_next_line(fd, &line);
		put_piece(fd, line, strct);
	}
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
		strct->plateau = (char **)malloc(sizeof(char *) * (strct->plateau_y + 1));
		while (j < strct->plateau_y)
		{
			idx = 4;
			i = 0;
			strct->plateau[j] = (char *)malloc(sizeof(char) * (strct->plateau_x + 1));
			while (i < strct->plateau_x)
			{
				strct->plateau[j][i] = line[idx];
				idx++;
				i++;
			}
			strct->plateau[j][i] = '\0';
			//printf("[%2d]  %s\n", j, strct->plateau[j]);
			j++;
			free(line);
			get_next_line(fd, &line);
		}
		strct->plateau[j] = NULL;
	}
	return (line);
}

/*
** Get the plateau_y and plaeau_x (the dimensions) of the Plateau
** by split the "Plateau 15 17:" to
** "Plateau" "15" "17:"
*/
void		get_plateau(char *line, t_struct *strct)
{
	char	**substr;

	if (ft_strncmp(line, "Plateau", 7) == 0)
	{
		substr = ft_strsplit(line, ' ');
		strct->plateau_y = ft_atoi(substr[1]);
		strct->plateau_x = ft_atoi(substr[2]);
		free(substr[0]);
		free(substr[1]);
		free(substr[2]);
		free(substr);
	}
}

/*
** This function should find player "ibotnaru"
** searching line by line.
** Be careful in which directory you create your player! (../, ./, etc)
** $$$ exec p1 : [../ibotnaru.filler]
*/
void		get_player(int fd, char *line, t_struct *strct)
{

	if (ft_strncmp(line, "$$$ exec p1 : [../ibotnaru.filler]", 34) == 0)
	{
		strct->player_on = 'O';
		strct->flag_player = 1;
	}
	else if (ft_strncmp(line, "$$$ exec p2 : [../ibotnaru.filler]", 34) == 0)
	{
		strct->player_on = 'X';
		strct->flag_player = 1;
	}
}