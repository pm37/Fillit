#include "fillit.h"

int   *ft_check_place(t_tetri_list **list, char **tab, char id, float c)
{
  int           is_ok;
  t_tetri_list  *tmp_lst;
  int           i;
  int           j;

  if (tab && list && id)
  {
    tmp_lst = (*list);
    while (tmp_lst && tmp_lst->id != id)
      tmp_list = tmp_list->next;
    is_ok = 1;
    if (tmp_list->placed == 0)
    {
      i = 0;
      while (tmp_list->tetriminos[i])
      {
        j = 0;
        while (tab[GET_Y(c) + i] && (size_t)j < ft_strlen(tmp_list->tetriminos[i]))
        {
          if (!(tab[GET_Y(c) + i][GET_X(c) + j]) ||
              (tab[GET_Y(c) + i][GET_X(c) + j] != '.' && tmp_list->tetriminos[i][j] != '.'))
          {
            is_ok = 0;
            break ;
          }
          j++;
        }
        if (is_ok == 0 || !tab[GET_Y(c) + i])
        {
          is_ok = 0;
          break;
        }
        i++;
      }
      if (is_ok == 1 && tab[GET_Y(c) + i - 1])
        return (1);
    }
  }
  return (0);
}
