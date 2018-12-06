/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_tetris.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pimichau <pimichau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:31:07 by pimichau          #+#    #+#             */
/*   Updated: 2018/12/04 16:31:11 by pimichau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void  ft_init_sol_tab(char ***tab, int sqr_size)
{
  int i;
  int j;
  //free memory
  ft_free_tab(tab);
  //allocate memory
  *tab = (char **)malloc(sizeof(**tab) * (sqr_size + 1));
  //complete tab with '.'
  i = 0;
  while (i < sqr_size)
  {
    tab[0][i] = (char *)malloc(sizeof(char) * (sqr_size + 1));
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
}

int   ft_get_min_sqr_size(t_tetri_list *list)
{
  int area;
  int sqr_size;

  area = 0;
  sqr_size = 0;
  if (!list)
    return (0);
  while (list)
  {
    list = list->next;
    area += 4:
  }
  while (area)
  {
      if (sqr_size = ft_sqrt(area))
        return (sqr_size);
    area++;
  }
  return(0);
}

void  ft_put_tetriminos(t_tetri_list *element, char **tab, float c)
{
  int i;
  int j;

  element = list;
  i = 0;
  while (element->tetriminos[i])
  {
    j = 0;
    while (element->tetriminos[i][j])
    {
      if (element->tetriminos[i][j] == '#')
        tab[GET_Y(coor) + i][GET_X(coor) + j] = element->id;
      j++;
    }
    i++;
  }
}

float ft_get_next_free_coor(char **tab, int x, int y)
{
  int i;
  int j;

  j = y;
  while (tab[j])
  {
    i = ((j == y) ? (x + 1) : 0)
    while (tab[j][i])
    {
      if (tab[j][i] == '.')
        return (SET_X(i) + SET_Y(j))
      i++;
    }
    j++;
  }
  return (0);
}

int   ft_complete_tetris(t_tetri_list **list, char **tab, float c)
{
  t_tetri_list  *element;

  if (!c && !available_tetri)
    return (1);
  if (element = ft_check_place(list, &tab, &c))
    ft_put_tetriminos(element, tab, c);
  ft_complete_tetris(list, tab, ft_get_next_coor(tab, c));
  else if (c = ft_get_next_coor(tab, c))
}
