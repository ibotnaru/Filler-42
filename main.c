/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:02:25 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/08 23:16:36 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		parsing(int fd, char *line, t_struct *strct)
{
	if(strct->flag_player == 0)
		get_player(fd, line, strct);
	if (strct->flag_player == 1)
	{
		get_plateau(line, strct);
		line = fill_plt(fd, line, strct);
		get_piece(fd, line, strct);
	}
}

int			main (void)
{
	int			fd;					//file descriptor to rread the map from thr file
	char		*line;				//for get_next_line
	t_struct	strct;			//all the data from the file where the map is

	fd = open("filler.txt", O_RDONLY);
	ft_bzero(&strct, sizeof(t_struct));
	while (get_next_line(fd, &line) > 0)			//read till EOF
	{
		parsing(fd, line, &strct);				//reading from the map and pars line by line
		free(line);
	}
	/* Check for leaks: */
	while (1);		//infinite loop
	return(0);
}
