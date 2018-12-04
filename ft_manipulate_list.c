#include "fillit.h"

int ft_create_list_element(char **tetri, t_tetri_list **list, char id)
{
  int i;
  char **tab;
  t_tetri_list *element;
  t_tetri_list *tmp_list;

  if (tetri)
  {
    // Search a position for the future element
    tmp_list = (*list);
    while (tmp_list && tmp_list->next)
      tmp_list = tmp_list->next;

    // Build of the element
    i = 0;
    if ((element = (t_tetri_list*)malloc(sizeof(t_tetri_list))))
    {
  		if (!(element->tetriminos = (char **)malloc(sizeof(*tab) * (4))))
        return (-1);
      while (i < 4)
      {
        element->tetriminos[i] = ft_strdup(tetri[i]);
        i++;
      }
      element->id = id;
      element->next = NULL;
    }
    else
      return (-1);

    // Add of the element.
    if (tmp_list)
      tmp_list->next = element;
    else
      (*list) = element;
  }
  return (1);
}


int   ft_create_list(char **tab, t_tetri_list **list)
{
  int i;
  char id;

  if (tab)
  {
    i = 0;
    id = 'A';
    while (tab[i - 1])
    {
      ft_create_list_element(&tab[i], list, id);
      i += (tab[i + 5]) ? 5 : 4;
      id++;
    }
  }
  return (0);
}
