/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:21:59 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/26 23:04:40 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = malloc(sizeof(char) * (size + 1));
	if (mem != NULL)
		ft_memset(mem, 0, size + 1);
	return (mem);
}
