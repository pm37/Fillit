#include "fillit.h"

t_tetri_list   *ft_check_place(t_tetri_list **list, char ***tab, float c)
{
  t_tetri_list  *tmp_list;
  int           is_ok;
  int           i;
  int           j;

  tmp_list = (*list);
  if (tab && tmp_list && tab[0][GET_Y(c)][GET_X(c)])
  {
    while (tmp_list)
    {
      is_ok = 1;
      if (tmp_list->placed == 0)
      {
        i = -1;
        while (tmp_list->tetriminos[++i])
        {
          j = -1;
          while (++j < ft_strlen(tmp_list->tetriminos[i]))
          {
            if (tab[0][GET_Y(c) + i][GET_X(c) + j] != '.' && tmp_list->tetriminos[i][j] != '.')
            {
              is_ok = 0;
              break ;
            }
          }
          if (is_ok == 0)
            break;
        }
        if (is_ok == 1)
          return (tmp_list);
      }
      tmp_list = tmp_list->next;
    }
  }
  return (NULL);
}
