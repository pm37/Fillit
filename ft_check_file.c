/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:15:43 by pimichau          #+#    #+#             */
/*   Updated: 2018/12/04 13:09:57 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_free_tab(char ***tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[0][i])
	{
		free(tab[0][i]);
		tab[0][i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

char	**ft_read_file(int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**tab;
	char	**temp;

	i = 0;
	tab = NULL;
	line = (ft_strnew(0));
	while (ft_get_next_line(fd, &line) && i < 130)
	{
		j = 0;
		temp = tab;
		tab = (char **)malloc(sizeof(*tab) * (i + 2));
		while (j < i)
		{
			tab[j] = temp[j];
			j++;
		}
		tab[i] = ft_strdup(line);
		if (temp)
			free(temp);
		free(line);
		i++;
	}
	if (i)
		tab[i] = NULL;
	i = 0;
	printf("--------->le tableau enregistre<----------\n");
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	printf("------------------>fin<-------------------\n");

	if (i < 130)
	 	return (tab);
	ft_free_tab(&tab);
	return (NULL);
}

int		ft_check_errors(char **tab)
{
	int		i;
	int		sharp;
	int		sides;

	i = -1;
	sharp = 0;
	sides = 0;
	while (tab[++i])
	{
		if (i > 128 || (((i + 1) % 5 != 0) && ft_strlen(tab[i]) != 4) || sharp > 4)
			return (0);
		//printf("1er if passe\n");
		if (((i + 1) % 5 == 0) && (ft_strlen(tab[i]) != 0))
			return (0);
		//printf("2eme if passe\n");
		if ((i + 1) % 5 == 0)
		{
			if (sharp != 4 || sides < 6)
				return (0);
			else
			{
				sharp = 0;
				sides = 0;
			}
		}
		//printf("3eme if passe\n");
		if ((i + 1) % 5 != 0)
			if (!ft_check_errors_2(tab, i, &sharp, &sides))
				return (0);
		if (tab[i + 1] == 0)
		{
			if (sharp != 4 || sides < 6)
				return (0);
		}
		//printf("4eme if passe avec ft2\n");
	}
	if (((i - 4 ) % 5) != 0 || i <= 4)
		return (0);
	return (1);
}

int		ft_check_errors_2(char **tab, int i, int *sharp, int *sides)
{
	int j;
	int	check;

	j = -1;
	check = 0;
	//printf("entree dans ft2\n");
	while (tab[i][++j])
	{
		if ((tab[i][j] != '#' && tab[i][j] != '.') || *sharp > 4)
			return (0);
	//printf("ft2: 1er if passe\n");
		if (tab[i][j] == '#')
		{
			(*sharp)++;
			if (((j > 0) && tab[i][j - 1] == '#'))
				check += 1;
			if ((j < 3) && tab[i][j + 1] == '#')
				check += 1;
			if ((tab[i + 1] && tab[i + 1][0] && tab[i + 1][j] == '#'))
				check += 1;
			if ((i > 0) &&	tab[i - 1][0] && tab[i - 1][j] == '#')
				check += 1;
			if (!check)
				return (0);
		}
		//printf("ft2 -> i : %d, j : %d\n", i, j);
	}
	*sides = *sides + check;
	return (1);
}
