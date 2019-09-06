/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_minnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:14:53 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/28 18:51:06 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_my_minnum(int *arr, int len)
{
	int		min;
	int		i;

	i = 0;
	min = 2147483647;
	if (arr == NULL)
		return (0);
	while (i < len)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			i++;
		}
		else
			i++;
	}
	return (min);
}
