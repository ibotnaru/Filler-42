/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:02:25 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/27 23:23:56 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		parsing(int fd, char *line, t_struct *strct)
{
	if(strct->player_on == 0)
	{
		line = get_player(line, strct, fd);
		free(line);
	}
	else
	{
		line = get_plt(line, strct, fd);
		line = fill_plt(fd, line, strct);
		line = get_piece(line, strct, fd);
		line = create_piece_in_strct(line, strct, fd);
		validation(strct);
		free(line);
	}
}

/*
** fd = open("filler.txt", O_RDONLY);
** while (1); Check for leaks
*/

int		main(void)
{
	int			fd;
	char		*line;
	t_struct	strct;

	fd = 0;
	fd = open("filler.txt", O_RDONLY);
	ft_bzero(&strct, sizeof(t_struct));
	while (get_next_line(fd, &line) > 0)
		parsing(fd, line, &strct);
	return (0);
}
