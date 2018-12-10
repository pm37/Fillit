/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:35:05 by pimichau          #+#    #+#             */
/*   Updated: 2018/12/04 12:12:15 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_usage(void)
{
	ft_putstr("error");
	return (0);
}

void		ft_display_tab(char **tab)
{
	while(*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}


int		main(int argc, char **argv)
{
	int		fd;
	int		sqr_size;
	char	**tab;
	t_tetri_list *list;
	float cursor;

	fd = 0;
	tab = NULL;
	list = NULL;
	cursor = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (read(fd, 0, 0) == -1)
			return (ft_usage());
		tab = ft_read_file(fd);
		close(fd);
		if (!tab)
			return (ft_usage());
		if (!ft_check_errors(tab))
			return (ft_usage());
		//printf("Les tetriminos sont corrects !");
		ft_create_list(tab, &list);
		sqr_size = ft_get_min_sqr_size(list);
		ft_init_sol_tab(&tab, sqr_size);
		while (!(ft_complete_tetris(&list, tab, cursor, sqr_size)))
		{
		//	ft_putendl("Trying with +1 size");
			sqr_size++;
			ft_init_sol_tab(&tab, sqr_size);
		}
	//	ft_complete_tetris(&list, tab, cursor, sqr_size);
		ft_display_tab(tab);
		ft_free_tab(&tab);
	}
	return (0);
}
