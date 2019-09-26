/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:55:50 by dabeloos          #+#    #+#             */
/*   Updated: 2018/10/09 12:40:20 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		l1;
	size_t		i2;

	l1 = ft_strlen(s1);
	i2 = -1;
	while (s2[++i2] != '\0' && i2 < n)
		s1[l1 + i2] = s2[i2];
	s1[l1 + i2] = '\0';
	return (s1);
}
