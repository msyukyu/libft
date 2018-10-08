/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:11:15 by dabeloos          #+#    #+#             */
/*   Updated: 2018/10/08 13:26:49 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = -sizeof(char);
	while (s[++i] != '\0')
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (((char)c == '\0') ? (char *)s + i : NULL);
}
