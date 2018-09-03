t_list	*read_tetri(int fd)
{
	char	*buf;
	int		count;
	t_list	*list;
	t_etris	*tetris;
	char	cur;

	buf = ft_strnew(21);
	list = NULL;
	cur = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (check_counts(buf, count) != 0
				|| (tetris = get_piece(buf, cur++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&buf);
	if (count != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
