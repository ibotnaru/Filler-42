/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:05:09 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/09/27 23:25:20 by ibotnaru         ###   ########.fr       */
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

int		find_match(t_struct *strct, int j, int i)
{
	int		ki;
	int		kj;
	int		cnt;

	ki = -1;
	kj = -1;
	cnt = 0;
	while (++kj < strct->piece_y)
	{
		if ((j + kj) >= strct->plt_y)
			return (0);
		ki = -1;
		while (++ki < strct->piece_x)
		{
			if ((i + ki) >= strct->plt_x)
				return (0);
			if (strct->piece[kj][ki] == '*' && ((strct->plt[j + kj][i + ki] == strct->player)
				|| (strct->plt[j + kj][i + ki] == strct->player + 32)))
				cnt++;
			if (strct->piece[kj][ki] == '*' && ((strct->plt[j + kj][i + ki] == strct->opponent)
				|| (strct->plt[j + kj][i + ki] == strct->opponent + 32)))
				return (0);
		}
	}
	return (cnt == 1 ? 1 : 0);
}

void	validation(t_struct *strct)
{
	int		**heatmap;

	heatmap = heat_map(strct);
	place_piece(strct, heatmap);
	ft_putnbr(strct->y_for_print);
	ft_putchar(' ');
	ft_putnbr(strct->x_for_print);
	ft_putchar('\n');
}
