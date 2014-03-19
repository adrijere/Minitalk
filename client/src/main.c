/*
** main.c for main in /home/mathon_j/rendu/PSU_2013_minitalk/client/src
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Mon Mar 10 18:05:06 2014 Jérémy MATHON
** Last update Wed Mar 19 21:29:03 2014 Jérémy MATHON
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<signal.h>
#include	"../include/client.h"

void		send_message(int pid_server, char *tmp)
{
  int		i;

  i = 0;
  while (i < 8)
    {
      if (tmp[i] == '0')
	kill(pid_server, SIGUSR1);
      else if (tmp[i] == '1')
	kill(pid_server, SIGUSR2);
      else
	my_putstr("Error : fail to convert to binary.\n");
      i++;
      usleep(1000);
    }
}

char		*check_character(char c)
{
  char		*tab;
  int		cpt;
  int		a;

  tab = my_malloc(sizeof(char) * 8);
  a = 0;
  cpt = 8;
  while (a < 8)
    {
      tab[a] = '2';
      a++;
    }
  while (cpt > 0)
    {
      if (c % 2 == 0)
	tab[cpt - 1] = '0';
      else
	tab[cpt - 1] = '1';
      c = c / 2;
      cpt--;
    }
  return (tab);
}

void		convert_to_bin(int pid_server, char *str)
{
  int		i;
  int		a;
  char		*tmp;

  a = 0;
  i = 0;
  tmp = my_malloc(sizeof(char) * 8);
  while (str[i] != 0)
    {
      tmp = check_character(str[i]);
      send_message(pid_server, tmp);
      i++;
    }
  tmp = check_character(0);
  send_message(pid_server, tmp);
}

int		main(int ac, char **av)
{
  int		i;

  if (ac != 3)
    {
      my_putstr("./client [Pid Server] [\"...\"]\n");
      return (1);
    }
  if (my_getnbr(av[1]) <= 1)
    {
      my_putstr("Le PID server doit être supérieur à 1.\n");
      return (1);
    }
  i = getpid();
  my_putstr("PID Client : ");
  my_put_nbr(i);
  my_putchar('\n');
  convert_to_bin(my_getnbr(av[1]), av[2]);
  return (0);
}
