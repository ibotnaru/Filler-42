/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:02:25 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/07 00:47:03 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** This function should find player "ibotnaru"
** searching line by line.
** Be careful in which directory you create your player! (../, ./, etc)
** $$$ exec p1 : [../ibotnaru.filler]
*/
void	get_player(int fd, char *line, t_struct *map_info)
{

	if ((ft_strncmp(line, "$$$ exec p1 : [../ibotnaru.filler]", 34) == 0) ||
		(ft_strncmp(line, "$$$ exec p2 : [../ibotnaru.filler]", 34) == 0))
		{
			map_info->player_on = 1;		//player "ibotnaru" - exists
			map_info->flag_player = 1;
		}
}

/*
** Get the plateau_y and plaeau_x (the dimensions) of the Plateau
** by split the "Plateau 15 17:" to
** "Plateau" "15" "17:"
*/
void	get_plateau(int fd, char *line, t_struct *map_info)
{
	char	**substr;

	if (ft_strncmp(line, "Plateau", 7) == 0)
	{
		substr = ft_strsplit(line, ' ');
		map_info->plateau_y = ft_atoi(substr[1]);
		map_info->plateau_x = ft_atoi(substr[2]);
	}
}

void	parsing(int fd, char *line, t_struct *map_info)
{

	get_player(fd, line, map_info);
	if (map_info->player_on == 1)
	{
		get_plateau(fd, line, map_info);
	}
	printf("\n");
	// get_piece();		//!
}

int main (void)
{
	int			fd;					//file descriptor to rread the map from thr file
	char		*line;				//for get_next_line
	t_struct	map_info;			//all the data from the file where the map is

	fd = open("filler.txt", O_RDONLY);
	ft_bzero(&map_info, sizeof(t_struct));
	while (get_next_line(fd, &line) > 0)			//read till EOF
		parsing(fd, line, &map_info);				//reading from the map and pars line by line
	return(0);
}
