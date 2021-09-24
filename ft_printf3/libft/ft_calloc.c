/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roms <romain.berthaud812@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:30:57 by roms              #+#    #+#             */
/*   Updated: 2021/09/18 13:25:20 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size == 0)
		size = 1;
	if (!nmemb)
		nmemb = 1;
	tab = malloc(sizeof(*tab) * (nmemb * size));
	if (!tab)
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}
