/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_maxnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:13:36 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/28 18:50:53 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_my_maxnum(int *arr, int len)
{
	int		max;
	int		i;

	i = 0;
	max = -2147483648;
	if (arr == NULL)
		return (0);
	while (i < len)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			i++;
		}
		else
			i++;
	}
	return (max);
}
