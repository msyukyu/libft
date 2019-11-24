/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thashmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:18:38 by dabeloos          #+#    #+#             */
/*   Updated: 2019/11/20 21:18:40 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_thmap_initialize(t_thmap *thmap,
	t_typemanager *tbnode_mng, t_array *array_tbtree,
	size_t (*hash)(void *s, size_t size))
{
	if (!thmap || !tbnode_mng || !array_tbtree || !hash ||
		array_tbtree->size < 2)
		return (-1);
	thmap->hmap.array = array_tbtree;
	thmap->hmap.hash_btree = (t_tbtree*)thmap->hmap.array->items;
	thmap->hmap.array->items =
		(void*)((char*)thmap->hmap.array->items + sizeof(t_tbtree));
	thmap->hmap.array->n_items--;
	thmap->hmap.array->size--;
	thmap->hmap.hash = hash;
	thmap->tbnode_mng = tbnode_mng;
	return (ft_tbtree_initialize(&thmap->hmap.hash_btree, tbnode_mng,
		ft_btree_cmp_addr));
}

void				ft_thmap_refill(t_thmap *thmap)
{
	size_t			i;
	t_tbtree		*tbtree;

	if (!thmap)
		return ;
	i = 0;
	while (i < thmap->hmap.array->size)
	{
		tbtree = (t_tbtree*)ft_array_get(thmap->hmap.array, i);
		if (tbtree->tmng)
			ft_tbtree_refill(tbtree);
		++i;
	}
	ft_tbtree_refill(thmap->hmap.hash_btree);
}
