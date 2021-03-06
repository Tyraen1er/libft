/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 21:51:46 by eferrand          #+#    #+#             */
/*   Updated: 2017/02/09 04:22:34 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_root(int a, int b)
{
	int c;

	c = 0;
	while (ft_power(c, a) <= b)
		++c;
	return (c - 1);
}
