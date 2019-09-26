/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:17:21 by dabeloos          #+#    #+#             */
/*   Updated: 2018/10/20 17:40:49 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

char		*ft_strcpy(char *dst, const char *src)
{
	size_t		i;

	i = -1;
	while (src[++i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
