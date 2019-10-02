#include "libft.h"
#include <stdio.h>

typedef struct	s_test_btree
{
	t_named		named;
	void		*ext;
}				t_data;

char			*in = "hivadeyfbcgopzwxklmjtunqsr";
char			*order = "abcdefghijklmnopqrstuvwxyz";
char			*inorder = "zyxwvutsrqponmlkjihgfedcba";

char			*char_bnode(t_bnode *bn)
{
	if (!bn->rank)
		return ("(null)");
	else
		return (bn->named->key);
}

int				display_bnode(void *receiver, void *sent)
{
	t_named		*cur;

	cur = (t_named*)sent;
	if (receiver)
	{
		printf("%s\n", cur->key);
		return (1);
	}
	return (0);
}

void			display_btree(t_btree *b, int verbose)
{
	if (!b)
		return ;
	ft_btree_bnode_iteration((verbose) ? &verbose : NULL, b->root,
		display_bnode);
}

t_memanager		*memanager_construct_data()
{
	t_memanager	*ma;

	ma = ft_memanager_construct(26, sizeof(t_data));
	return (ma);
}

t_memanager		*memanager_construct_bnode()
{
	t_memanager *ma;

	ma = ft_memanager_construct(26, sizeof(t_bnode));
	return (ma);
}

t_memanager		*memanager_construct_btree()
{
	t_memanager *ma;

	ma = ft_memanager_construct(1, sizeof(t_btree));
	return (ma);
}

int				main(void)
{
	t_memanager *bnodes;
	t_memanager *datas;
	t_memanager *btrees;
	t_btree		*btree;
	t_memused	mudatas;
	t_memused	mubtrees;
	t_data		*data;
	char		*key;

	bnodes = memanager_construct_bnode();
	datas = memanager_construct_data();
	btrees = memanager_construct_btree();
	ft_memused_initialize(&mudatas);
	ft_memused_initialize(&mubtrees);

	btree = ft_memanager_get(btrees, &mubtrees);
	ft_btree_construct_extmem(btree, bnodes);
	for (int i = 0; i < 26; i++)
	{
		data = ft_memanager_get(datas, &mudatas);
		data->named = (t_named){&(in[i])};
		data->ext = "ext";
		printf("added : %s || status : %d\n\n", data->named.key,
			ft_btree_add(btree, (t_named*)data));
		printf("------------------------------\n\n");
	}
	if (!btree)
		printf("btree null\n");
	else
	{
		printf("root %s\n", btree->root->named->key);
	}
	
	display_btree(btree, 1);

	for (int i = 0; i < 26; i++)
	{
		key = &in[i];
		data = (t_data*)ft_btree_remove(btree, key);
		printf("removed : %s || status : %s\n\n", key,
			(!data) ? "(null)" : data->named.key);
		printf("------------------------------\n\n");
	}

	display_btree(btree, 1);

	ft_memanager_free(bnodes);
	ft_memanager_free(datas);
	ft_memanager_free(btrees);
}