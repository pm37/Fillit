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

int   ft_get_min_sqr_size(t_tetri_list **list)
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

void  ft_put_tetriminos(t_tetri_list **list, char id, char **tab, float coor)
{
  t_tetri_list  *element;
  int i;
  int j;

  element = *list;
  while (element->id)
    element = element->next;
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

/* fonction non terminee :
int   ft_complete_tetris(t_tetri_list **list, char **tab, char id,
float coor)
{
  t_tetri_list  *element;

  element = *list;
  if (ft_is_tetris_complete)
    return (1);
  while (!ft_check_space_availability(element, tab, coor))
    element=element->next;
  if (element)
  {
    ft_put_tetriminos(element, coor);
    return (ft_complete_tetris(list, tab, coor + 0,1));
  }
  else if (ft_complete_tetris(list, tab, ))
}*/
