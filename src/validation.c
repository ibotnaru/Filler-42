/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:05:09 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/29 13:17:43 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** This function compares char** - plt with char** -piece.
** The position is valid if it founds only one match.
** If it mathes 0 or more than once - the position on the plt for the
** piece isn't valid.
** Also the position isn't valid if it is out of the borders of the plt.
*/

int		find_match(t_struct *sct, int j, int i)
{
	int		ki;
	int		kj;
	int		cnt;

	ki = -1;
	kj = -1;
	cnt = 0;
	while (++kj < sct->piece_y)
	{
		if ((j + kj) >= sct->plt_y)
			return (0);
		ki = -1;
		while (++ki < sct->piece_x)
		{
			if ((i + ki) >= sct->plt_x)
				return (0);
			if (sct->piece[kj][ki] == '*' && ((sct->plt[j + kj][i + ki] ==
			sct->player) || (sct->plt[j + kj][i + ki] == sct->player + 32)))
				cnt++;
			if (sct->piece[kj][ki] == '*' && ((sct->plt[j + kj][i + ki] ==
			sct->opponent) || (sct->plt[j + kj][i + ki] == sct->opponent + 32)))
				return (0);
		}
	}
	return (cnt == 1 ? 1 : 0);
}

void	rm_leaks(int ***map, t_struct *sct)
{
	int i;

	i = -1;
	while (++i < sct->plt_y)
		free((*map)[i]);
	free(*map);
}

/*
** Solve the "An error occured. aborting..." :
** sct->y_for_print = -1;
** sct->x_for_print = -1;
*/

void	validation(t_struct *sct)
{
	int		i;
	int		**heatmap;

	i = -1;
	sct->y_for_print = -1;
	sct->x_for_print = -1;
	heatmap = heat_map(sct);
	place_piece(sct, heatmap);
	rm_leaks(&heatmap, sct);
	ft_putnbr(sct->y_for_print);
	ft_putchar(' ');
	ft_putnbr(sct->x_for_print);
	ft_putchar('\n');
}
