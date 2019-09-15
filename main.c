/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:02:25 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/13 23:46:41 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		parsing(int fd, char *line, t_struct *strct)
{
	if(strct->player_on == 0)
		get_player(fd, line, strct);
	if (strct->player_on == 1)
	{
		get_plateau(line, strct);
		line = fill_plt(fd, line, strct);
		get_piece(fd, line, strct);
	}
}

void	print_map(int **heat_map, t_struct *strct)
{
	int i = 0;
	int j = 0;

	while (j < strct->plateau_y)
	{
		i = 0;
		printf("[%2d] ", j);
		while (i < strct->plateau_x)
		{
			printf("%2d ", heat_map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}
void	print_map2(char **heat_map, t_struct *strct)
{
	int i = 0;
	int j = 0;

	while (j < strct->plateau_y)
	{
		i = 0;
		while (i < strct->plateau_x)
		{
			printf("%2d ", heat_map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

int			main (void)
{
	int			fd;					//file descriptor to rread the map from thr file
	char		*line;				//for get_next_line
	t_struct	strct;			//all the data from the file where the map is
	int			**map;//just for ckeck

	fd = open("filler.txt", O_RDONLY);
	ft_bzero(&strct, sizeof(t_struct));
	while (get_next_line(fd, &line) > 0)			//read till EOF
	{
		parsing(fd, line, &strct);				//reading from the map and pars line by line
		//free(line);
	}
	char **pl = strct.plateau; //just for ckeck
	print_map2(pl, &strct);//just for ckeck
	map = heat_map(&strct);//just for ckeck
	print_map(map, &strct);//just for ckeck
	/* Check for leaks: */
	while (1);		//infinite loop
	return(0);
}
