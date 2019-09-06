/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:00:29 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/26 23:00:48 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		ch;
	size_t	i;

	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = ch;
		i++;
	}
	return (b);
}
