/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:02:25 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/07 22:36:05 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** This function should find player "ibotnaru"
** searching line by line.
** Be careful in which directory you create your player! (../, ./, etc)
** $$$ exec p1 : [../ibotnaru.filler]
*/
void	get_player(int fd, char *line, t_struct *strct)
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

/*
** This funct reads data from the map and fills the plateau
** byte by byte, line by line.
*/
void	fill_plt(int fd, char *line, t_struct *strct)
{
	int		i;
	int		j;
	int		idx;

	idx = 4;
	i = 0;
	j = 0;
	if (ft_strncmp(line, "000", 3) == 0)
	{
		strct->plateau = (char **)malloc(sizeof(char *) * strct->plateau_y + 1);
		while (j < strct->plateau_y)
		{
			idx = 4;
			i = 0;
			strct->plateau[j] = (char *)malloc(sizeof(char) * strct->plateau_x + 1);
			while (i < strct->plateau_x)
			{
				strct->plateau[j][i] = line[idx];
				idx++;
				i++;
			}
			strct->plateau[j][i] = '\0';
			printf("[%2d]  %s\n", j, strct->plateau[j]);
			j++;
			get_next_line(fd, &line);
		}
		strct->plateau[j] = NULL;
	}
}

/*
** Get the plateau_y and plaeau_x (the dimensions) of the Plateau
** by split the "Plateau 15 17:" to
** "Plateau" "15" "17:"
*/
void	get_plateau(int fd, char *line, t_struct *strct)
{
	char	**substr;

	if (ft_strncmp(line, "Plateau", 7) == 0)
	{
		substr = ft_strsplit(line, ' ');
		strct->plateau_y = ft_atoi(substr[1]);
		strct->plateau_x = ft_atoi(substr[2]);
	}
}

void	parsing(int fd, char *line, t_struct *strct)
{
	if(strct->flag_player == 0)
		get_player(fd, line, strct);
	if (strct->flag_player == 1)
	{
		get_plateau(fd, line, strct);
		fill_plt(fd, line, strct);
		get_piece();	//!!!
		put_piece();	//!!!!
	}
}

int main (void)
{
	int			fd;					//file descriptor to rread the map from thr file
	char		*line;				//for get_next_line
	t_struct	strct;			//all the data from the file where the map is

	fd = open("filler.txt", O_RDONLY);
	ft_bzero(&strct, sizeof(t_struct));
	while (get_next_line(fd, &line) > 0)			//read till EOF
		parsing(fd, line, &strct);				//reading from the map and pars line by line
	return(0);
}
