/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:15:43 by pimichau          #+#    #+#             */
/*   Updated: 2018/12/17 16:00:34 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_tab(char ***tab)
{
	int	i;

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

char		**ft_read_file(int fd, int i, int j, char **tab)
{
	char	*line;
	char	**temp;

	line = NULL;
	while (ft_get_next_line(fd, &line) && i < 131 && line != NULL)
	{
		j = -1;
		if (!(temp = (char **)malloc(sizeof(*tab) * (i + 2))))
			return (NULL);
		while (++j < i)
			if (!(temp[j] = ft_strdup(tab[j])))
				return (NULL);
		if (!(temp[i] = ft_strdup(line)))
			return (NULL);
		temp[i + 1] = NULL;
		if (tab)
			ft_free_tab(&tab);
		tab = temp;
		free(line);
		i++;
	}
	if (i == 130)
		ft_free_tab(&tab);
	return ((i == 130) ? NULL : tab);
}

static int	ft_check_errors_2(char **tab, int i, int *sharp, int *sides)
{
	int j_ck[2];

	j_ck[0] = -1;
	j_ck[1] = 0;
	while (tab[i][++(j_ck[0])])
	{
		if ((tab[i][j_ck[0]] != '#' && tab[i][j_ck[0]] != '.') || *sharp > 4)
			return (0);
		if (tab[i][j_ck[0]] == '#')
		{
			(*sharp)++;
			if (((j_ck[0] > 0) && tab[i][j_ck[0] - 1] == '#'))
				j_ck[1] += 1;
			if ((j_ck[0] < 3) && tab[i][j_ck[0] + 1] == '#')
				j_ck[1] += 1;
			if ((tab[i + 1] && tab[i + 1][0] && tab[i + 1][j_ck[0]] == '#'))
				j_ck[1] += 1;
			if ((i > 0) && tab[i - 1][0] && tab[i - 1][j_ck[0]] == '#')
				j_ck[1] += 1;
			if (!j_ck[1])
				return (0);
		}
	}
	*sides = *sides + j_ck[1];
	return (1);
}

int			ft_check_errors(char **tab, int i, int s, int sides)
{
	while (tab[++i])
	{
		if (i > 128 || (((i + 1) % 5 != 0) && ft_strlen(tab[i]) != 4) || s > 4)
			return (0);
		if (((i + 1) % 5 == 0) && (ft_strlen(tab[i]) != 0))
			return (0);
		if ((i + 1) % 5 == 0)
		{
			if (s != 4 || sides < 6)
				return (0);
			s = 0;
			sides = 0;
		}
		if ((i + 1) % 5 != 0)
			if (!ft_check_errors_2(tab, i, &s, &sides))
				return (0);
		if (tab[i + 1] == 0)
			if (s != 4 || sides < 6)
				return (0);
	}
	if (((i - 4) % 5) != 0 || i < 4)
		return (0);
	return (1);
}
