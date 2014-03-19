/*
** my_put_nbr.c for my_put_nbr in /home/mathon_j/rendu/Piscine-C-lib/my
**
** Made by Jeremy Mathon
** Login   <mathon_j@epitech.net>
**
** Started on  Wed Oct  9 13:50:48 2013 Jeremy Mathon
** Last update Mon Mar 10 18:28:43 2014 Jérémy MATHON
*/

#include	"../include/server.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb != 0 && nb > 10)
    my_put_nbr(nb/10);
  my_putchar(nb % 10 + 48);
  return (nb);
}
