/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:29:15 by dabeloos          #+#    #+#             */
/*   Updated: 2018/10/20 17:40:27 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

void		ft_strclr(char *s)
{
	size_t		i;

	if (s == NULL)
		return ;
	i = -1;
	while (s[++i] != '\0')
		s[i] = '\0';
}
