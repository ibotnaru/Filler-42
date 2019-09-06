/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:02:25 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/06 15:08:49 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main (void)
{
	int			fd;					//file descriptor to rread the map from thr file
	char		*line;				//for get_next_line
	t_struct	map_info;			//all the data from the file where the map is



	ft_bzero(&map_info, sizeof(t_struct));

	//while (get_next_line(fd, &line))
	//{
	//	start_work(fd, line);
	//}
	return(0);
}
