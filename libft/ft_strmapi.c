/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:32:29 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/26 21:30:57 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*mem;
	unsigned int		len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	mem = malloc(len + 1);
	if (mem != NULL)
	{
		while (s[i])
		{
			mem[i] = (*f)(i, s[i]);
			i++;
		}
		mem[i] = '\0';
	}
	return (mem);
}
