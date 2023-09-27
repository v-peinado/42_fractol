/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:27:58 by vpeinado          #+#    #+#             */
/*   Updated: 2023/07/06 14:26:15 by vpeinado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nitems * size));
	return (ptr);
}

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (n--)
	{
		*s++ = 0;
	}
	str = s;
}
