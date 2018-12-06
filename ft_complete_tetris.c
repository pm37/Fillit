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
    *tab[i] = (char *)malloc(sizeof(char) * (sqr_size + 1));
    j = 0;
    while (j < sqr_size)
    {
      *tab[i][j] = '.';
      j++;
    }
    *tab[i][j] = '\0';
    i++;
  }
*tab[i] = NULL;
}

int   ft_get_min_sqr_size(t_tetri_list **list)
{
  int sqr_size;

  sqr_size = 0;
  if (!list)
    return (0);
  while (list)
  {
    list = list->next;
    sqr_size++:
  }
  return(sqr_size);
}

void  ft_put_tetriminos(t_tetri_list *element, char **tab, float coor)
{
  int i;
  int j;

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

int   ft_complete_tetris(t_tetri_list **list, char **tab, char id,
float coor)
{
  t_tetri_list  *element;

  if (elem = ft_check)
  {
    ft_put_tetriminos(element, tab, coor);
    if (coor + element->width1)
      return (ft_complete_tetris(list, tab, coor + element->width1));
    else
      return (ft_complete_tetris(list, tab, coo))
  }
  else if (ft_complete_tetris(list, tab, ))
}
