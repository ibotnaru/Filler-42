/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:49:01 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/02/28 01:53:34 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p;

	p = malloc(sizeof(t_list));
	if (p == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		p->content = NULL;
		p->content_size = 0;
	}
	else
	{
		p->content = malloc(content_size);
		if (p->content == NULL)
		{
			free(p);
			return (NULL);
		}
		ft_memcpy(p->content, content, content_size);
		p->content_size = content_size;
	}
	p->next = NULL;
	return (p);
}
