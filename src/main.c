/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:02:25 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/29 13:20:13 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parsing(int fd, char *line, t_struct *sct)
{
	if (sct->player_on == 0)
	{
		line = get_player(line, sct, fd);
		free(line);
	}
	else
	{
		line = get_plt(line, sct, fd);
		line = fill_plt(fd, line, sct);
		line = get_piece(line, sct, fd);
		line = create_piece_in_sct(line, sct, fd);
		validation(sct);
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
	t_struct	sct;

	fd = 0;
	ft_bzero(&sct, sizeof(t_struct));
	while (get_next_line(fd, &line) > 0)
		parsing(fd, line, &sct);
	return (0);
}
