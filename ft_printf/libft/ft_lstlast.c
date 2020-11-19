/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:45:16 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/03 15:51:04 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *tmp;
	t_list *before;

	tmp = lst;
	before = lst;
	while (tmp != NULL)
	{
		before = tmp;
		tmp = tmp->next;
	}
	return (before);
}
