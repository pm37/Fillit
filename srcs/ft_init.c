/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:39:58 by pimichau          #+#    #+#             */
/*   Updated: 2018/12/12 17:50:33 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_init_sol_tab(char ***tab, int sqr_size)
{
	int	i;
	int	j;

	ft_free_tab(tab);
	if (!(*tab = (char **)malloc(sizeof(**tab) * (sqr_size + 1))))
		exit(EXIT_SUCCESS);
	i = 0;
	while (i < sqr_size)
	{
		if (!(tab[0][i] = (char *)malloc(sizeof(char) * (sqr_size + 1))))
			exit(EXIT_SUCCESS);
		j = 0;
		while (j < sqr_size)
		{
			tab[0][i][j] = '.';
			j++;
		}
		tab[0][i][j] = '\0';
		i++;
	}
	tab[0][i] = NULL;
	return (1);
}

int		ft_get_min_sqr_size(t_tetri_list *list)
{
	int	area;
	int	sqr_size;

	area = 0;
	sqr_size = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		area += 4;
	}
	while (area)
	{
		if ((sqr_size = ft_sqrt(area)))
			return (sqr_size);
		area++;
	}
	return (0);
}

void	ft_display_tab(char **tab)
{
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}

void	ft_free_list(t_tetri_list **list)
{
	t_tetri_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		ft_free_tab(&(*list)->tetri);
		free(*list);
		*list = temp;
	}
	free(*list);
	*list = NULL;
}
