/*
** main.c for main in /home/mathon_j/rendu/PSU_2013_minitalk/client/src
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Mon Mar 10 18:05:06 2014 Jérémy MATHON
** Last update Thu Mar 20 10:50:52 2014 Jérémy MATHON
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<signal.h>
#include	"../include/server.h"

unsigned char  	str[8];

void		my_put_in_dec(unsigned char *str)
{
  int		i;
  int		dec;
  int		cpt;

  i = 0;
  dec = 0;
  cpt = 128;
  while (i < 8)
    {
      dec = ((str[i] - 48) * cpt) + dec;
      cpt = cpt / 2;
      i++;
    }
  if (dec == 0)
    my_putchar('\n');
  else
    my_putchar(dec);
}

void		my_ini(unsigned char *str)
{
  int		i;

  i = 0;
  while (i < 8)
    {
      str[i] = '2';
      i++;
    }
}

void		catch_signal(int sig)
{
  int		i;

  i = 0;
  while (str[i] != '2')
    i++;
  if (sig == SIGUSR1)
    str[i] = '0';
  else if (sig == SIGUSR2)
    str[i] = '1';
  if (i == 7)
    {
      my_put_in_dec(str);
      my_ini(str);
    }
}

int		main(int ac, char **av)
{
  int		i;

  signal(SIGUSR1, catch_signal);
  signal(SIGUSR2, catch_signal);
  my_ini(str);
  i = getpid();
  my_putstr("PID Server : ");
  my_put_nbr(i);
  my_putchar('\n');
  while (42)
    pause();
  return (0);
}
