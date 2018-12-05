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
	ft_putstr("Erreur dans les tetriminos\n");
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**tab;
	t_tetri_list *list;

	fd = 0;
	tab = NULL;
	list = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		tab = ft_check_file(fd);
		if (!ft_check_errors(tab))
			return (ft_usage());
		printf("Les tetriminos sont corrects !");
		ft_create_list(tab, &list);
		i = ft_get_min_square_side(list);
		ft_init_sol_tab(&tab, i);
		while (!ft_complete_tetris(&list, sqr_size))
			ft_init_sol_tab(&tab, ++sqr_size);
		ft_print
	close(fd);
	}
	return (0);
}
