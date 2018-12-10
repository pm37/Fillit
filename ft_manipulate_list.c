#include "fillit.h"

char **ft_rebuild_tetri(char **tetri)
{
  int i;
  int j;
  int width;
  int height;
  int k;
  int min_j;
  char **tab;

  // Determine height and start(Y) of shape and malloc first index of tab
  i = -1;
  height = 0;
  while (++i < 4)
    height += (ft_strchr(tetri[i], '#')) ? 1 : 0;
  if (!(tab = (char**)malloc(sizeof(char*) * (height + 1))))
    return (NULL);
  tab[height] = NULL;
  //ft_putendl("height calculee :");
  //ft_putnbr(height);
  //ft_putendl("");
  // Determinate width and start(X) of shape
  j = -1;
  width = 0;
  while (++j < 4)
  {
    i = -1;
    while (++i< 4)
    {
      if (tetri[i][j] == '#')
      {
        width++;
        break;
      }
    }
  }
  //ft_putendl("width calculee :");
  //ft_putnbr(width);
  //ft_putendl("");
  i = 0;
  while (!(ft_strchr(tetri[i], '#')))
    i++;
  min_j = 3;
  k = 0;
  //ft_putendl("i et k init valent :");
  //ft_putnbr(k);
  //ft_putendl("");
  //ft_putendl("debut suspect");
  while (tetri[k + i] && (k + i) < 4)
  {
    j = 0;
    while(tetri[k + i][j] == '.')
      j++;
    if (min_j > j)
    {
    //  ft_putendl("j vaut:");
      //ft_putnbr(j);
      //ft_putendl("");
      min_j = j;
    }
    k++;
  }
  //ft_putendl("fin suspecte");
  //ft_putendl("min_j vaut:");
  //ft_putnbr(min_j);
  //ft_putendl("");
  // If a line contain a # copy it of width chars
  j = 0;
  while (tetri[i] && ft_strchr(tetri[i], '#'))
  {
    tab[j] = ft_strsub(tetri[i], min_j, width);
    i++;
    j++;
  }
  //ft_putendl("completion du tetriminos effectuee");
  //ft_putendl("");
  return (tab);
}

int ft_create_list_element(char **tetri, t_tetri_list **list, char id)
{
  t_tetri_list *element;
  t_tetri_list *tmp_list;

  if (tetri)
  {
    /*if (list)
      tmp_list = (*list);
    else
      tmp_list = NULL;*/
    tmp_list = (*list);
    //ft_putendl("tmp_list init");
    while (tmp_list && tmp_list->next)
      tmp_list = tmp_list->next;
    if ((element = (t_tetri_list*)malloc(sizeof(t_tetri_list))))
    {
      //ft_putendl("avant ft_rebuild");
  		if (!(element->tetriminos = ft_rebuild_tetri(tetri)))
        return (0);
      //ft_putendl("apres ft_rebuild");
      //ft_display_tab(element->tetriminos);
      //ft_putendl("apres display");
      element->id = id;
      element->placed = 0;
      element->next = NULL;
    }
    else
      return (0);
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
  int j;
  char id;

  if (tab)
  {
    i = 0;
    id = 'A';
    while (tab[i])
    {
      //ft_putendl("entree dans while create list");
      ft_create_list_element(&(tab[i]), list, id++);
      //ft_putendl("element cree");
      j = (tab[i + 4] == 0 ? 4 : 5);
      //ft_putnbr(j);
      //ft_putendl("");
      i += j;
    }
    //ft_putendl("fin du while create list");
  }
  return (0);
}
