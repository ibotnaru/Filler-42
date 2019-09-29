/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:40:17 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/26 21:30:33 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*mem;
	int		len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	mem = malloc(len + 1);
	if (mem != NULL)
	{
		while (s[i])
		{
			mem[i] = (*f)(s[i]);
			i++;
		}
		mem[i] = '\0';
	}
	return (mem);
}
