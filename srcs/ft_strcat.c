/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:25:55 by eferrand          #+#    #+#             */
/*   Updated: 2016/11/29 00:27:47 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (dst[a] != '\0')
		a++;
	while (src[b] != '\0')
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
	return (dst);
}
