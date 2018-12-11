#include "fillit.h"

int   *ft_check_place(t_tetri_list *element, char **tab, float c)
{
  int           is_ok;
  int           i;
  int           j;

  if (element && tab)
  {
    is_ok = 1;
    if (element->placed == 0)
    {
      i = 0;
      while (element->tetriminos[i])
      {
        j = 0;
        while (tab[GET_Y(c) + i] && (size_t)j < ft_strlen(element->tetriminos[i]))
        {
          if (!(tab[GET_Y(c) + i][GET_X(c) + j]) ||
              (tab[GET_Y(c) + i][GET_X(c) + j] != '.' && element->tetriminos[i][j] != '.'))
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
